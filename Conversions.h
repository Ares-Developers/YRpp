#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include <Helpers/Macro.h>
#include <YRPP.h>

// converters
class Conversions
{
public:
	static double Str2Armor(char *buf, DWORD *specialFX) {
		if(!buf) { return 0.0; }
		if(strchr(buf, '%')) {
			bool specialed = false;
			if(strlen(buf) == 2) {
				switch(*buf) {
					case '0':
						*specialFX &= ~verses_ForceFire;
					case '1':
						*specialFX &= ~verses_Retaliate;
					case '2':
						*specialFX &= ~verses_PassiveAcquire;
						specialed = true;
						break;
				}
			}
			if(!specialed) {
				*specialFX |= verses_ForceFire;
				*specialFX |= verses_Retaliate;
				*specialFX |= verses_PassiveAcquire;
			}
			return atoi(buf) * 0.01;
		} else {
			double vs = atof(buf);
			bool specialed = false;
			if(CLOSE_ENOUGH(vs, 0.02)) {
				*specialFX &= ~verses_PassiveAcquire;
				specialed = true;
			}
			if(CLOSE_ENOUGH(vs, 0.01)) {
				*specialFX &= ~verses_Retaliate;
			}
			if(CLOSE_ENOUGH(vs, 0.00)) {
				*specialFX &= ~verses_ForceFire;
			}
			if(!specialed) {
				*specialFX |= verses_ForceFire;
				*specialFX |= verses_Retaliate;
				*specialFX |= verses_PassiveAcquire;
			}
			return vs;
		}
	}

	// OMG OPTIMIZED:
	// http://graphics.stanford.edu/~seander/bithacks.html#IntegerLog
	static int Int2Highest(DWORD v) {
		register unsigned int r; // result of log2(v) will go here
		register unsigned int shift;

		r =     (v > 0xFFFF) << 4; v >>= r;
		shift = (v > 0xFF  ) << 3; v >>= shift; r |= shift;
		shift = (v > 0xF   ) << 2; v >>= shift; r |= shift;
		shift = (v > 0x3   ) << 1; v >>= shift; r |= shift;
		                                        r |= (v >> 1);

		return r;
	}

};

#endif
