#pragma once

#ifndef TIMER
#define TIMER

#include <chrono>

struct Timer {

	Timer();
	void Reset();
	float ElapsedTime();
	float ElapsedMilliSeconds();

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

#endif // !TIMER