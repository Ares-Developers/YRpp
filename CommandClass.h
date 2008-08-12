/*
	UI Commands
*/

#ifndef COMMAND_H
#define COMMAND_H

#include <GeneralDefinitions.h>
#include <ArrayClasses.h>

class CommandClass
{
public:
	//STATIC
	static DynamicVectorClass<CommandClass*>* Array;

	//Destructor
	virtual ~CommandClass(){}

	//CommandClass
	virtual const char*	GetName() = 0;
	virtual const wchar_t*	GetUIName() = 0;
	virtual const wchar_t*	GetUICategory() = 0;
	virtual const wchar_t*	GetUIDescription() = 0;

	virtual bool vt_entry_14(DWORD dwUnk)
		{ return false; }

	virtual bool vt_entry_18(DWORD dwUnk)
		{ return (bool)(((~dwUnk) >> 11) & 1); }

	virtual bool vt_entry_1C(DWORD dwUnk)
		{ return false; }

	virtual void Execute(DWORD dwUnk) = 0;

	//Constructor
	CommandClass() { }
};

#endif
