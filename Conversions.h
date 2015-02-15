#pragma once

#include <Helpers/Macro.h>
#include <YRPP.h>
#include <WarheadTypeClass.h>

// converters
class Conversions
{
public:
	static double Str2Armor(const char *buf, WarheadFlags *whFlags) {
		if(!buf) { return 0.0; }

		bool ForceFire = true;
		bool Retaliate = true;
		bool PassiveAcquire = true;

		if(strchr(buf, '%')) {

			if(strlen(buf) == 2) {
				switch(*buf) {
					case '0':
						ForceFire = false;
					case '1':
						Retaliate = false;
					case '2':
						PassiveAcquire = false;
						break;
				}
			}
			whFlags->ForceFire = ForceFire;
			whFlags->Retaliate = Retaliate;
			whFlags->PassiveAcquire = PassiveAcquire;
			return atoi(buf) * 0.01;
		} else {
			double vs = atof(buf);
			if(LESS_EQUAL(vs, 0.02)) {
				whFlags->PassiveAcquire = false;
			}
			if(LESS_EQUAL(vs, 0.01)) {
				whFlags->Retaliate = false;
			}
			if(LESS_EQUAL(vs, 0.00)) {
				whFlags->ForceFire = false;
			}
			return vs;
		}
	}

	// OMG OPTIMIZED:
	// http://graphics.stanford.edu/~seander/bithacks.html#IntegerLog
	static unsigned int Int2Highest(DWORD v) {
		unsigned int r; // result of log2(v) will go here
		unsigned int shift;

		r =     static_cast<DWORD>(v > 0xFFFF) << 4; v >>= r;
		shift = static_cast<DWORD>(v > 0xFF  ) << 3; v >>= shift; r |= shift;
		shift = static_cast<DWORD>(v > 0xF   ) << 2; v >>= shift; r |= shift;
		shift = static_cast<DWORD>(v > 0x3   ) << 1; v >>= shift; r |= shift;
		                                                          r |= (v >> 1);
		return r;
	}

	static unsigned int Int2Highest(int v) {
		return Int2Highest(static_cast<DWORD>(v));
	}

};
