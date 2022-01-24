#pragma once
#pragma warning(disable : 4996)


class Date
{
	
	int Month;
	int Day;
	int Year;

public:

	Date();
	Date(int Month, int Day, int Year);

private:

	int CleanMonthInput(int Month) const;
	int CleanDayInput(int Day) const;
	int CleanYearInput(int Year) const;

public:

	int GetMonth() const;
	void SetMonth(int Month);
	int GetDay() const;
	void SetDay(int Day);
	int GetYear() const;
	void SetYear(int Year);
	std::string GetDate() const;

	bool operator==(const Date& other)
	{
		if (GetDate() == other.GetDate())
		{
			return true;
		}

		return false;
	}


};

namespace CurrentDate {
	std::tm* GetCurrentDate();
	int GetCurrentMonth();
	int GetCurrentDay();
	int GetCurrentYear();
}