
#include "Arduino.h"
#include "MCP41010.h"

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */

MCP41010::MCP41010(int Data,int Clk,int Cs) { // Constructor
  SDATA = Data;
  SCLK  = Clk;
  CS    = Cs;  
}
  
void MCP41010::init() {	
  pinMode(SCLK,  OUTPUT);
  pinMode(SDATA, OUTPUT);
  pinMode(CS,    OUTPUT);
  
  digitalWrite(SCLK,  HIGH);
  digitalWrite(CS,    HIGH);

  Mute(POT_ALL);
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
 
void MCP41010::SetVolume(byte vol,byte pot) {
  byte Cmd; 
  SendWord(CMD_WRITE | pot ,vol);
}
	
// ----------------------------------------------------------------------------

void MCP41010::Mute(int pot) {
  SetVolume(0,pot);
}	

/* ------------------------------------------------------------------------- */
/*                  Base functions for registers acces                       */
/* ------------------------------------------------------------------------- */

void MCP41010::SendWord (byte Cmd, byte Value) {        
  unsigned int Data;
  Data= ( Cmd << 8 ) | Value;
  
  digitalWrite(SCLK,  HIGH);          // for safety
  digitalWrite(CS,    LOW);           // Start New Word Loading
    
  for (byte i = 0; i < 16; i++) {
    if (Data & 0x8000) digitalWrite(SDATA, HIGH);
    else               digitalWrite(SDATA, LOW);
    digitalWrite(SCLK, LOW);          // Clock on falling edge, so Set to Low
    Data = Data << 1;                 // next bit      
    digitalWrite(SCLK, HIGH);         // Clock to High level
  }
  digitalWrite(CS,     HIGH);         // End of Datas
}

/* ------------------------------------------------------------------------- */
/*                             --- E N D ---                                 */
/* ------------------------------------------------------------------------- */
