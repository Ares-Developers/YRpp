#ifndef UNSORTED_H
#define UNSORTED_H

class ObjectClass;

namespace Unsorted
{
	static int &CurrentFrame     = *(int *)0xA8ED84;

	static byte &ArmageddonMode  = *(byte *)0xA8ED6B;

	static DynamicVectorClass<ObjectClass *>** vec_ObjectsInLayers = (DynamicVectorClass<ObjectClass *>**)0x8A0360;

struct ColorPacker
{
	int _R_SHL;
	int _R_SHR;
	int _B_SHL;
	int _B_SHR;
	int _G_SHL;
	int _G_SHR;
};

	static ColorPacker *ColorPackData = (ColorPacker *)0x8A0DD0;

	static CellStruct *CellSpreadTable = (CellStruct *)0xABD490;

	static int &CurrentSWType = *(int *)0x8809A0;

	static const int except_txt_length = 0xFFFF;
	static char *except_txt_content = (char *)0x8A3A08;

/*
 * This thing is ridiculous
 * all xxTypeClass::Create functions use it:

  InfantryTypeClass *foo = something;
  ++SomeMutex;
  InfantryClass *obj = something->CreateObject();
  --SomeMutex;

  ++SomeMutex;
  obj->Put(blah);
  --SomeMutex;
  
  AI base node generation uses it:
  int level = SomeMutex;
  SomeMutex = 0;
  House->GenerateAIBuildList();
  SomeMutex = level;
  
  Building destruction uses it:
  if(!SomeMutex) {
  	Building->ShutdownSensorArray();
  	Building->ShutdownDisguiseSensor();
  }
  
  Building placement uses it:
  if(!SomeMutex) {
  	UnitTypeClass *freebie = Building->Type->FreeUnit;
  	if(freebie) {
  		freebie->CreateObject(blah);
  	}
  }
  
  Building state animations use it:
  if(SomeMutex) {
  	// foreach attached anim
  	// update anim state (normal | damaged | garrisoned) if necessary, play anim
  }
  
  building selling uses it:
  if(blah) {
  	++SomeMutex;
  	this->Type->UndeploysInto->CreateAtMapCoords(blah);
  	--SomeMutex;
  }

  Robot Control Centers use it:
  if ( !SomeMutex ) {
  	VoxClass::PlayFromName("EVA_RobotTanksOffline/BackOnline", -1, -1);
  }

  and so on...
 */
	static int &SomeMutex = *(int *)0xA8E7AC;
}

#endif
