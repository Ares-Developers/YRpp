#pragma once

class FPSCounter
{
public:
	//!< The number of frames processed in the last second.
	static constexpr reference<unsigned int, 0xABCD44u> const CurrentFrameRate{};

	//!< The total number of frames elapsed.
	static constexpr reference<unsigned int, 0xABCD48u> const TotalFramesElapsed{};

	//!< The time it took to process TotalFramesElapsed frames.
	static constexpr reference<unsigned int, 0xABCD4Cu> const TotalTimeElapsed{};

	//!< Whether the current fps is considered too low.
	static constexpr reference<bool, 0xABCD50u> const ReducedEffects{};

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
	static constexpr reference<unsigned int, 0x829FF4u> const MinFrameRate{};

	//!< The zone that needs to be left to change
	static constexpr reference<unsigned int, 0x829FF8u> const BufferZoneWidth{};

	//!< The minimum frame rate considering the buffer zone.
	static inline unsigned int GetMinFrameRate()
		{ JMP_STD(0x55AF60); }

	//!< Whether effects should be reduced.
	static inline bool ReduceEffects()
	{
		return FPSCounter::CurrentFrameRate < GetMinFrameRate();
	}
};
