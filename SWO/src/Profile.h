#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

class Profile
{
private:
	int level;
	std::string name;

public:
	Profile();

	void readProfile(std::string fileName);
	void writeProfile(std::string fileName);

	void setLevel(int l);
	int getLevel();

	void setName(std::string n);
	std::string getName();
};