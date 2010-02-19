#ifndef AUDIO_H_
#define AUDIO_H_

#include <GeneralDefinitions.h>
class RawFileClass;

class Audio {
public:

	static bool __fastcall ReadWAVFile(RawFileClass *file, void *AudioSample, int *result)
		{ JMP_STD(0x408610); }

	static signed int __fastcall FindSampleIndex(void *AudioIDXData, const char *Name)
		{ JMP_STD(0x4015C0); }
};

#endif
