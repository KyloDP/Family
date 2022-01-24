#include "Header.h"
#include "Height.h"

Height::Height()
	: Feet(-1), Inches(-1.0f)
{}

Height::Height(int Feet)
	: Feet(Feet), Inches(-1)
{}

Height::Height(int Feet, int Inches)
	: Feet(Feet), Inches(Inches)
{}

int Height::GetFeet() const
{
	return Feet;
}
void Height::SetFeet(int Feet)
{
	this->Feet = Feet;
}

int Height::GetInches() const
{
	return Inches;
}

void Height::SetInches(int Inches)
{
	this->Inches = Inches;
}

std::string Height::GetHeight() const
{
	return std::to_string(Feet) + "' " + std::to_string(Inches) + "\"";
}