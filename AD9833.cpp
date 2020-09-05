
#include "Arduino.h"
#include "AD9833.h"

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */

AD9833::AD9833(int Data,int Clk,int Fsync, double Refclock = 25000000.0 ) { // Constructor
  SDATA     = Data;
  SCLK      = Clk;
  FSYNC     = Fsync; 
  REFCLOCK  = Refclock;
}
  
void AD9833::init() {	
  pinMode(SCLK,  OUTPUT);
  pinMode(SDATA, OUTPUT);
  pinMode(FSYNC, OUTPUT);
  
  digitalWrite(SCLK,  HIGH);
  digitalWrite(FSYNC, HIGH);
  
  Reset();
}

// ----------------------------------------------------------------------------

void AD9833::Reset() {
  delay(10);
  SendWord (RESET_ON);
  delay(100);
}

void AD9833::ClearReg() {
   CrtlReg=0;
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
        
void AD9833::SetFrequency(unsigned long Freq,byte no) {
  unsigned long Reg;
  unsigned int Msb;
  unsigned int Lsb;
  Reg = Freq * ( 0x10000000 / REFCLOCK ) + 0.5;  // calculate FreqReg
  Lsb= Reg        & 0x3FFF;                      // 14 low bits to Lsb
  Msb=(Reg >> 14 )& 0x3FFF;                      // 14 high bits to Msb
  
  if ( no == 0 ) {
    F0Lsb = Lsb | FREQ0;   
    F0Msb = Msb | FREQ0;
  } else {
    F1Lsb = Lsb | FREQ1;   
    F1Msb = Msb | FREQ1; 
  }
}

// ----------------------------------------------------------------------------

void AD9833::SetPhase(unsigned long Phase,byte no) {
  unsigned long Reg;
  Reg = ( 4096.0 * Phase ) / 360.0  + 0.5;  // calculate PhaseReg Phase in °                    
  if ( no == 0 ) {
    F0Phase = Reg & 0x0FFF | PHASE0;   
  } else {
    F1Phase = Reg & 0x0FFF | PHASE1;   
  }  
}

// ----------------------------------------------------------------------------

void AD9833::SetSine() {
  CrtlReg = ( CrtlReg & FORMMASK ) | SINE;
  SendWord(CrtlReg);
}

// ----------------------------------------------------------------------------

void AD9833::SetSquare(){
  CrtlReg = ( CrtlReg & FORMMASK ) | SQUARE;
  SendWord(CrtlReg);
}

// ----------------------------------------------------------------------------

void AD9833::SetTriangle(){
  CrtlReg = ( CrtlReg & FORMMASK ) | TRIANGLE;
  SendWord(CrtlReg);  
}

// ----------------------------------------------------------------------------

void AD9833::Apply() {
  CrtlReg  = CrtlReg |  B28_ON | RESET_ON;

  SendWord (CrtlReg);
  SendWord (F0Lsb);
  SendWord (F0Msb);
  SendWord (F0Phase);

  SendWord (F1Lsb);
  SendWord (F1Msb);
  SendWord (F1Phase);
  
  CrtlReg=CrtlReg & RESET_OFF ;
  SendWord (CrtlReg);
}
    
/* ------------------------------------------------------------------------- */
/*                  Base functions for registers acces                       */
/* ------------------------------------------------------------------------- */

void AD9833::SendWord (unsigned int Data) {         
  digitalWrite(SCLK,  HIGH);          // for safety
  digitalWrite(FSYNC, LOW);           // Start New Word Loading
    
  for (byte i = 0; i < 16; i++) {
    if (Data & 0x8000) digitalWrite(SDATA, HIGH);
    else               digitalWrite(SDATA, LOW);
    digitalWrite(SCLK, LOW);          // Clock on falling edge, so Set to Low
    Data = Data << 1;                 // next bit      
    digitalWrite(SCLK, HIGH);         // Clock to High level
  }
  digitalWrite(FSYNC, HIGH);          // End of Datas
}

/* ------------------------------------------------------------------------- */
/*                             --- E N D ---                                 */
/* ------------------------------------------------------------------------- */
