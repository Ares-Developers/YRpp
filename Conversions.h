#ifndef CONVERSIONS_H
#define CONVERSIONS_H

// converters
class Conversions
{
public:
	static double Str2Armor(char *buf) {
		if(!buf) { return 0.0; }
		if(strchr(buf, '%')) {
			return atoi(buf) * 0.01;
		} else {
			return atof(buf);
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
