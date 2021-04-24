#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <stdlib.h>     //srand, rand
#include <time.h>       //time
#include <iomanip>		// std::setfill, std::setw

class Timer
{
public:
	bool isRunning = false;

	int seconds = 0;
	int minutes = 0;
	int hours = 0;

	Timer();

	void start();
	void stop();
	void activity();
	void showTimer();
};