/*
	UI Commands
*/

/*
NOTE:
	This should NOT become a victim of Operation: The Cleansing, since we actually
	derive classes from it!

	-pd
*/

#ifndef COMMAND_H
#define COMMAND_H

#include <GeneralDefinitions.h>
#include <ArrayClasses.h>

class NOVTABLE CommandClass
{
public:
	// static
	static DynamicVectorClass<CommandClass*>* Array;

	//CommandClass
	virtual ~CommandClass() = default;
	virtual const char* GetName() const = 0;
	virtual const wchar_t* GetUIName() const = 0;
	virtual const wchar_t* GetUICategory() const = 0;
	virtual const wchar_t* GetUIDescription() const = 0;

	virtual bool vt_entry_14(DWORD dwUnk) const
		{ return false; }

	virtual bool vt_entry_18(DWORD dwUnk) const
		{ return (((~dwUnk) >> 11) & 1) != 0; }

	virtual bool vt_entry_1C(DWORD dwUnk) const
		{ return false; }

	virtual void Execute(DWORD dwUnk) const = 0;
};

#endif
