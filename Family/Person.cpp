#include "Header.h"
#include "Person.h"

std::map<unsigned long long, Person*> Person::People;

unsigned long long Person::NextPersonId;
std::vector<unsigned long long> Person::OpenPeopleIds;

Person::Person()
	: p_Id(ReceiveId()), p_FirstName("Unknown"), p_MiddleName("Unknown"), p_LastName("Unknown"), p_Gender(GENDER::UNKNOWN), p_Height(Height()), p_Birthday(Birthday()), p_Age(-1), p_ParentOne(nullptr), p_ParentTwo(nullptr)
{}

Person::Person(std::string in_FirstName, GENDER in_Gender)
	: p_Id(ReceiveId()), p_FirstName(in_FirstName), p_MiddleName("Unknown"), p_LastName("Unknown"), p_Gender(in_Gender), p_Height(Height()), p_Birthday(Birthday()), p_Age(-1), p_ParentOne(nullptr), p_ParentTwo(nullptr)
{}

Person::Person(std::string in_FirstName, GENDER in_Gender, Birthday in_Birthday)
	: p_Id(ReceiveId()), p_FirstName(in_FirstName), p_MiddleName("Unknown"), p_LastName("Unknown"), p_Gender(in_Gender), p_Height(Height()), p_Birthday(in_Birthday), p_Age(in_Birthday.GetAge()), p_ParentOne(nullptr), p_ParentTwo(nullptr)
{}

Person::Person(std::string in_FirstName, GENDER in_Gender, Height in_Height, Birthday in_Birthday)
	: p_Id(ReceiveId()), p_FirstName(in_FirstName), p_MiddleName("Unknown"), p_LastName("Unknown"), p_Gender(in_Gender), p_Height(in_Height), p_Birthday(in_Birthday), p_Age(in_Birthday.GetAge()), p_ParentOne(nullptr), p_ParentTwo(nullptr)
{}

Person::Person(std::string in_FirstName, std::string in_LastName, GENDER in_Gender, Height in_Height, Birthday in_Birthday)
	: p_Id(ReceiveId()), p_FirstName(in_FirstName), p_MiddleName("Unknown"), p_LastName(in_LastName), p_Gender(in_Gender), p_Height(in_Height), p_Birthday(in_Birthday), p_Age(in_Birthday.GetAge()), p_ParentOne(nullptr), p_ParentTwo(nullptr)
{}

Person::Person(std::string in_FirstName, std::string in_MiddleName, std::string in_LastName, GENDER in_Gender, Height in_Height, Birthday in_Birthday)
	: p_Id(ReceiveId()), p_FirstName(in_FirstName), p_MiddleName(in_MiddleName), p_LastName(in_LastName), p_Gender(in_Gender), p_Height(in_Height), p_Birthday(in_Birthday), p_Age(in_Birthday.GetAge()), p_ParentOne(nullptr), p_ParentTwo(nullptr)
{}

Person::Person(std::string in_FirstName, GENDER in_Gender, float in_Age)
	: p_Id(ReceiveId()), p_FirstName(in_FirstName), p_MiddleName("Unknown"), p_LastName("Unknown"), p_Gender(in_Gender), p_Height(Height()), p_Birthday(Birthday()), p_Age(CleanAgeInput(in_Age)), p_ParentOne(nullptr), p_ParentTwo(nullptr)
{}

Person::Person(std::string in_FirstName, GENDER in_Gender, Height in_Height, float in_Age)
	: p_Id(ReceiveId()), p_FirstName(in_FirstName), p_MiddleName("Unknown"), p_LastName("Unknown"), p_Gender(in_Gender), p_Height(in_Height), p_Birthday(Birthday()), p_Age(CleanAgeInput(in_Age)), p_ParentOne(nullptr), p_ParentTwo(nullptr)
{}

Person::Person(std::string in_FirstName, std::string in_LastName, GENDER in_Gender, Height in_Height, float in_Age)
	: p_Id(ReceiveId()), p_FirstName(in_FirstName), p_MiddleName("Unknown"), p_LastName(in_LastName), p_Gender(in_Gender), p_Height(in_Height), p_Birthday(Birthday()), p_Age(CleanAgeInput(in_Age)), p_ParentOne(nullptr), p_ParentTwo(nullptr)
{}

Person::Person(std::string in_FirstName, std::string in_MiddleName, std::string in_LastName, GENDER in_Gender, Height in_Height, float in_Age)
	: p_Id(ReceiveId()), p_FirstName(in_FirstName), p_MiddleName(in_MiddleName), p_LastName(in_LastName), p_Gender(in_Gender), p_Height(in_Height), p_Birthday(Birthday()), p_Age(CleanAgeInput(in_Age)), p_ParentOne(nullptr), p_ParentTwo(nullptr)
{}

Person::Person(std::string in_FirstName, std::string in_MiddleName, std::string in_LastName, GENDER in_Gender, Height in_Height)
	: p_Id(ReceiveId()), p_FirstName(in_FirstName), p_MiddleName(in_MiddleName), p_LastName(in_LastName), p_Gender(in_Gender), p_Height(in_Height), p_Birthday(Birthday()), p_Age(-1), p_ParentOne(nullptr), p_ParentTwo(nullptr)
{}

Person::Person(std::string in_FirstName, std::string in_MiddleName, std::string in_LastName)
	: p_Id(ReceiveId()), p_FirstName(in_FirstName), p_MiddleName(in_MiddleName), p_LastName(in_LastName), p_Gender(GENDER::UNKNOWN), p_Height(Height()), p_Birthday(Birthday()), p_Age(-1), p_ParentOne(nullptr), p_ParentTwo(nullptr)
{}

Person::~Person()
{

	DeleteId();

}

unsigned long long Person::ReceiveId()
{

	unsigned long long Id = 0;

	if (OpenPeopleIds.size() > 0)
	{
		Id = OpenPeopleIds[0];
		OpenPeopleIds.erase(OpenPeopleIds.begin());
	}

	if (Id == 0)
	{
		Id = NextPersonId;
		NextPersonId += 1;
	}


	People[Id] = this;

	return Id;
}

void Person::DeleteId()
{

	People.erase(GetId());
	OpenPeopleIds.push_back(GetId());

}

float Person::CleanAgeInput(float Age) const
{
	if (Age >= 0 || Age == -1)
	{
		return Age;
	}
	
	return -1;
}

unsigned long long Person::GetId() const
{
	return p_Id;
}

std::string Person::GetFirstName() const
{
	return p_FirstName;
}

void Person::SetFirstName(std::string p_FirstName)
{
	this->p_FirstName = p_FirstName;
}

std::string Person::GetMiddleName() const
{
	return p_MiddleName;
}

void Person::SetMiddleName(std::string p_MiddleName)
{
	this->p_MiddleName = p_MiddleName;
}

std::string Person::GetLastName() const
{
	return p_LastName;
}

void Person::SetLastName(std::string p_LastName)
{
	this->p_LastName = p_LastName;
}

GENDER Person::GetGender() const
{
	return p_Gender;
}

std::string Person::GetGenderAsString() const
{
	if (p_Gender == GENDER::MALE)
	{
		return "Male";
	}
	else if (p_Gender == GENDER::FEMALE)
	{
		return "Female";
	}
	else if (p_Gender == GENDER::OTHER)
	{
		return "Other";
	}
	else {
		return "Unknown";
	}
}

void Person::SetGender(GENDER p_Gender)
{
	this->p_Gender = p_Gender;
}

Height Person::GetHeight() const
{
	return p_Height;
}

void Person::SetHeight(Height p_Height)
{
	this->p_Height = p_Height;
}

Birthday Person::GetBirthday() const
{
	return p_Birthday;
}

void Person::SetBirthday(Birthday p_Birthday)
{
	this->p_Birthday = p_Birthday;
}

float Person::GetAge() const
{
	return p_Age;
}

std::string Person::GetAgeAsString() const
{
	if (p_Age == -1)
	{
		return "Unknown";
	}

	if (p_Age == (int)p_Age)
	{
		return std::to_string((int)p_Age);
	}
	
	return std::to_string(p_Age);
}

void Person::SetAge(float p_Age)
{
	this->p_Age = p_Age;
}

Person* Person::GetParentOne() const
{
	try
	{
		if (p_ParentOne != nullptr)
		{
			return p_ParentOne;
		}
	}
	catch (const std::bad_alloc& e) {}

	return (new Person());
}

void Person::SetParentOne(Person& p_Parent)
{

	this->p_ParentOne = &p_Parent;

}

Person* Person::GetParentTwo() const
{
	try
	{
		if (p_ParentTwo != nullptr)
		{
			return p_ParentTwo;
		}
	}
	catch (const std::bad_alloc& e) {}

	return (new Person());
}

void Person::SetParentTwo(Person& p_Parent)
{

	this->p_ParentTwo = &p_Parent;

}

std::string Person::GetSpecialTitle(SPECIALTITLE p_SpecialTitle)
{
	return p_SpecialTitles[p_SpecialTitle];
}

void Person::SetSpecialTitle(SPECIALTITLE p_SpecialTitle, std::string s_SpecialTitle)
{
	this->p_SpecialTitles[p_SpecialTitle] = s_SpecialTitle;
}

std::vector<Person*> Person::GetKnownPerson(std::string Title, std::string FirstName)
{

	std::vector<Person*> vec;

	for (int i = 0; i < p_KnownPeople[Title].size(); i++)
	{

		auto TitledPerson = p_KnownPeople[Title][i];

		try
		{
			if (TitledPerson->GetFirstName() == FirstName)
			{
				vec.push_back(TitledPerson);
			}
		}
		catch (const std::bad_alloc& e)
		{
			p_KnownPeople[Title].erase(p_KnownPeople[Title].begin() + i);
			continue;
		}

	}

	return vec;

}

std::vector<Person*> Person::GetKnownPerson(std::string Title, std::string FirstName, std::string LastName)
{

	std::vector<Person*> vec;

	for (int i = 0; i < p_KnownPeople[Title].size(); i++)
	{

		auto TitledPerson = p_KnownPeople[Title][i];

		try
		{
			if (TitledPerson->GetFirstName() == FirstName && TitledPerson->GetLastName() == LastName)
			{
				vec.push_back(TitledPerson);
			}
		}
		catch (const std::bad_alloc& e)
		{
			p_KnownPeople[Title].erase(p_KnownPeople[Title].begin() + i);
			continue;
		}

	}

	return vec;

}

Person* Person::GetKnownPerson(std::string Title, std::string FirstName, std::string MiddleName, std::string LastName)
{

	for (int i = 0; i < p_KnownPeople[Title].size(); i++)
	{

		auto TitledPerson = p_KnownPeople[Title][i];

		try
		{
			if (TitledPerson->GetFirstName() == FirstName && TitledPerson->GetMiddleName() == MiddleName && TitledPerson->GetLastName() == LastName)
			{
				return TitledPerson;
			}
		}
		catch (const std::bad_alloc& e)
		{
			p_KnownPeople[Title].erase(p_KnownPeople[Title].begin() + i);
			continue;
		}

	}

	return (new Person());

}

void Person::AddKnownPerson(std::string Title, Person& p_KnownPerson)
{
	p_KnownPeople[Title].push_back(&p_KnownPerson);
}

void Person::RemoveKnownPerson(std::string Title, unsigned long long PersonId)
{

	auto Group = p_KnownPeople[Title];

	for (int i = 0; i < Group.size(); i++)
	{

		if (Group[i]->GetId() == PersonId)
		{
			p_KnownPeople[Title].erase(p_KnownPeople[Title].begin() + i);
		}

	}
}

std::vector<Pet*> Person::GetPet(std::string PetName)
{

	std::vector<Pet*> vec;

	for (int i = 0; i < p_Pets.size(); i++)
	{
		try
		{
			if (p_Pets[i]->GetPetName() == PetName)
			{
				vec.push_back(p_Pets[i]);
			}
		}
		catch (const std::bad_alloc& e)
		{
			p_Pets.erase(p_Pets.begin() + i);
			continue;
		}
	}

	return vec;

}

std::vector<Pet*> Person::GetPet(std::string PetName, std::string Species)
{

	std::vector<Pet*> vec;

	for (int i = 0; i < p_Pets.size(); i++)
	{
		try
		{
			if (p_Pets[i]->GetPetName() == PetName && p_Pets[i]->GetSpecies() == Species)
			{
				vec.push_back(p_Pets[i]);
			}
		}
		catch (const std::bad_alloc& e)
		{
			p_Pets.erase(p_Pets.begin() + i);
			continue;
		}
	}

	return vec;

}

Pet* Person::GetPet(std::string PetName, std::string Species, std::string Description)
{

	for (int i = 0; i < p_Pets.size(); i++)
	{
		try
		{
			if (p_Pets[i]->GetPetName() == PetName && p_Pets[i]->GetSpecies() == Species && p_Pets[i]->GetDescription() == Description)
			{
				return p_Pets[i];
			}
		}
		catch (const std::bad_alloc& e)
		{
			p_Pets.erase(p_Pets.begin() + i);
			continue;
		}
	}

	return (new Pet());

}

void Person::AddPet(Pet& p_Pet)
{
	p_Pets.push_back(&p_Pet);
}

void Person::RemovePet(unsigned long long PetId)
{
	for (int i = 0; i < p_Pets.size(); i++)
	{
		try
		{
			if (p_Pets[i]->GetId() == PetId)
			{
				p_Pets.erase(p_Pets.begin() + i);
			}
		}
		catch (const std::bad_alloc& e)
		{
			p_Pets.erase(p_Pets.begin() + i);
			continue;
		}
	}
}

Date Person::GetSpecialDate(std::string Title)
{
	return p_SpecialDates[Title];
}

void Person::AddSpecialDate(std::string Title, Date p_SpecialDate)
{
	p_SpecialDates[Title] = p_SpecialDate;
}

void Person::RemoveSpecialDate(std::string Title)
{
	p_SpecialDates.erase(Title);
}

bool Person::IsDead() const
{
	return Death.IsDead();
}

void Person::Kill()
{
	Death.Kill();
}

Date Person::GetDeathDate() const
{
	return Death.GetDeathDate();
}
void Person::SetDeathDate(Date DeathDate)
{
	Death.SetDeathDate(DeathDate);
}

std::string Person::GetLastWords() const
{
	return Death.GetLastWords();
}
void Person::SetLastWords(std::string LastWords)
{
	Death.SetLastWords(LastWords);
}

void Person::PrintPets()
{

	for (auto p_Pet : p_Pets)
	{

		bool Exists;

		auto OwnerId = p_Pet->GetOwnerId(Exists);

		if (Exists)
		{
			std::cout << "Owner Name: " << Person::FindPersonById(OwnerId)->GetFirstName() << "\n";
		}
		else {
			std::cout << "Owner Name: Unknown\n";
		}

		std::cout << "Name: " << p_Pet->GetPetName() << "\n";
		std::cout << "Species: " << p_Pet->GetSpecies() << "\n";

		if (typeid(*p_Pet) == typeid(PetDog))
		{
			std::cout << "Breed: " << ((PetDog*)p_Pet)->GetBreed() << "\n";
		}

		std::cout << "\n";

	}

}

void Person::PrintFamilyTree()
{

	std::cout << *this;

	for (auto Group : p_KnownPeople)
	{
		for (int i = 0; i < Group.second.size(); i++)
		{

			auto KnownPerson = Group.second[i];

			try
			{
				if (KnownPerson->GetMiddleName() == "Unknown")
				{
					std::cout << Group.first << ": " << KnownPerson->GetFirstName() << " " << KnownPerson->GetLastName() << "\n";
				}
				else {
					std::cout << Group.first << ": " << KnownPerson->GetFirstName() << " " << KnownPerson->GetMiddleName() << " " << KnownPerson->GetLastName() << "\n";
				}
			}
			catch (const std::bad_alloc& e)
			{
				p_KnownPeople[Group.first].erase(p_KnownPeople[Group.first].begin() + i);
				continue;
			}
		}
	}

	for (auto p_Pet : p_Pets)
	{
		std::cout << "Pet: " << p_Pet->GetPetName() << "\n";
	}

	std::cout << "\n";

	std::string ChildTitle;

	if (p_SpecialTitles[SPECIALTITLE::CHILD] != "")
	{
		ChildTitle = p_SpecialTitles[SPECIALTITLE::CHILD];
	}
	else {
		ChildTitle = "Child";
	}

	for (auto Group : p_KnownPeople)
	{
		if (Group.first == ChildTitle)
		{
			for (int i = 0; i < Group.second.size(); i++)
			{
				auto Child = Group.second[i];

				try
				{
					Child->PrintFamilyTree();
				}
				catch (const std::bad_alloc& e)
				{
					p_KnownPeople[Group.first].erase(p_KnownPeople[Group.first].begin() + i);
					continue;
				}
			}
		}
		else {
			for (int i = 0; i < Group.second.size(); i++)
			{
				auto KnownPerson = Group.second[i];

				try
				{
					std::cout << *KnownPerson << "\n";
				}
				catch (const std::bad_alloc& e)
				{
					p_KnownPeople[Group.first].erase(p_KnownPeople[Group.first].begin() + i);
					continue;
				}
			}
		}
	}

	PrintPets();

}

void Person::PrintKnownPeople()
{

	for (auto Group : p_KnownPeople)
	{
		for (int i = 0; i < Group.second.size(); i++)
		{
			auto KnownPerson = Group.second[i];

			try
			{
				std::cout << *KnownPerson << "\n";
			}
			catch (const std::bad_alloc& e)
			{
				p_KnownPeople[Group.first].erase(p_KnownPeople[Group.first].begin() + i);
				continue;
			}
		}
	}

}

bool Person::operator==(const Person& other) const
{
	if (GetId() == other.GetId())
	{
		return true;
	}

	return false;
}

std::ostream& operator<<(std::ostream& stream, Person& PrintPerson)
{
	stream << "Child of " << PrintPerson.GetParentTwo()->GetFirstName() << " and " << PrintPerson.GetParentOne()->GetFirstName() << " " << PrintPerson.GetParentTwo()->GetLastName() << "\n";

	stream << "First Name: " << PrintPerson.GetFirstName() << "\n";
	stream << "Middle Name: " << PrintPerson.GetMiddleName() << "\n";
	stream << "Last Name: " << PrintPerson.GetLastName() << "\n";
	stream << "Gender: " << PrintPerson.GetGenderAsString() << "\n";
	stream << "Height: " << PrintPerson.GetHeight().GetHeight() << "\n";
	stream << "Birthday: " << PrintPerson.GetBirthday().GetDate() << "\n";
	stream << "Age: " << PrintPerson.GetAgeAsString() << "\n";

	if (PrintPerson.IsDead())
	{
		stream << "Date Of Death: " << PrintPerson.GetDeathDate().GetDate() << "\n";
		stream << "Last Words: " << PrintPerson.GetLastWords() << "\n";
	}

	return stream;
}

Person* Person::FindPersonById(unsigned long long Id)
{
	try
	{

		if (People[Id] != nullptr)
		{
			return People[Id];
		}
	}
	catch (const std::bad_alloc& e) {}

	return (new Person());

}

void PeopleOperations::Marry(Person& PersonOne, Person& PersonTwo)
{
	std::string SpouseTitleOne;
	std::string SpouseTitleTwo;

	if (PersonOne.GetSpecialTitle(SPECIALTITLE::SPOUSE) != "")
	{
		SpouseTitleOne = PersonOne.GetSpecialTitle(SPECIALTITLE::SPOUSE);
	}
	else {
		SpouseTitleOne = "Spouse";
	}

	if (PersonTwo.GetSpecialTitle(SPECIALTITLE::SPOUSE) != "")
	{
		SpouseTitleTwo = PersonTwo.GetSpecialTitle(SPECIALTITLE::SPOUSE);
	}
	else {
		SpouseTitleTwo = "Spouse";
	}

	PersonOne.AddKnownPerson(SpouseTitleOne, PersonTwo);
	PersonTwo.AddKnownPerson(SpouseTitleTwo, PersonOne);

}

void PeopleOperations::Devorce(Person& PersonOne, Person& PersonTwo)
{

	std::string SpouseTitleOne;
	std::string SpouseTitleTwo;

	if (PersonOne.GetSpecialTitle(SPECIALTITLE::SPOUSE) != "")
	{
		SpouseTitleOne = PersonOne.GetSpecialTitle(SPECIALTITLE::SPOUSE);
	}
	else {
		SpouseTitleOne = "Spouse";
	}

	if (PersonTwo.GetSpecialTitle(SPECIALTITLE::SPOUSE) != "")
	{
		SpouseTitleTwo = PersonTwo.GetSpecialTitle(SPECIALTITLE::SPOUSE);
	}
	else {
		SpouseTitleTwo = "Spouse";
	}

	std::string ExSpouseTitleOne;
	std::string ExSpouseTitleTwo;

	if (PersonOne.GetSpecialTitle(SPECIALTITLE::SPOUSE) != "")
	{
		ExSpouseTitleOne = PersonOne.GetSpecialTitle(SPECIALTITLE::SPOUSE);
	}
	else {
		ExSpouseTitleOne = "ExSpouse";
	}

	if (PersonTwo.GetSpecialTitle(SPECIALTITLE::SPOUSE) != "")
	{
		ExSpouseTitleTwo = PersonTwo.GetSpecialTitle(SPECIALTITLE::SPOUSE);
	}
	else {
		ExSpouseTitleTwo = "ExSpouse";
	}

	PersonOne.RemoveKnownPerson(SpouseTitleOne, PersonTwo.GetId());
	PersonOne.AddKnownPerson(ExSpouseTitleOne, PersonTwo);

	PersonTwo.RemoveKnownPerson(SpouseTitleTwo, PersonOne.GetId());
	PersonTwo.AddKnownPerson(ExSpouseTitleTwo, PersonOne);
}

void PeopleOperations::HaveChild(Person& PersonOne, Person& PersonTwo, Person& Child)
{
	std::string ChildTitleOne;
	std::string ChildTitleTwo;

	if (PersonOne.GetSpecialTitle(SPECIALTITLE::CHILD) != "")
	{
		ChildTitleOne = PersonOne.GetSpecialTitle(SPECIALTITLE::CHILD);
	}
	else {
		ChildTitleOne = "Child";
	}

	if (PersonTwo.GetSpecialTitle(SPECIALTITLE::CHILD) != "")
	{
		ChildTitleTwo = PersonTwo.GetSpecialTitle(SPECIALTITLE::CHILD);
	}
	else {
		ChildTitleTwo = "Child";
	}

	PersonOne.AddKnownPerson(ChildTitleOne, Child);
	PersonTwo.AddKnownPerson(ChildTitleTwo, Child);

	Child.SetParentOne(PersonTwo);
	Child.SetParentTwo(PersonOne);

}

void PeopleOperations::Kill(Person& PersonOne, Date DeathDate, std::string LastWords)
{

	PersonOne.Kill();
	PersonOne.SetDeathDate(DeathDate);
	PersonOne.SetLastWords(LastWords);

}

void PeopleOperations::Kill(Person& PersonOne, Date DeathDate)
{
	
	PersonOne.Kill();
	PersonOne.SetDeathDate(DeathDate);

}
void PeopleOperations::Kill(Person& PersonOne, std::string LastWords)
{

	PersonOne.Kill();
	PersonOne.SetLastWords(LastWords);

}

void PeopleOperations::AdoptPet(Person& PersonOne, Pet& PetOne)
{
	PersonOne.AddPet(PetOne);
	PetOne.AddOwnerId(PersonOne.GetFirstName(), PersonOne.GetId());
}
