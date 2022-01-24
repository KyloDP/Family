#pragma once
#include "Header.h"

class Height
{
	int Feet;
	int Inches;

public:

	Height();
	Height(int Feet);
	Height(int Feet, int Inches);

	int GetFeet() const;
	void SetFeet(int Feet);
	int GetInches() const;
	void SetInches(int Inches);
	std::string GetHeight() const;

	bool operator==(const Height& other)
	{
		if(GetFeet() == other.GetFeet() && GetInches() == other.GetInches())
		{
			return true;
		}

		return false;
	}

};