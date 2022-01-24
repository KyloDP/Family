#pragma once

#include <string>

class Animal {

	std::string Species;
	std::string Description;

public:

	Animal();
	Animal(std::string Species, std::string Description);
	Animal(std::string Species);

	std::string GetSpecies() const;
	void SetSpecies(std::string Species);
	std::string GetDescription() const;
	void SetDescription(std::string Description);

};