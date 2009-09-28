#ifndef SPECIAL_STRUCTURES_H
#define SPECIAL_STRUCTURES_H

// this file contains a few structures representing function arguments on the stack (normally all except `this`)

// i.e. this struct can be used to read the args to ObjectClass::ReceiveDamage
struct args_ReceiveDamage {
	int *Damage;
	int TypeSource;
	WarheadTypeClass *WH;
	TechnoClass *target;
	bool ignoreDefenses;
	int arg10;
	HouseClass *SourceHouse;
};

#endif
