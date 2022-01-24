#include "Death.h"

Dead::Dead()
	:b_IsDead(false), DeathDate(Date()), LastWords("Unknown")
{}

Dead::Dead(bool b_IsDead)
	: b_IsDead(b_IsDead), DeathDate(Date()), LastWords("Unknown")
{}

Dead::Dead(bool b_IsDead, Date DeathDate)
	: b_IsDead(b_IsDead), DeathDate(DeathDate), LastWords("Unknown")
{}

Dead::Dead(bool b_IsDead, std::string LastWords)
	: b_IsDead(b_IsDead), DeathDate(Date()), LastWords(LastWords)
{}

Dead::Dead(bool b_IsDead, Date DeathDate, std::string LastWords)
	: b_IsDead(b_IsDead), DeathDate(DeathDate), LastWords(LastWords)
{}

bool Dead::IsDead() const
{
	return b_IsDead;
}

void Dead::Kill()
{
	b_IsDead = true;
}

Date Dead::GetDeathDate() const
{
	if (IsDead())
		return DeathDate;

	return Date();
}

void Dead::SetDeathDate(Date DeathDate)
{
	if (IsDead())
		this->DeathDate = DeathDate;
}

std::string Dead::GetLastWords() const
{
	if (IsDead())
		return LastWords;

	return "I'm Not Dead!";
}

void Dead::SetLastWords(std::string LastWords)
{
	if (IsDead())
		this->LastWords = LastWords;
}