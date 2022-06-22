#pragma once

#include "TimeStruct.h"

//�ð� �̱���
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
	//�ڽ��� TIme���� ����ü
	TimeStruct myTime;
};