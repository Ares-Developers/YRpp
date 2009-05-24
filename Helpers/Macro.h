#ifndef DCODER_H
#define DCODER_H

#include <Syringe.h>

// In this file: Alternatives to CTRL + H...

#include <hash_map>
// macros DCoder uses and pd dislikes :)

#define GET(clsname, var, reg) \
	clsname var = (clsname )R->get_ ## reg ();

// it's really not a good idea to GET_STACK(not_a_pointer)
// no, really
#define GET_STACK(clsname, var, offset) \
	clsname var = *((clsname *)(R->lea_ ## StackVar(offset)));

#define GET_BASE(clsname, var, offset) \
	clsname var = *((clsname *)(R->lea_ ## BaseVar(offset)));

#define RET_UNLESS(expr) \
	if(!(expr)) { return 0; }
#define RETZ_UNLESS(expr) \
	if(!(expr)) { return ; }


// buffer length for tags containing a list such as AnimToInfantry=
#define BUFLEN 2048


// absflags shorthand
#define ABS_IS_OBJECT(var) \
	((var->AbstractFlags & ABSFLAGS_ISOBJECT) != 0)

#define ABS_IS_TECHNO(var) \
	((var->AbstractFlags & ABSFLAGS_ISTECHNO) != 0)

#define ABS_IS_FOOT(var) \
	((var->AbstractFlags & ABSFLAGS_ISFOOT) != 0)

// this is an Ares macro, durr, don't use it in YR++, will be moved someday
#define IF_STR(section, key) \
	if(INI->ReadString(section, key, Ares::readDefval, Ares::readBuffer, Ares::readLength))
#define FOR_STRTOK \
	for(char *cur = strtok(Ares::readBuffer, Ares::readDelims); \
		cur; cur = strtok(NULL, Ares::readDelims))

#define PARSE_VECTOR(ini_section, ini_key, var, objtype) \
IF_STR(ini_section, #ini_key) { \
	DynamicVectorClass<objtype *>* vec = var; vec->Clear(); \
	FOR_STRTOK{ \
		objtype *idx = objtype::Find(cur); if(idx) { vec->AddItem(idx); } \
	} \
}

#define PARSE_VECTOR_N(ini_section, obj, ini_key, objtype) \
IF_STR(ini_section, #ini_key) { \
	DynamicVectorClass<objtype *>* vec = obj->get_ ## ini_key(); vec->Clear(); \
	FOR_STRTOK{ \
		objtype *idx = objtype::Find(cur); \
		if(idx) { vec->AddItem(idx); } \
	} \
}

#define PARSE_VECTOR_BIT(ini_section, obj, ini_key, objtype, obj_key) \
IF_STR(ini_section, #ini_key) { \
	DWORD buf = 0; \
	FOR_STRTOK{ \
		int idx = objtype::FindIndex(cur); if(idx > -1) { buf |= (1 << idx); } \
	} \
	obj->set_ ## obj_key (buf); \
}

#define PARSE_VECTOR_INT(ini_section, ini_key, obj) \
IF_STR(ini_section, #ini_key) { \
	DynamicVectorClass<int>* vec = obj->get_ ## ini_key(); vec->Clear(); \
	FOR_STRTOK{ \
		int idx = atoi(cur); vec->AddItem(idx); \
	} \
}

// parse ini faster! harder! stronger!

#define PARSE_BUF() \
	char buffer[256];

/*
 * warning: all further funcs depend on
 * const char *section = <section_name_to_read_from>
 * being declared. Since you are not supposed to read from a gajillion sections at once, deal with it.
 */

// WARNING MK II: These funcs are ::Find, not ::FindOrAllocate, make variants if you wish

// find items
#define PARSE_VAR_OBJ(key, var, cls) \
	if(pINI->ReadString(section, key, "", buffer, 256) > 0) \
		var = cls::Find(buffer);

#define PARSE_WH(key, var) \
	PARSE_VAR_OBJ(key, var, WarheadTypeClass);

#define PARSE_WEAP(key, var) \
	PARSE_VAR_OBJ(key, var, WeaponTypeClass);

#define PARSE_TECHNO(key, var) \
	PARSE_VAR_OBJ(key, var, TechnoTypeClass);

#define PARSE_AIRCRAFT(key, var) \
	PARSE_VAR_OBJ(key, var, AircraftTypeClass);

#define PARSE_VEHICLE(key, var) \
	PARSE_VAR_OBJ(key, var, UnitTypeClass);

#define PARSE_INFANTRY(key, var) \
	PARSE_VAR_OBJ(key, var, InfantryTypeClass);

#define PARSE_BUILDING(key, var) \
	PARSE_VAR_OBJ(key, var, BuildingTypeClass);

#define PARSE_ANIM(key, var) \
	PARSE_VAR_OBJ(key, var, AnimTypeClass);

#define PARSE_SW(key, var) \
	PARSE_VAR_OBJ(key, var, SuperWeaponTypeClass);

#define PARSE_TASKFORCE(key, var) \
	PARSE_VAR_OBJ(key, var, TaskForceClass);

#define PARSE_SCRIPT(key, var) \
	PARSE_VAR_OBJ(key, var, ScriptTypeClass);

#define PARSE_TEAM(key, var) \
	PARSE_VAR_OBJ(key, var, TeamTypeClass);

// find indices
#define PARSE_VAR_IDX(key, var, cls) \
	if(pINI->ReadString(section, key, "", buffer, 256) > 0) \
		var = cls::FindIndex(buffer);

#define PARSE_SND(key, var) \
	PARSE_VAR_IDX(key, var, VocClass);

#define PARSE_EVA(key, var) \
	PARSE_VAR_IDX(key, var, VoxClass);

#define PARSE_WH_IDX(key, var) \
	PARSE_VAR_IDX(key, var, WarheadTypeClass);

#define PARSE_WEAP_IDX(key, var) \
	PARSE_VAR_IDX(key, var, WeaponTypeClass);

#define PARSE_TECHNO_IDX(key, var) \
	PARSE_VAR_IDX(key, var, TechnoTypeClass);

#define PARSE_AIRCRAFT_IDX(key, var) \
	PARSE_VAR_IDX(key, var, AircraftTypeClass);

#define PARSE_VEHICLE_IDX(key, var) \
	PARSE_VAR_IDX(key, var, UnitTypeClass);

#define PARSE_INFANTRY_IDX(key, var) \
	PARSE_VAR_IDX(key, var, InfantryTypeClass);

#define PARSE_BUILDING_IDX(key, var) \
	PARSE_VAR_IDX(key, var, BuildingTypeClass);

#define PARSE_ANIM_IDX(key, var) \
	PARSE_VAR_IDX(key, var, AnimTypeClass);

#define PARSE_SW_IDX(key, var) \
	PARSE_VAR_IDX(key, var, SuperWeaponTypeClass);

#define PARSE_TASKFORCE_IDX(key, var) \
	PARSE_VAR_IDX(key, var, TaskForceClass);

#define PARSE_SCRIPT_IDX(key, var) \
	PARSE_VAR_IDX(key, var, ScriptTypeClass);

#define PARSE_TEAM_IDX(key, var) \
	PARSE_VAR_IDX(key, var, TeamTypeClass);


// read colors
#define PARSE_COLOR(key, var, buf) \
		buf = var; \
		pINI->ReadColor(&buf, section, key, &var); \
		var = buf;

// swizzle shorthand
#define SWIZZLE(var) \
	SwizzleManagerClass::SwizzleManager()->Swizzle((void **)&var);

// debug logging
#ifdef DEBUGBUILD
#define DEBUGLOG(...) \
	Debug::Log(__VA_ARGS__)
#else
#define DEBUGLOG(...) \
	
#endif


// float cmp
#define CLOSE_ENOUGH(x, y) \
	(abs(x - y) < 0.001)

#endif
