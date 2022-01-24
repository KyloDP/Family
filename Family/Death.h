#pragma once
#include <string>
#include "Date.h"

class Dead {

	bool b_IsDead;
	Date DeathDate;
	std::string LastWords;

public:
	
	Dead();
	Dead(bool b_IsDead);
	Dead(bool b_IsDead, Date DeathDate);
	Dead(bool b_IsDead, std::string LastWords);
	Dead(bool b_IsDead, Date DeathDate, std::string LastWords);

	bool IsDead() const;
	void Kill();

	Date GetDeathDate() const;
	void SetDeathDate(Date DeathDate);

	std::string GetLastWords() const;
	void SetLastWords(std::string LastWords);

};