/*
	Sides
*/

#ifndef SIDE_H
#define SIDE_H

#include <AbstractTypeClass.h>
#include <ArrayClasses.h>
#include <HouseTypeClass.h>
#include <HouseClass.h>

class SideClass : public AbstractTypeClass
{
public:
	enum {AbsID = abs_Side};
	enum eSides {GDI, NOD, THIRDSIDE, CIVILIAN, MUTANT, NONE_ERROR};

	//Array
	ABSTRACTTYPE_ARRAY(SideClass);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~SideClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	static eSides DetermineSide(int SideIndex) {
		const char* SideStrings[] = {"GDI","Nod","ThirdSide","Civilian","Mutant"};

		for(short i = 0; i <= 4; ++i) {
			if(SideClass::FindIndex(SideStrings[i]) == SideIndex) {
				return i;
			}
		}
	}

	/*
	<DC|work> HouseTypeClass * SpecialHouse = HouseTypes::Array->GetItem(SideClass::Find("Mutant")->HouseTypes->Items[$someIndex]);
	<DC|work> then you need to go over HouseClass::Array and find all houses whose Type == SpecialHouse

	*/

	template <class T> class cSideList {
		public:
			DynamicVectorClass< T > GDI; // British,French,Germans,Americans,Alliance
			DynamicVectorClass< T > Nod; // Russians,Africans,Confederation,Arabs
			DynamicVectorClass< T > ThirdSide; // YuriCountry
			DynamicVectorClass< T > Civilian; // Neutral
			DynamicVectorClass< T > Mutant; // Special
			void Add(T Addee) {
				switch((Addee->WhatAmI() == abs_House) ? Addee->Type->Side : Addee->Side) {
					case eSides::GDI:
						this->GDI.AddItem(Addee);
						break;
					case NOD:
						Nod.AddItem(Addee);
						break;
					case THIRDSIDE:
						ThirdSide.AddItem(Addee);
						break;
					case CIVILIAN:
						Civilian.AddItem(Addee);
						break;
					case MUTANT:
						Mutant.AddItem(Addee);
						break;
					case NONE_ERROR:
						// this should never be reached
						// if there is a Debug::Error(), this would be a good place for it
						break;
				}
			}
	};

	static cSideList< HouseTypeClass* > HouseTypes;
	static cSideList< HouseClass* > Houses;

	//Constructor
	SideClass(const char* pID) : AbstractTypeClass(false)
		{ JMP_THIS(0x6A4550); }

protected:
	SideClass() : AbstractTypeClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY_STRUCT(TypeList<int>, HouseTypes);	//indices!

};

#endif
