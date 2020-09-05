
/* ------------------------------------------------------------------------- */
/*                           AD 9833 & MCP 41010                             */
/* ------------------------------------------------------------------------- */

#define CH1_CS        5  // for MCP41010
#define CH1_FSYNC    17  // for AD9833
#define CH1_SCLK      7  // SPI Clock
#define CH1_SDATA     6  // SPI Data

#define CH2_CS        4  // for MCP41010
#define CH2_FSYNC    10  // for AD9833
#define CH2_SCLK      7  // SPI Clock
#define CH2_SDATA     6  // SPI Data

#include "AD9833.h"  
AD9833 Chn1 = AD9833(CH1_SDATA,CH1_SCLK,CH1_FSYNC, 25000017.5 ); // Data,Clk, Fsync ( Corrected frequency )
AD9833 Chn2 = AD9833(CH2_SDATA,CH2_SCLK,CH2_FSYNC, 25000040.0 );

#include "MCP41010.h"  
MCP41010 Vol1 = MCP41010(CH1_SDATA,CH1_SCLK,CH1_CS); // Data,Clk, Fsync
MCP41010 Vol2 = MCP41010(CH2_SDATA,CH2_SCLK,CH2_CS); // Data,Clk, Fsync

unsigned int AD9833_CrtlReg  = B28_ON | RESET_ON | POWER_OFF;
unsigned int AD9833_F0Msb    = FREQ0;
unsigned int AD9833_F0Lsb    = FREQ0;
unsigned int AD9833_F0Phase  = PHASE0;
unsigned int AD9833_F1Msb    = FREQ1;
unsigned int AD9833_F1Lsb    = FREQ1;
unsigned int AD9833_F1Phase  = PHASE1;

/* ------------------------------------------------------------------------- */
/*                              Encodeur et Boutons                          */
/* ------------------------------------------------------------------------- */

#define encoder0PinA  2 
#define encoder0PinB  3 

#define BtnEncoder   14 // A0
#define BtnCh1       15 // A1
#define BtnCh2       16 // A2 

int posencoder = 0;
int encodermov  = 0;
unsigned long ntime = 0;
unsigned long otime = 0;

void doEncoder() {
  ntime=millis();
  if ( ntime-otime > 60 ) {
    if (digitalRead(encoder0PinA) == digitalRead(encoder0PinB)) {
      encodermov =-1;
      posencoder--;
    } else {
      encodermov =+1;
      posencoder++;
    }
    otime=ntime;
  }
}

// ----------------------------------------------------------------------------

#define BTN_None         0
#define BTN_Ch1          1
#define BTN_Ch1_Long     2
#define BTN_Ch2          3
#define BTN_Ch2_Long     4
#define BTN_Encoder      5
#define BTN_EncoderL     6
#define BTN_LONGDELAY  800

byte keydown  = BTN_None;
byte key      = BTN_None;
unsigned long   BTNTime;

void readBtnState() {
  unsigned long NTime; 
  NTime=millis();
  
  if ( keydown == BTN_None ) { // no key waiting 
    if ( digitalRead (BtnEncoder)==LOW ) { BTNTime=NTime;  keydown=BTN_Encoder;  }
    if ( digitalRead (BtnCh1    )==LOW ) { BTNTime=NTime;  keydown=BTN_Ch1;      }
    if ( digitalRead (BtnCh2    )==LOW ) { BTNTime=NTime;  keydown=BTN_Ch2;      }    
  } else {                     // key allready down
    if ( NTime - BTNTime > 10 ) { // avoid rebounds
        switch (keydown) {
           case BTN_Encoder:
                 if ( digitalRead (BtnEncoder)==HIGH ) { // keypress on release ;)   
                   if ( NTime - BTNTime >= BTN_LONGDELAY )  key = BTN_EncoderL;                
                   else                                     key = BTN_Encoder;
                   keydown=BTN_None;
                 }
                 break;
           case BTN_Ch1:
                 if ( digitalRead (BtnCh1)==HIGH ) { // keypress on release ;)   
                   if ( NTime - BTNTime >= BTN_LONGDELAY )  key = BTN_Ch1_Long;                
                   else                                     key = BTN_Ch1;
                   keydown=BTN_None;
                 }
                 break;
           case BTN_Ch2:
                 if ( digitalRead (BtnCh2)==HIGH ) { // keypress on release ;)   
                   if ( NTime - BTNTime >= BTN_LONGDELAY )  key = BTN_Ch2_Long;                
                   else                                     key = BTN_Ch2;
                   keydown=BTN_None;
                 }
                 break;           
        }       
    }
  }
}

// ----------------------------------------------------------------------------

bool keypressed() {
  return ( key != BTN_None );
}

byte readkey() {
  byte tmp = key;
  key=BTN_None;
  return( tmp);
}

/* ------------------------------------------------------------------------- */
/*                                  KMR 1.8                                  */
/* ------------------------------------------------------------------------- */

#define TFT_RST       0  // Not connected
#define TFT_DC        8
#define TFT_CS        9

#define TFT_CLK      13
#define TFT_DATA     11

#include <Adafruit_ST7735.h> 
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

#define BLACK   0x0000
#define GREY    0x632C
#define LGREY   0xB614
#define WHITE   0xFFFF

#define NAVY    0x000F
#define BLUE    0x001F
#define TEAL    0x03EF
#define CYAN    0x07FF

#define CYAN    0x07FF
#define MAROON  0x7800
#define RED     0xF800

#define DGREEN  0x03E0
#define GREEN   0x07E0

#define YELLOW  0xFFE0
#define ORANGE  0xFC00
#define PURPLE  0x780F
#define LPURPLE 0xC018

#define MAGENTA 0xF81F

/* ------------------------------------------------------------------------- */
/*                   Draw a button at Place                                  */
/* ------------------------------------------------------------------------- */

void drawBtn(int x, int y, bool on, bool sel, int no) {
  int coul;
  
  if ( on ) { coul = YELLOW; }  else { coul = GREY; } 
  tft.fillRect(x+1, y+1, 25, 11, coul);

  if ( sel ) { coul = RED; } else { coul = BLUE; }  
//  tft.drawRect(x,y,  27, 13, coul);
  tft.drawFastVLine(x   ,y+ 1 , 11, coul);
  tft.drawFastVLine(x+26,y+ 1 , 11, coul);
  tft.drawFastHLine(x+1 ,y    , 25, coul);
  tft.drawFastHLine(x+1 ,y+12 , 25, coul);
  
  tft.drawPixel(x+ 1,y+ 1,coul);
  tft.drawPixel(x+ 1,y+11,coul);
  tft.drawPixel(x+25,y+ 1,coul);
  tft.drawPixel(x+25,y+11,coul);

  tft.setTextColor(coul);  
  tft.setTextSize(1);   
         
  switch (no) {
  case 1: 
          tft.setCursor(x+5, y+3);
          tft.print("Ch1");    
          break;
  case 2:
          tft.setCursor(x+5, y+3);
          tft.print("Ch2");    
          break;
  case 3: // Sinus        
          tft.drawLine(x+ 3,y+ 7, x+ 3,y+ 5 ,coul);  
          tft.drawLine(x+ 3,y+ 5, x+ 6,y+ 2 ,coul);  
          tft.drawLine(x+ 6,y+ 2, x+10,y+ 2 ,coul);  
          tft.drawLine(x+10,y+ 2, x+13,y+ 5 ,coul);  
          tft.drawLine(x+13,y+ 5, x+13,y+ 7 ,coul);  
          tft.drawLine(x+13,y+ 7, x+16,y+10 ,coul);  
          tft.drawLine(x+16,y+10, x+20,y+10 ,coul);  
          tft.drawLine(x+20,y+10, x+23,y+ 7 ,coul);  
  case 4: // triangle
          tft.drawLine(x+ 3,y+ 6, x+8, y+ 1 ,coul);
          tft.drawLine(x+ 8,y+ 1, x+18,y+11, coul);
          tft.drawLine(x+18,y+11, x+23,y+ 6, coul);   
          break;
  case 5: // carre
          tft.drawLine(x+ 3,y+ 7, x+ 3,y+ 2 ,coul);  
          tft.drawLine(x+ 3,y+ 2, x+13,y+ 2 ,coul);  
          tft.drawLine(x+13,y+ 2, x+13,y+10 ,coul);  
          tft.drawLine(x+13,y+10, x+23,y+10 ,coul);  
          tft.drawLine(x+23,y+10, x+23,y+ 6 ,coul);           
          break;
  default:
          break;
  }
}

/* --------------------------------------------------------------- */
/*                Display Fredcency Value                          */
/* --------------------------------------------------------------- */

unsigned char Digit7 = 0;
unsigned char Digit6 = 0;
unsigned char Digit5 = 0;
unsigned char Digit4 = 0;
unsigned char Digit3 = 0;
unsigned char Digit2 = 0;
unsigned char Digit1 = 0;
unsigned char Digit0 = 0;

void DisplayFrequency(int x,int y, unsigned long Freq ,int dg=0 ) {
  int Cbase;
  
  Digit0 = Freq % 10; Freq = Freq / 10;
  Digit1 = Freq % 10; Freq = Freq / 10;
  Digit2 = Freq % 10; Freq = Freq / 10;
  Digit3 = Freq % 10; Freq = Freq / 10;
  Digit4 = Freq % 10; Freq = Freq / 10;
  Digit5 = Freq % 10; Freq = Freq / 10;
  Digit6 = Freq % 10; Freq = Freq / 10;  
  Digit7 = Freq % 10; Freq = Freq / 10;

//  tft.fillRect(x+17, y, 110, 15, CChanel); // erase Value
  if ( dg==0 )        Cbase=YELLOW;
  else if ( dg==-1 )  Cbase=RED;
       else           Cbase=GREEN;

  tft.setCursor(x, y);
          
  if ( dg== 7 ) tft.setTextColor(RED  ,BLACK);
  else          tft.setTextColor(Cbase,BLACK); 
  tft.print(Digit7); 
  tft.print(Digit6);
  tft.print(".");
          
  if ( dg== 6 ) tft.setTextColor(RED  ,BLACK);
  else          tft.setTextColor(Cbase,BLACK); 
  tft.print(Digit5);
          
  if ( dg== 5 ) tft.setTextColor(RED  ,BLACK);
  else          tft.setTextColor(Cbase,BLACK); 
  tft.print(Digit4);
          
  if ( dg== 4 ) tft.setTextColor(RED  ,BLACK);
  else          tft.setTextColor(Cbase,BLACK); 
  tft.print(Digit3);
  tft.print(".");
          
  if ( dg== 3 ) tft.setTextColor(RED  ,BLACK);
  else          tft.setTextColor(Cbase,BLACK); 
  tft.print(Digit2);
          
  if ( dg== 2 ) tft.setTextColor(RED  ,BLACK);
  else          tft.setTextColor(Cbase,BLACK); 
  tft.print(Digit1);
          
  if ( dg== 1 ) tft.setTextColor(RED  ,BLACK);
  else          tft.setTextColor(Cbase,BLACK); 
  tft.print(Digit0);
}


/* ------------------------------------------------------------------------- */
/*                                   Leds                                    */
/* ------------------------------------------------------------------------- */

#define LedCh1      18  // A4
#define LedCh2      19  // A5

/* ------------------------------------------------------------------------- */
/*                              Initialisation                               */ 
/* ------------------------------------------------------------------------- */

void setup() {
 
  // encoder  
  // ----------
  pinMode(encoder0PinA, INPUT_PULLUP); 
  pinMode(encoder0PinB, INPUT_PULLUP); 
//  attachInterrupt(digitalPinToInterrupt(encoder0PinB), doEncoder, CHANGE); 
  attachInterrupt(digitalPinToInterrupt(encoder0PinA), doEncoder, CHANGE); 
  
  // Boutons 
  // ----------
  pinMode(BtnEncoder  , INPUT_PULLUP);
  pinMode(BtnCh1      , INPUT_PULLUP);
  pinMode(BtnCh2      , INPUT_PULLUP);

  // Leds 
  // ----------
  pinMode(LedCh1, OUTPUT); 
  pinMode(LedCh2, OUTPUT); 

  //    tft
  // -----------
//  SPI.begin();
//  SPI.setDataMode(SPI_MODE0);    
//  delay(50); 
  
  tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab
  tft.setRotation(1);
  tft.setTextWrap(false);
  tft.fillScreen(BLACK);  
  tft.setTextColor(YELLOW);
  tft.setTextSize(2);   

  //  AD 9833 
  // -----------
  Chn1.init();
  Chn2.init();
  
  //  MCP41010
  // -----------
  Vol1.init();
  Vol2.init();  
  
  Vol1.SetVolume(0x00,POT_ALL);
  Vol2.SetVolume(0x00,POT_ALL);
}

/* --------------------------------------------------------------- */
/*                                                                 */
/* --------------------------------------------------------------- */

unsigned int      CSel = GREEN;

int  Chn_Sel = 1;
unsigned long int Frequ0 [2] = {      440 ,      880 };
bool              On     [2] = {        0 ,        0 };
unsigned char     Form   [2] = {        0 ,        0 };  // 0 = Sin      , 1 = Triangle , 2 = square
unsigned int      Level  [2] = {       80 ,       80 };  // tension * 100 

int ActSel = 1;

char buffer9 [10];

void DisplayOneChanel(int Chn , int Sel) {
  int yy=0;
  if (Chn>0) yy=64;
  
  drawBtn(  3, yy+3, On  [Chn]   , Sel==1 ,1+Chn);
  drawBtn( 42, yy+3, Form[Chn]==0, Sel==2 ,3);
  drawBtn( 72, yy+3, Form[Chn]==1, Sel==3 ,4);
  drawBtn(102, yy+3, Form[Chn]==2, Sel==4 ,5);

  tft.setTextSize(2);
//  if ( Sel==5 )  tft.setTextColor(RED   ,BLACK);
//  else           tft.setTextColor(YELLOW,BLACK);
//  DisplayFrequency(10 , yy+21, Frequ0[Chn] );
  if ( Sel==5 )  DisplayFrequency(10 , yy+21, Frequ0[Chn] , -1);
  else           DisplayFrequency(10 , yy+21, Frequ0[Chn] );

// 
  dtostrf( Level[Chn]*0.01 , 4, 2, buffer9);
  if ( Sel==6 )  tft.setTextColor(RED   ,BLACK);
  else           tft.setTextColor(YELLOW,BLACK);
  tft.setCursor( 40, yy+ 39); tft.print(buffer9);

  tft.setTextColor(YELLOW,BLACK);
  tft.setCursor(104, yy+ 39); tft.print("V");

  tft.setTextSize(1);
  tft.setCursor(116, yy+ 45); tft.print("peak");
    
  tft.setTextColor(MAGENTA);
  tft.setCursor(134,yy+ 26);  tft.print("Hz");
}

/* ------------------------------------------------------------------------- */
/*                             Boucle Principale                             */ 
/* ------------------------------------------------------------------------- */

void RefreshScreen() {
//  tft.fillScreen(BLACK);    
//  tft.setTextColor(YELLOW,BLACK);

  if ( Chn_Sel== 1 ) {
    tft.drawRect(0,64,160,64,BLACK);
    tft.drawRect(1,65,158,62,BLACK);        
    tft.drawRect(0,0,160,64,RED);
    tft.drawRect(1,1,158,62,RED);      
    DisplayOneChanel(0 , ActSel);
    DisplayOneChanel(1 , 0);
  } else {
    tft.drawRect(0,0,160,64,BLACK);
    tft.drawRect(1,1,158,62,BLACK);      
    tft.drawRect(0,64,160,64,RED);
    tft.drawRect(1,65,158,62,RED);   
    DisplayOneChanel(0 , 0);
    DisplayOneChanel(1 , ActSel);
  }
}

void ChangeFrequency(int Chn ) {
  int yy=0;
  long int Increment = 10;
  int digit = 2;
  bool doedit = true;
  byte k;
  long int f0;
  
  if (Chn>0) yy=64; 
  tft.setTextColor(GREEN   ,BLACK);
  tft.setTextSize(2);
   
  DisplayFrequency(10 , yy+21, Frequ0[Chn] ,digit);
  while (doedit) {
    readBtnState();
    k=readkey();
    if ( k == BTN_EncoderL ) doedit=false;
    if ( k == BTN_Encoder  ) {
      Increment = Increment *10; digit++;
      if ( Increment > 1000000 ) {
        Increment=1;
        digit=1;
      }
    }
    
    if (encodermov != 0 ) {
      f0  = Frequ0[Chn] + Increment * encodermov;
      if ( ( f0 > 0 ) & ( f0 <= 12500000 ) ) Frequ0[Chn]=f0;
      encodermov=0;
    }
    DisplayFrequency(10 , yy+21, Frequ0[Chn] , digit); 
  }
}


void ChangeLevel(int Chn ) {
  int yy=0;
  bool doedit = true;
  byte k;
  long int a0;

  if (Chn>0) yy=64; 
  tft.setTextColor(GREEN   ,BLACK);
  tft.setTextSize(2);
    
  dtostrf( Level[Chn]*0.01 , 4, 2, buffer9);
  tft.setCursor( 40, yy+ 39); tft.print(buffer9);
  
  while (doedit) {
    readBtnState();
    k=readkey();
    if ( k == BTN_Encoder ) doedit=false;

    if (encodermov != 0 ) {
      if ( Level[Chn] + encodermov <= 30 ) {
        a0  = Level[Chn] + 1 * encodermov;
      } else{
        a0  = Level[Chn] + 5 * encodermov;
      }
      if ( ( a0 >= 0 ) & ( a0 <= 200 ) ) Level[Chn]=a0;
      encodermov=0;
    }
    dtostrf( Level[Chn]*0.01 , 4, 2, buffer9);
    tft.setCursor( 40, yy+ 39); tft.print(buffer9);    
  } 
}

void SelectFunc() {
  switch ( ActSel ) {  
      case 1 : On[Chn_Sel-1] = not(On[Chn_Sel-1]);
               break;
      case 2 : Form[Chn_Sel-1]=0;
               break;
      case 3 : Form[Chn_Sel-1]=1;
               break;
      case 4 : Form[Chn_Sel-1]=2;
               break;
      case 5 : ChangeFrequency(Chn_Sel-1);
               break;
      case 6 : ChangeLevel(Chn_Sel-1);
               break;
  }
}


/* ------------------------------------------------------------------------- */
/*
/* ------------------------------------------------------------------------- */


void RefreshAD9833() {

  if ( On[0] ) {
    Vol1.SetVolume(Level[0],POT_ALL);
  } else {
    Vol1.Mute(POT_ALL);
  }
  
  Chn1.ClearReg();
  Chn1.SetFrequency(Frequ0[0],0);
  Chn1.SetPhase(0,0);
  switch( Form[0] ) {
    case 0 : Chn1.SetSine();
             break;
    case 1 : Chn1.SetTriangle();
             break;
    case 2 : Chn1.SetSquare();
             break;
  }
  Chn1.Apply();

  if ( On[1] ) {
    Vol2.SetVolume(Level[1],POT_ALL);
  } else {
    Vol2.Mute(POT_ALL);
  }
  
  Chn2.ClearReg();
  Chn2.SetFrequency(Frequ0[1],0);
  Chn2.SetPhase(0,0);
  switch( Form[1] ) {
    case 0 : Chn2.SetSine();
             break;
    case 1 : Chn2.SetTriangle();
             break;
    case 2 : Chn2.SetSquare();
             break;
  }
  Chn2.Apply();  
}

// ----------------------------------------------------------------------------

bool change = true;

void loop() {
  readBtnState();
  if ( keypressed() ) {
    change=true;
    switch ( readkey() ) {
      case BTN_Ch1     : Chn_Sel=1;
                         break;
      case BTN_Ch1_Long: On[0] = not(On[0]);
                         break;
      case BTN_Ch2     : Chn_Sel=2;
                         break;
      case BTN_Ch2_Long: On[1] = not(On[1]);
                         break;
      case BTN_Encoder : SelectFunc();
                         break;
      case BTN_EncoderL: 
                         break;
    }
  }

  if (encodermov!= 0 ) {
    change=true;
    ActSel+=encodermov;
    encodermov=0;
    if ( ActSel>6 ) ActSel=1;
    if ( ActSel<1 ) ActSel=6;
  }

  if ( change ) {
    RefreshScreen();
    digitalWrite( LedCh1, On[0]);
    digitalWrite( LedCh2, On[1]);
    RefreshAD9833();
    change = false;
  }
}
