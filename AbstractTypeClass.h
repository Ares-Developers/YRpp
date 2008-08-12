/*
	AbstractTypes are abstract template objects initialized by INI files
*/
#ifndef ABSTRACTTYPE_H
#define ABSTRACTTYPE_H

#include <AbstractClass.h>

//forward declarations
class CCINIClass;

//Macro for the static Array of every AbstractTypeClass!
#define ABSTRACTTYPE_ARRAY(class_name)	public:\
	static DynamicVectorClass<class_name*>* Array;\
	static class_name* Find(const char* pID)\
	{\
		for(int i=0;i<Array->get_Count();i++)\
			if(!_strcmpi((*Array)[i]->get_ID(), pID))\
				return (*Array)[i];\
		return NULL;\
	}\
	static class_name* FindOrAllocate(const char* pID)\
	{\
		class_name* pRet = Find(pID);\
		if(pRet)\
			return pRet;\
		else\
			return new class_name(pID);\
	}\
	static int FindIndex(const char* pID)\
	{\
		for(int i=0;i<Array->get_Count();i++)\
			if(!_strcmpi((*Array)[i]->get_ID(), pID))\
				return i;\
		return -1;\
	}
//---

class AbstractTypeClass : public AbstractClass
{
public:
	//Static
	static DynamicVectorClass<AbstractTypeClass*>* Array;

	//Destructor
	virtual ~AbstractTypeClass()
		{ THISCALL(0x4109C0); }

	//AbstractClass
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x410BE0); }

	//AbstractTypeClass
	virtual void LoadTheaterSpecificArt(eTheater th_type) { }

	virtual bool LoadFromINI(CCINIClass* pINI)
		{ PUSH_VAR32(pINI); THISCALL(0x410A60); }

	virtual bool SaveToINI(CCINIClass* pINI)
		{ PUSH_VAR32(pINI); THISCALL(0x410B90); }

	//Constructor
	AbstractTypeClass(const char* id):AbstractClass(false)
									{
									PUSH_VAR32(id);
									THISCALL(0x410800);
									}

protected:
	AbstractTypeClass():AbstractClass(false){};
	AbstractTypeClass(bool X):AbstractClass(X){};	//trick to disable base class construction!

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY_STRING(ID,0x18);
	PROTECTED_PROPERTY(BYTE,zero_3C);
	PROPERTY_STRING(UINameLabel,0x20);
	PROPERTY(wchar_t*,UIName);
	PROPERTY_STRING(Name,0x31);
};

#endif
