#include "Header.h"
#include "Birthday.h"


Birthday::Birthday()
	: Date()
{}

Birthday::Birthday(int Month, int Day, int Year)
	: Date(Month, Day, CleanBirthdayYearInput(Year))
{}

int Birthday::CleanBirthdayYearInput(int Year) const
{
	if (Year > 1899 || Year == -1)
	{
		return Year;
	}
	else {
		throw std::invalid_argument("1899 < Year | -1 Is Unknown");
		return -1;
	}
}

float Birthday::GetAge() const
{

	if (GetYear() != -1)
	{

		float YearAge = ((float)(CurrentDate::GetCurrentYear() - GetYear()));
		if (GetMonth() != -1 && GetDay() != -1)
		{
			float MonthAge = ((float)(CurrentDate::GetCurrentMonth() - GetMonth()) / (float)12);
			float DayAge = ((float)(CurrentDate::GetCurrentDay() - GetDay()) / (float)31) / (float)10;
			
			return YearAge + MonthAge + DayAge;
		}

		return YearAge;
	}

	return -1;

}