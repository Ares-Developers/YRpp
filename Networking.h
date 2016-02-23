#pragma once

#include <NetworkEvents.h>
#include <Helpers\CompileTime.h>

class Networking {
public:
	static constexpr reference<DWORD, 0xAC51FCu> const CurrentFrameCRC{};

	// this points to CRCs from 0x100 last frames
	static constexpr reference<DWORD, 0xB04474u, 256u> const LatestFramesCRC{};

	static constexpr reference<int, 0xA802C8u> const LastEventIndex{};
	static constexpr reference<int, 0xA802D0u> const NextPacketIndex{};

	// these are really 128 length arrays
	static constexpr reference<NetworkEvent, 0xA802D4u, 128u> const QueuedEvents{};
	static constexpr reference<int, 0xA83A54u, 128u> const QueuedEventTimestamps{};

	// custom helper for Ares logics
	static bool AddEvent(NetworkEvent *event) {
		event->Timestamp = static_cast<DWORD>(Unsorted::CurrentFrame);
		if(LastEventIndex >= 128) {
			return false;
		}
		memcpy(&QueuedEvents[NextPacketIndex], event, sizeof(*event));
		QueuedEventTimestamps[NextPacketIndex] = static_cast<int>(Imports::TimeGetTime());
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
			(Mission Mission, NetID *PackedTarget, int selfID, char selfWhatAmI, NetID *PackedTargetCell)
		{ JMP_STD(0x646E90); }

};
