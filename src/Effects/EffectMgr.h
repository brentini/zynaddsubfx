/*
  ZynAddSubFX - a software synthesizer
 
  EffectMgr.h - Effect manager, an interface betwen the program and effects
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

#ifndef EFFECTMGR_H
#define EFFECTMGR_H

#include <pthread.h>

#include "Effect.h"
#include "Reverb.h"
#include "Echo.h"
#include "Chorus.h"
#include "Phaser.h"
#include "Alienwah.h"
#include "Distorsion.h"
#include "EQ.h"
#include "../Misc/Buffer.h"


class EffectMgr{
    public:
	EffectMgr(int insertion_,pthread_mutex_t *mutex_);
	~EffectMgr();
	void saveloadbuf(Buffer *buf);
	void out(REALTYPE *smpsl,REALTYPE *smpsr);

	//get the output(to speakers) volume of the systemeffect
	REALTYPE sysefxgetvolume();

	void cleanup();//cleanup the effec5
	
	void changeeffect(int nefx_);
	int geteffect();
        void changepreset(unsigned char npreset);
        void changepreset_nolock(unsigned char npreset);
	unsigned char getpreset();
	void seteffectpar(int npar,unsigned char value);
	void seteffectpar_nolock(int npar,unsigned char value);//sets the effect par without thread lock
	unsigned char geteffectpar(int npar);
        int insertion;//1 if the effect is connected as insertion effect
	REALTYPE *efxoutl,*efxoutr;

	//used by UI
	REALTYPE getEQfreqresponse(REALTYPE freq);
	
    private:
	int nefx;
	Effect *efx;
	pthread_mutex_t *mutex;
    
};

#endif


