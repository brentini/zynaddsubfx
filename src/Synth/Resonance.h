/*
  ZynAddSubFX - a software synthesizer
 
  Resonance.h - Resonance 
  Copyright (C) 2002-2003 Nasca Octavian Paul
  Author: Nasca Octavian Paul

  This program is free software; you can redistribute it and/or modify
  it under the terms of version 2 of the GNU General Public License 
  as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License (version 2) for more details.

  You should have received a copy of the GNU General Public License (version 2)
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/
#ifndef RESONANCE_H
#define RESONANCE_H

#include "../globals.h"
#include "../Misc/Util.h"

#define N_RES_POINTS 256

class Resonance{
    public:
	Resonance();
	~Resonance();
	void setpoint(int n,unsigned char p);
	void applyres(int n,REALTYPE *fftdata,REALTYPE freq);
	void smooth();
	void interpolatepeaks(int type);
	void randomize(int type);
	void saveloadbuf(Buffer *buf);
	REALTYPE getfreqpos(REALTYPE freq);
	REALTYPE getfreqx(REALTYPE x);
	REALTYPE getcenterfreq();
	REALTYPE getoctavesfreq();
	void sendcontroller(MidiControllers ctl,REALTYPE par);

    //parameters
    unsigned char Penabled;			//if the ressonance is enabled	
    unsigned char Prespoints[N_RES_POINTS];	//how many points define the resonance function
    unsigned char PmaxdB;			//how many dB the signal may be amplified
    unsigned char Pcenterfreq,Poctavesfreq;     //the center frequency of the res. func., and the number of octaves
    unsigned char Pgain;			//how the signal is amplified 
    unsigned char Pprotectthefundamental;       //the fundamental (1-st harmonic) is not damped, even it resonance function is low
    //controllers
    REALTYPE ctlcenter;//center frequency(relative)
    REALTYPE ctlbw;//bandwidth(relative)
    
    private:
};

#endif