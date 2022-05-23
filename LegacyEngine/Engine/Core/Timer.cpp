#include "Core/Headers/Timer.h"

Timer::Timer() {
	Reset();
}

void Timer::Reset() {
	start = std::chrono::high_resolution_clock::now();
}

float Timer::ElapsedTime() {
	return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start).count() * 0.001f * 0.001f * 0.001f;
}

float Timer::ElapsedMilliSeconds() {
	return ElapsedTime() * 1000.0f;
}
