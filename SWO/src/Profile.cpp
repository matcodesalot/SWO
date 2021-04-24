#include "Profile.h"

Profile::Profile()
{
}

void Profile::readProfile(std::string fileName)
{
	std::cin >> fileName;

	std::ifstream file("res/" + fileName + ".txt");

	if (file.is_open())
	{
		std::vector<std::string> names;
		std::string input;

		while (getline(file, input))
		{
			names.push_back(input);
		}

		for (std::string name : names)
		{
			std::cout << name << std::endl;
		}
	}
	else
	{
		std::cout << "Error: Unable to open file." << std::endl;
	}
}

void Profile::writeProfile(std::string fileName)
{
	std::cin >> fileName;

	std::ofstream file("res/" + fileName + ".txt");

	if (file.is_open())
	{
		std::cout << "Profile saved successfully!" << std::endl;

		setName(fileName);
		setLevel(69);

		std::vector<std::string> names;
		names.push_back("Name: " + getName());
		names.push_back("Level: " + std::to_string(getLevel()));

		for (std::string name : names)
		{
			file << name << std::endl;
		}

		file.close();
	}
	else
	{
		std::cout << "Error: Unable to open file." << std::endl;
	}
}

void Profile::setLevel(int l)
{
	level = l;
}

int Profile::getLevel()
{
	return level;
}

void Profile::setName(std::string n)
{
	name = n;
}

std::string Profile::getName()
{
	return name;
}