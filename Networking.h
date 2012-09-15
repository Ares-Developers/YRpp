#ifndef YRPP_NETWORKING_H
#define YRPP_NETWORKING_H

#include <NetworkEvents.h>

class Networking {
public:
	static DWORD &CurrentFrameCRC;

	// this points to CRCs from 0x100 last frames
	static DWORD *LatestFramesCRC;

public:
	static int &LastEventIndex;
	static int &NextPacketIndex;
	static NetworkEvent *QueuedEvents; // these are really 128 length arrays
	static int *QueuedEventTimestamps; // these are really 128 length arrays

	// custom helper for Ares logics
	static bool AddEvent(NetworkEvent *event) {
		event->Timestamp = Unsorted::CurrentFrame;
		if(LastEventIndex >= 128) {
			return false;
		}
		memcpy(&QueuedEvents[NextPacketIndex], event, sizeof(*event));
		QueuedEventTimestamps[NextPacketIndex] = Imports::TimeGetTime();
		NextPacketIndex = (NextPacketIndex + 1) & 0x7F;
		++LastEventIndex;
		return true;
	}

	// existing functions from Westwood

	/**
	 * dam girl, you crazy
	 *
	 * this gets called when you click-command your objects
	 * from inside TechnoClass::ClickedMission, where this is the selected object
	 *
	 * selfID and selfWhatAmI are results of Pack(this)
	 * PackedTarget and PackedTargetCell are pointers to the Pack()ed versions of the Target and TargetCell of ClickedMission
	 */
	static bool __fastcall CreateClickedMissionEvent
			(eMission Mission, NetID *PackedTarget, int selfID, char selfWhatAmI, NetID *PackedTargetCell)
		{ JMP_STD(0x646E90); }

};

#endif
