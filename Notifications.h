#pragma once

#include <ArrayClasses.h>

class AbstractClass;

// encapsulates a bunch of vectors that are used for announcing invalid pointers.
// if an AbstractClass is contained in an list it will be notified through
// PointerExpired whenever an object of that type expires.
class PointerExpiredNotification {
public:
	static PointerExpiredNotification &NotifyInvalidObject; // Object class hierarchy
	static PointerExpiredNotification &NotifyInvalidType; // AbstractType class hierarchy
	static PointerExpiredNotification &NotifyInvalidAnim; // AnimClass
	static PointerExpiredNotification &NotifyInvalidHouse; // HouseClass
	static PointerExpiredNotification &NotifyInvalidTag; // TagClass
	static PointerExpiredNotification &NotifyInvalidTrigger; // TriggerClass
	static PointerExpiredNotification &NotifyInvalidFactory; // FactoryClass
	static PointerExpiredNotification &NotifyInvalidWaypoint; // WaypointClass
	static PointerExpiredNotification &NotifyInvalidTeam; // TeamClass
	static PointerExpiredNotification &NotifyInvalidNeuron; // NeuronClass
	static PointerExpiredNotification &NotifyInvalidActionOrEvent; // ActionClass and EventClass

	inline bool Add(AbstractClass* object) {
		// add only if doesn't exist
		int index = this->Array.FindItemIndex(object);
		if(index < 0) {
			return this->Array.AddItem(object);
		}
		return false;
	}

	inline bool Remove(AbstractClass* object) {
		int index = this->Array.FindItemIndex(object);
		if(index > -1) {
			return this->Array.RemoveItem(index);
		}
		return false;
	}

	DynamicVectorClass<AbstractClass*> Array;
};
