#include "Header.h"
#include "Person.h"

int main()
{

	Person* Jeffery = new Person("Jeffery", "Scott", "Yoder", GENDER::MALE, Height(6, 2), Birthday(5, 16, 1995));
	Person* Elisabeth = new Person("Elisabeth", "Yoder", GENDER::FEMALE, Height(5, 8), Birthday(-1, -1, 1994));

	Person* Jared = new Person("Jared", "Yoder", GENDER::MALE, Height(5, 10), Birthday(3, 14, 1993));

	Person* Kendall = new Person("Kendall", "Yoder", GENDER::MALE, Height(5, 7), Birthday(6, 13, 1992));
	Person* Emilie = new Person("Emilie", "Miller", "Yoder", GENDER::FEMALE, Height(5, 6));

	Person* Krista = new Person("Krista", "Yoder", GENDER::FEMALE, Height(5, 2), Birthday(7, 20, 2000));
	Person* Lindsey = new Person("Lindsey", "Yoder", GENDER::FEMALE, Height(5, 6), Birthday(10, 27, 2002));
	Person* Kyle = new Person("Kyle", "Benjamin", "Yoder", GENDER::MALE, Height(5, 7), Birthday(7, 12, 2004));
	Person* Elizabeth = new Person("Elizabeth", "Anne", "Hondel", GENDER::FEMALE, Height(5, 2), Birthday(11, 15, 2004));
	Pet* Daisy = new PetDog("Daisy", "German Shepard");
	
	Person* Emily = new Person("Emily", "Yoder", GENDER::FEMALE, Height(5, 1), Birthday(10, 10, 2007));
	Person* Jordan = new Person("Jordan", "Yoder", GENDER::MALE, Height(4, 9), Birthday(5, 27, 2010));
	Pet* Luna = new PetDog("Luna", "Mini Ausie");

	Person* Regina = new Person("Regina", "Yoder", GENDER::FEMALE, Height(5, 7), Birthday(11, 27, 1960));
	Person* Ernest = new Person("Ernest", "W.", "Yoder", GENDER::MALE, Height(5, 7), Birthday(11, 20, 1970));

	PeopleOperations::Marry(*Ernest, *Regina);

	PeopleOperations::HaveChild(*Ernest, *Regina, *Jeffery);
	PeopleOperations::HaveChild(*Ernest, *Regina, *Jared);
	PeopleOperations::HaveChild(*Ernest, *Regina, *Kendall);
	PeopleOperations::HaveChild(*Ernest, *Regina, *Krista);
	PeopleOperations::HaveChild(*Ernest, *Regina, *Lindsey);
	PeopleOperations::HaveChild(*Ernest, *Regina, *Kyle);
	PeopleOperations::HaveChild(*Ernest, *Regina, *Emily);
	PeopleOperations::HaveChild(*Ernest, *Regina, *Jordan);

	PeopleOperations::Marry(*Jeffery, *Elisabeth);

	Kyle->AddKnownPerson("Bestfriend", *Elizabeth);
	Kyle->AddSpecialDate("I Met Elizabeth", Date(3, 29, 2021));
	PeopleOperations::AdoptPet(*Kyle, *Daisy);
	PeopleOperations::AdoptPet(*Jordan, *Luna);

	PeopleOperations::Marry(*Kendall, *Emilie);

	PeopleOperations::Kill(*Kyle, Date(1, 13, 2020), "I am going to haunt you as a ghost");

	Ernest->PrintFamilyTree();

	std::cin.get();

}