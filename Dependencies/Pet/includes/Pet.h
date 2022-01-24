#pragma once
#include <Animal.h>
#include <map>
#include <vector>

class Pet : public Animal {

	static std::map<unsigned long long, Pet*> Pets;

	static unsigned long long NextPetId;
	static std::vector<unsigned long long> OpenPetIds;

	std::map<std::string, unsigned long long> OwnerIds;
	unsigned long long PetId;

	std::string PetName;

public:

	Pet();
	Pet(std::string PetName, std::string Species, std::string Description);
	Pet(std::string PetName, std::string Species);
	Pet(std::string PetName);
	~Pet();

private:

	unsigned long long ReceiveId();
	void DeleteId();

public:

	unsigned long long GetId() const;

	unsigned long long GetOwnerId(bool& Exists);
	unsigned long long GetOwnerId(std::string OwnerName, bool& Exists);
	void AddOwnerId(std::string OwnerName, unsigned long long OwnerId);
	void RemoveOwnerId(std::string OwnerName);

	std::string GetPetName() const;
	void SetPetName(std::string PetName);

};

class PetDog : public Pet {

	std::string Breed;

public:

	PetDog();
	PetDog(std::string PetName, std::string Breed, std::string Description);
	PetDog(std::string PetName, std::string Breed);
	PetDog(std::string PetName);

	std::string GetBreed() const;
	void SetBreed(std::string Breed);

};