#include "Timer.h"
#include "Profile.h"

Timer::Timer()
{
	//initialize random seed
	srand(time(NULL));
}

void Timer::start()
{
	isRunning = true;

	while (isRunning)
	{
		showTimer();

		Sleep(1000);

		seconds++;
		if (seconds % 5 == 0)
		{
			Timer::activity();
		}
		if (seconds >= 60)
		{
			minutes++;

			if (minutes >= 60)
			{
				hours++;
				minutes = 0;
			}

			seconds = 0;

			/*if (minutes % 30 == 0)
			{
				Timer::activity();
			}*/
		}
		
		//It detects button press when window is minimized. I don't want that.
		if (GetKeyState(VK_ESCAPE) & 0x8000)
		{
			Timer::stop();
			system("cls");
		}
	}
}

void Timer::stop()
{
	isRunning = false;
	seconds = 0;
	minutes = 0;
	hours = 0;
}

void Timer::activity()
{
	std::string activityList[] = {
		"Do 10 jumping jacks",
		"Do 10 push-ups",
		"Do 10 leg raises",
		"Do 10 squats",
		"Go up and down the stairs 5 times",
		"Stretch",
		"Do 10 crunches",
		"Bring Sally Up"
	};

	int len = sizeof(activityList) / sizeof(activityList[0]);
	std::string theActivity = activityList[(rand() % len)];

	int messageBoxID = MessageBoxA(nullptr, theActivity.c_str(), "Get ya lazy ass up!", MB_OK | MB_ICONEXCLAMATION);
	Profile profile;

	switch (messageBoxID)
	{
	case IDOK:
		std::cout << "You pressed ok" << std::endl;
		int profileLevel = profile.getLevel();
		profile.setLevel(profileLevel++);
		//profile.writeProfile("res/" + fileName + ".txt");
	}
}

void Timer::showTimer()
{
	system("cls");
	std::cout << "            TIMER" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "| " << std::setfill('0') << std::setw(2) << hours << " hrs | ";
	std::cout << std::setfill('0') << std::setw(2) << minutes << " min | ";
	std::cout << std::setfill('0') << std::setw(2) << seconds << " sec |" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "(press ESC to return to menu)" << std::endl;
}