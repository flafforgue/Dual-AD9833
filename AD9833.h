/* ------------------------------------------------------------------------- */
/*  Analog Device - AD9833 - low power, programmable waveform generator      */
/* ------------------------------------------------------------------------- */
/*                                                                           */
/* programmable waveform generator capable of producing sine, triangular,    */
/*   and square wave outputs                                                 */
/*                                                                           */
/* https://www.analog.com/media/en/technical-documentation/data-sheets/ad9833.pdf */
/*                                                                           */
/* ------------------------------------------------------------------------- */

#ifndef AD9833_H

#define AD9833_H
#include "Arduino.h"

// #define REFCLOCK  25000000.0  // as float for frequency calculations 
                         
#define FREQ0     0x4000 // 010. ....  .... ....
#define PHASE0    0xC000 // 110. ....  .... ....
#define FREQ1     0x8000 // 100. ....  .... ....
#define PHASE1    0xE000 // 111. ....  .... ....

#define SINE      0x0000 // .... ....  ..0. 0.0.
#define TRIANGLE  0x0002 // .... ....  ..0. 0.1.
#define SQUARE    0x0028 // .... ....  ..1. 1.0.
#define SQUARE2   0x0020 // .... ....  ..1. 0.0.
#define FORMMASK  0x0000 // 1111 1111  11.1 .1.1

#define POWER_ON  0xFF3F // .... ....  .... 00..
#define POWER_OFF 0x00C0 // .... ....  .... 11..
  
#define B28_ON    0x2000 // .... ..1.  .... .... 
#define B28_OFF   0xDFFF // .... ..0.  .... ....
  
#define RESET_ON  0x0100 // .... ...1  .... ....
#define RESET_OFF 0xFEFF // .... ...0  .... ....
  
#define PHASE_ON  0x0400 // .... .1..  .... .... 
#define PHASE_OFF 0xFBFF // .... .0..  .... ....
  
#define FSEL0     0xF7FF // .... 0...  .... ....
#define FSEL1     0x0800 // .... 1...  .... .... 

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */

class AD9833 {
  public:
//	  AD9833(int Data,int Clk,int Fsync);
    AD9833(int Data,int Clk,int Fsync, double Refclock = 25000000.0 );

	  void init();
    void Reset();
    void ClearReg();

    void SetFrequency(unsigned long Freq,byte no);
    void SetPhase(unsigned long Phase,byte no);
	 
	  void SetSine();
	  void SetSquare();
	  void SetTriangle();

    void Apply();
    
    void SendWord (unsigned int Data);
	
  private:
     int    SDATA;
     int    SCLK;
     int    FSYNC;
     double REFCLOCK;

     unsigned int CrtlReg  = B28_ON | RESET_ON;
     unsigned int F0Msb    = FREQ0;
     unsigned int F0Lsb    = FREQ0;
     unsigned int F0Phase  = PHASE0;
     unsigned int F1Msb    = FREQ1;
     unsigned int F1Lsb    = FREQ1;
     unsigned int F1Phase  = PHASE1;	 
};

#endif // of #ifndef AD9833_H
