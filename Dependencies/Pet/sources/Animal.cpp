#include <Animal.h>

Animal::Animal()
	:Species("Unknown"), Description("Unknown")
{}

Animal::Animal(std::string Species, std::string Description)
	:Species(Species), Description(Description)
{}

Animal::Animal(std::string Species)
	:Species(Species), Description("")
{}

std::string Animal::GetSpecies() const
{
	return Species;
}

void Animal::SetSpecies(std::string Species)
{
	this->Species = Species;
}

std::string Animal::GetDescription() const
{
	return Description;
}

void Animal::SetDescription(std::string Description)
{
	this->Description = Description;
}