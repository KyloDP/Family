#pragma once
#include "Header.h"
#include "Date.h"

class Birthday : public Date
{

public:

	Birthday();
	Birthday(int Month, int Day, int Year);

private:

	int CleanBirthdayYearInput(int Year) const;

public:

	float GetAge() const;

	bool operator==(const Birthday& other)
	{
		if (GetDate() == other.GetDate())
		{
			return true;
		}

		return false;
	}

};
