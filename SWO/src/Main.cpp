#include <iostream>
#include <Windows.h>
#include <string>
#include "Timer.h"
#include "Profile.h"

std::string showMenu();
int numberChecker(int min, int max);

int main() 
{
	Timer timer;
	Profile profile;
	bool quit = false;

	while (!quit)
	{
		std::cout << showMenu();

		switch (numberChecker(1, 5))
		{
		case 1:
			system("cls");
			std::cout << "Enter the name of your profile BUT NO SPACES: ";
			profile.writeProfile(profile.getName());
			break;
		case 2:
			system("cls");
			std::cout << "Enter the name of the profile you want to load: ";
			profile.readProfile(profile.getName());
			break;
		case 3:
			system("cls");
			std::cout << "save profile" << std::endl;
			break;
		case 4:
			timer.start();
			break;
		case 5:
			std::cout << "Thank you for using SWO! See you soon!" << std::endl;
			quit = true;
			break;
		default:
			break;
		}
	}
}

std::string showMenu()
{
	std::string str = "";

	str = "Welcome to SWO! The spontaneous workout plan to make you swole!\n";
	str.append("---------------------------------------------------------------\n");
	str.append("1. Create profile\n");
	str.append("2. Load profile\n");
	str.append("3. Save profile\n");
	str.append("4. Quick start\n");
	str.append("5. Exit\n\n");
	str.append("Please select an option: ");

	return str;
}

int numberChecker(int min, int max)
{
	double number;
	std::cin >> number;

	if (std::cin.fail() || (number - floor(number)) || (number < min || number > max))
	{
		system("cls");
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Invalid input. Please enter a valid number.\n\n" << showMenu();

		return numberChecker(min, max);
	}

	return number;
}