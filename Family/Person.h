#pragma once
#include "Header.h"
#include "Height.h"
#include "Birthday.h"
#include "Death.h"

enum class GENDER {
	UNKNOWN = -1,
	OTHER = 0,
	MALE = 1,
	FEMALE = 2
};

enum SPECIALTITLE {
	SPOUSE,
	EXSPOUSE,
	CHILD,
	GIRLFRIEND,
	BOYFRIEND,
	EXGIRLFRIEND,
	EXBOYFRIEND,
	BESTFRIEND,
	FRIEND,
};

class Person
{

	static std::map<unsigned long long, Person*> People;

	static unsigned long long NextPersonId;
	static std::vector<unsigned long long> OpenPeopleIds;

	unsigned long long p_Id;

	std::string p_FirstName;
	std::string p_MiddleName;
	std::string p_LastName;

	GENDER p_Gender;
	Height p_Height;
	Birthday p_Birthday;

	float p_Age;

	Person* p_ParentOne;
	Person* p_ParentTwo;

	std::map<SPECIALTITLE, std::string> p_SpecialTitles;
	std::map<std::string, std::vector<Person*>> p_KnownPeople;
	std::vector<Pet*> p_Pets;
	std::map<std::string, Date> p_SpecialDates;

	Dead Death;

public:

	Person();
	Person(std::string in_FirstName, GENDER in_Gender);
	Person(std::string in_FirstName, GENDER in_Gender, Birthday in_Birthday);
	Person(std::string in_FirstName, GENDER in_Gender, Height in_Height, Birthday in_Birthday);
	Person(std::string in_FirstName, std::string in_LastName, GENDER in_Gender, Height in_Height, Birthday in_Birthday);
	Person(std::string in_FirstName, std::string in_MiddleName, std::string in_LastName, GENDER in_Gender, Height in_Height, Birthday in_Birthday);

	Person(std::string in_FirstName, GENDER in_Gender, float in_Age);
	Person(std::string in_FirstName, GENDER in_Gender, Height in_Height, float in_Age);
	Person(std::string in_FirstName, std::string in_LastName, GENDER in_Gender, Height in_Height, float in_Age);
	Person(std::string in_FirstName, std::string in_MiddleName, std::string in_LastName, GENDER in_Gender, Height in_Height, float in_Age);

	Person(std::string in_FirstName, std::string in_MiddleName, std::string in_LastName, GENDER in_Gender, Height in_Height);

	Person(std::string in_FirstName, std::string in_MiddleName, std::string in_LastName);

	~Person();

private:

	static Person* FindPersonById(unsigned long long Id);

	unsigned long long ReceiveId();
	void DeleteId();

	float CleanAgeInput(float Age) const;

public:

	unsigned long long GetId() const;
	
	std::string GetFirstName() const;
	void SetFirstName(std::string p_FirstName);

	std::string GetMiddleName() const;
	void SetMiddleName(std::string p_MiddleName);
	
	std::string GetLastName() const;
	void SetLastName(std::string p_LastName);
	
	GENDER GetGender() const;
	std::string GetGenderAsString() const;
	void SetGender(GENDER p_Gender);
	
	Height GetHeight() const;
	void SetHeight(Height p_Height);
	
	Birthday GetBirthday() const;
	void SetBirthday(Birthday p_Birthday);
	
	float GetAge() const;
	std::string GetAgeAsString() const;
	void SetAge(float Age);
	
	Person* GetParentOne() const;
	void SetParentOne(Person& p_Parent);
	
	Person* GetParentTwo() const;
	void SetParentTwo(Person& p_Parent);
	
	std::string GetSpecialTitle(SPECIALTITLE p_SpecialTitle);
	void SetSpecialTitle(SPECIALTITLE p_SpecialTitle, std::string s_SpecialTitle);
	
	std::vector<Person*> GetKnownPerson(std::string Title, std::string FirstName);
	std::vector<Person*> GetKnownPerson(std::string Title, std::string FirstName, std::string LastName);
	Person* GetKnownPerson(std::string Title, std::string FirstName, std::string MiddleName, std::string LastName);
	void AddKnownPerson(std::string Title, Person& p_KnownPerson);
	void RemoveKnownPerson(std::string Title, unsigned long long PersonId);

	std::vector<Pet*> GetPet(std::string PetName);
	std::vector<Pet*> GetPet(std::string PetName, std::string Species);
	Pet* GetPet(std::string PetName, std::string Species, std::string Description);
	void AddPet(Pet& p_Pet);
	void RemovePet(unsigned long long PetId);

	Date GetSpecialDate(std::string Title);
	void AddSpecialDate(std::string Title, Date p_SpecialDate);
	void RemoveSpecialDate(std::string Title);

	bool IsDead() const;
	void Kill();

	Date GetDeathDate() const;
	void SetDeathDate(Date DeathDate);

	std::string GetLastWords() const;
	void SetLastWords(std::string LastWords);

	void PrintPets();
	void PrintFamilyTree();
	void PrintKnownPeople();

	bool operator==(const Person& other) const;

};

std::ostream& operator<<(std::ostream& stream, Person& PrintPerson);

namespace PeopleOperations {

	void Marry(Person& PersonOne, Person& PersonTwo);
	void Devorce(Person& PersonOne, Person& PersonTwo);

	void HaveChild(Person& PersonOne, Person& PersonTwo, Person& Child);
	void Kill(Person& PersonOne, Date DeathDate, std::string LastWords);
	void Kill(Person& PersonOne, Date DeathDate);
	void Kill(Person& PersonOne, std::string LastWords);

	void AdoptPet(Person& PersonOne, Pet& PetOne);
}