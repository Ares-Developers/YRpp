#ifndef UNSORTED_H
#define UNSORTED_H

namespace Unsorted
{
	static int &CurrentFrame     = *(int *)0xA8ED84;

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
