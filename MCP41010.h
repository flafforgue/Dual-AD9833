/* ------------------------------------------------------------------------- */
/*  Microchip - MCP41010 - low power, programmable waveform generator        */
/* ------------------------------------------------------------------------- */
/*                                                                           */
/* devices  are  256-position,   digital   potentiometers                    */
/*                                                                           */
/*                                                                           */
/* http://ww1.microchip.com/downloads/en/devicedoc/11195c.pdf                */
/*                                                                           */
/* ------------------------------------------------------------------------- */

#ifndef MCP41010_H

#define MCP41010_H
#include "Arduino.h"

 
#define CMD_NONE  0x00 // ..00 ....
#define CMD_WRITE 0x10 // ..01 ....
#define CMD_SHDW  0x20 // ..10 ....
 
#define POT_NONE  0x00 // .... ..00
#define POT_0     0x01 // .... ..01
#define POT_1     0x02 // .... ..10
#define POT_ALL   0x03 // .... ..11

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */

class MCP41010 {
  public:
	  MCP41010(int Data,int Clk,int Cs);

	  void init();
      void SetVolume(byte vol,byte pot);   
	  void Mute(int pot);
	
      void SendWord (byte Cmd, byte Value);
	
  private:
      int SDATA;
      int SCLK;
      int CS;
	 
};

#endif // of #ifndef MCP41010_H
