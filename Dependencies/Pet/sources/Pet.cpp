#include <Pet.h>

std::map<unsigned long long, Pet*> Pet::Pets;

unsigned long long Pet::NextPetId;
std::vector<unsigned long long> Pet::OpenPetIds;

Pet::Pet()
	: Animal()
{}

Pet::Pet(std::string PetName, std::string Species, std::string Description)
	: PetName(PetName), Animal(Species, Description)
{}

Pet::Pet(std::string PetName, std::string Species)
	: PetName(PetName), Animal(Species)
{}

Pet::Pet(std::string PetName)
	: PetName(PetName), Animal()
{}

Pet::~Pet()
{
	DeleteId();
}

unsigned long long Pet::ReceiveId()
{
	unsigned long long Id = 0;

	if (OpenPetIds.size() > 0)
	{
		Id = OpenPetIds[0];
		OpenPetIds.erase(OpenPetIds.begin());
	}

	if (Id == 0)
	{
		Id = NextPetId;
		NextPetId += 1;
	}


	Pets[Id] = this;

	return Id;
}

void Pet::DeleteId()
{
	Pets.erase(GetId());
	OpenPetIds.push_back(GetId());
}

unsigned long long Pet::GetId() const
{
	return PetId;
}

unsigned long long Pet::GetOwnerId(bool& Exists)
{

	std::map<std::string, unsigned long long>::iterator Return;

	Return = OwnerIds.end();

	for (auto OwnerId : OwnerIds)
	{
		Return = OwnerIds.find(OwnerId.first);
	}

	if (Return != OwnerIds.end())
	{
		Exists = true;
	}
	else {
		Exists = false;
	}

	return Return->second;
}

unsigned long long Pet::GetOwnerId(std::string OwnerName, bool& Exists)
{

	if (OwnerIds.find(OwnerName) != OwnerIds.end())
	{
		Exists = true;
		return OwnerIds.find(OwnerName)->second;
	}
	else {
		Exists = false;
	}

	return 0;

}

void Pet::AddOwnerId(std::string OwnerName, unsigned long long OwnerId)
{
	this->OwnerIds[OwnerName] = OwnerId;
}

void Pet::RemoveOwnerId(std::string OwnerName)
{
	this->OwnerIds.erase(OwnerName);
}

std::string Pet::GetPetName() const
{
	return PetName;
}

void Pet::SetPetName(std::string PetName)
{
	this->PetName = PetName;
}

// ------------ PetDog ----------------------------

PetDog::PetDog()
	:Breed(""), Pet()
{}

PetDog::PetDog(std::string PetName, std::string Breed, std::string Description)
	: Breed(Breed), Pet(PetName, "Dog", Description)
{}

PetDog::PetDog(std::string PetName, std::string Breed)
	: Breed(Breed), Pet(PetName, "Dog")
{}


PetDog::PetDog(std::string PetName)
	: Breed("Unknown"), Pet(PetName, "Dog")
{}

std::string PetDog::GetBreed() const
{
	return Breed;
}

void PetDog::SetBreed(std::string Breed)
{
	this->Breed = Breed;
}