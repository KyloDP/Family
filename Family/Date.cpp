#include "Header.h"
#include "Date.h"

Date::Date()
	: Month(-1), Day(-1), Year(-1)
{}

Date::Date(int Month, int Day, int Year)
	: Month(CleanMonthInput(Month)), Day(CleanDayInput(Day)), Year(CleanYearInput(Year))
{}

int Date::CleanMonthInput(int Month) const
{

	if ((Month < 13 && Month > 0) || Month == -1)
	{
		return Month;
	}
	else {
		throw std::invalid_argument("0 < Month < 13 | -1 Is Unknown... " + std::to_string(Month) + " Is Invlaid!");
		return -1;
	}
}

int Date::CleanDayInput(int Day) const
{
	std::map<int, int> NumberOfDaysInMonth;

	NumberOfDaysInMonth[-1] = 31;
	NumberOfDaysInMonth[1] = 31;
	NumberOfDaysInMonth[2] = 28;
	NumberOfDaysInMonth[3] = 31;
	NumberOfDaysInMonth[4] = 30;
	NumberOfDaysInMonth[5] = 31;
	NumberOfDaysInMonth[6] = 30;
	NumberOfDaysInMonth[7] = 31;
	NumberOfDaysInMonth[8] = 31;
	NumberOfDaysInMonth[9] = 30;
	NumberOfDaysInMonth[10] = 31;
	NumberOfDaysInMonth[11] = 30;
	NumberOfDaysInMonth[12] = 31;

	if ((Day < NumberOfDaysInMonth[GetMonth()] && Day > 0) || Day == -1)
	{
		return Day;
	}
	else {
		throw std::invalid_argument("0 < Day < " + std::to_string(NumberOfDaysInMonth[GetMonth()]) + " | -1 Is Unknown... " + std::to_string(Day) + " Is Invlaid!");
		return -1;
	}

}

int Date::CleanYearInput(int Year) const
{
	if (Year > 0 || Year == -1)
	{
		return Year;
	}
	else {
		throw std::invalid_argument("0 < Year | -1 Is Unknown... " + std::to_string(Year) + " Is Invlaid!");
		return -1;
	}
}

int Date::GetMonth() const
{
	return Month;
}

void Date::SetMonth(int Month)
{
	this->Month = CleanMonthInput(Month);
}

int Date::GetDay() const
{
	return Day;
}

void Date::SetDay(int Day)
{
	this->Day = CleanDayInput(Day);
}

int Date::GetYear() const
{
	return Year;
}

void Date::SetYear(int Year)
{
	this->Year = CleanYearInput(Year);
}

std::string Date::GetDate() const
{
	std::string s_Month;
	std::string s_Day;
	std::string s_Year;

	if (Month != -1)
	{
		s_Month = std::to_string(Month);
	}
	else {
		s_Month = "Unknown";
	}

	if (Day != -1)
	{
		s_Day = std::to_string(Day);
	}
	else {
		s_Day = "Unknown";
	}

	if (Year != -1)
	{
		s_Year = std::to_string(Year);
	}
	else {
		s_Year = "Unknown";
	}

	return s_Month + "/" + s_Day + "/" + s_Year;
}

std::tm* CurrentDate::GetCurrentDate()
{
	std::time_t time = std::time(0);
	std::tm* now = std::localtime(&time);

	return now;
}

int CurrentDate::GetCurrentMonth()
{
	return (GetCurrentDate()->tm_mon + 1);
}

int CurrentDate::GetCurrentDay()
{
	return (GetCurrentDate()->tm_mday);
}

int CurrentDate::GetCurrentYear()
{
	return (GetCurrentDate()->tm_year + 1900);
}