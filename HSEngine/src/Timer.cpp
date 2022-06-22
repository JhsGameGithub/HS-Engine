#include "../header/Timer.h"

void Timer::initTimer()
{
	QueryPerformanceFrequency(&myTime.myFrequency);
	QueryPerformanceCounter(&myTime.previousTime);
}

void Timer::updateTimer()
{
	QueryPerformanceCounter(&myTime.currentTime);
	myTime.elapsedTime = (double)myTime.currentTime.QuadPart - (double)myTime.previousTime.QuadPart;
	myTime.previousTime = myTime.currentTime;
}
//
double Timer::getElapsed()
{
	return myTime.elapsedTime;
}

LARGE_INTEGER Timer::getFrequency()
{
	return myTime.myFrequency;
}
double Timer::deltaTime()
{
	return myTime.elapsedTime / (double)myTime.myFrequency.QuadPart;
}