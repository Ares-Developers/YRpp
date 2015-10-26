#pragma once

class FPSCounter
{
public:
	//!< The number of frames processed in the last second.
	static unsigned int &CurrentFrameRate;

	//!< The total number of frames elapsed.
	static unsigned int &TotalFramesElapsed;

	//!< The time it took to process TotalFramesElapsed frames.
	static unsigned int &TotalTimeElapsed;

	//!< Whether the current fps is considered too low.
	static bool &ReducedEffects;

	//!< The average frame rate for all frames processed.
	static inline double GetAverageFrameRate()
	{
		if(TotalTimeElapsed) {
			return static_cast<double>(TotalFramesElapsed)
				/ static_cast<double>(TotalTimeElapsed);
		}

		return 0.0;
	}
};

class Detail {
public:
	//!< What is considered the minimum acceptable FPS.
	static unsigned int &MinFrameRate;

	//!< The zone that needs to be left to change 
	static unsigned int &BufferZoneWidth;

	//!< The minimum frame rate considering the buffer zone.
	static inline unsigned int GetMinFrameRate()
		{ JMP_STD(0x55AF60); }

	//!< Whether effects should be reduced.
	static inline bool ReduceEffects()
	{
		return FPSCounter::CurrentFrameRate < GetMinFrameRate();
	}
};
