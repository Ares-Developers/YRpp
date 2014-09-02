#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H

class FPSCounter
{
public:
	//!< The number of frames processed in the last second.
	static unsigned int &CurrentFrameRate;

	//!< The total number of frames elapsed.
	static unsigned int &TotalFramesElapsed;

	//!< The time it took to process TotalFramesElapsed frames.
	static unsigned int &TotalTimeElapsed;

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

#endif
