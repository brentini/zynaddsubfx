CXX=gcc

#You can set the on what OS is compiling (Linux/Windows)
OS_PORT=LINUX
#OS_PORT=WINDOWS

#The version of the FFTW which is used (2 or 3)
#FFTW_VERSION=2
FFTW_VERSION=3

#Assembler FLOAT to INT conversions
ASM_F2I=YES
#ASM_F2I=NO

# L I N U X   C O N F I G U R A T I O N
#Next line sets the midi input. It can be "ALSA", "OSS" or "NONE".
LINUX_MIDIIN=ALSA
#LINUX_MIDIIN=OSS
#LINUX_MIDIIN=NONE

#Next line sets the audio output (OSS/JACK/PA)
LINUX_AUDIOOUT=OSS
#LINUX_AUDIOOUT=NONE
#LINUX_AUDIOOUT=JACK
#for PortAudio (PA)
#LINUX_AUDIOOUT=PA


# W I N D O W S   C O N F I G U R A T I O N

#Next line sets the midi input
#WINDOWS_MIDIIN=NONE
WINDOWS_MIDIIN=WIN

#Next line sets the audio output
#WINDOWS_AUDIOOUT=NONE
WINDOWS_AUDIOOUT=PA

#Next line sets if the synth is compiled for VST (as .dll file)
#If this setting is "YES", MIDI in and AUDIOOUT are set automatically to VST
WINDOWS_VST=NO
#WINDOWS_VST=YES

#configuration end 

ifeq ($(OS_PORT),LINUX)
 MIDIIN=$(LINUX_MIDIIN)
 AUDIOOUT=$(LINUX_AUDIOOUT)
 WINDOWS_VST=NO
else
 MIDIIN=$(WINDOWS_MIDIIN)
 AUDIOOUT=$(WINDOWS_AUDIOOUT)
    ifeq ($(WINDOWS_VST),YES)
     MIDIIN=VST
     AUDIOOUT=VST
    endif
endif
