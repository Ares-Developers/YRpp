#ifndef FUNDAMENTALS_H
#define FUNDAMENTALS_H

/*
These globals are so important and fundamental that no other files should be
included for them to be available.
*/
namespace Unsorted
{
	static const int& CurrentFrame = *reinterpret_cast<int*>(0xA8ED84);
}

#endif
