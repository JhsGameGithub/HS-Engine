#pragma once

#include "TimeStruct.h"

//시간 싱글톤
class Timer
{
public:
	static Timer& instance()
	{
		static Timer instance;

		return instance;
	}

public:
	void initTimer();
	double getElapsed();
	LARGE_INTEGER getFrequency();
	void updateTimer();

	double deltaTime();

private:
	Timer() {};

	Timer(const Timer&) = delete;

	void operator=(const Timer&) = delete;

private:
	//자신의 TIme변수 구조체
	TimeStruct myTime;
};