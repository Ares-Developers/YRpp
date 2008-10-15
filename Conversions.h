#ifndef CONVERSIONS_H
#define CONVERSIONS_H

// converters
class Conversions
{
public:
	static double Str2Armor(char *buf)
	{
		if(!buf) { return 0.0; }
		if(strchr(buf, '%'))
		{
			return atoi(buf) * 0.01;
		}
		else
		{
			return atof(buf);
		}
	}
};

#endif
