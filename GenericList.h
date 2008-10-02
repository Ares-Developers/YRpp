//General linked list class

#ifndef GENLIST_H
#define GENLIST_H

#include <YRPPCore.h>

template <typename T> class GenericNode
{
public:
	//Destructor
	virtual ~GenericNode()
		{ PUSH_IMM(0); THISCALL(0x40E390); }

	//Constructor
	GenericNode()
		{ Next=NULL; Previous=NULL; }

	//Properties
	T*	Next;
	T*	Previous;
};

template <typename T> class GenericList
{
public:
	//Destructor
	virtual ~GenericList()
		{ PUSH_IMM(0); THISCALL(0x40E3E0); }

	//Constructor
	GenericList()
		{ THISCALL(0x52ACE0); }

	//Properties
	GenericNode<T>	First;
	GenericNode<T>	Last;
};

#endif
