#pragma once

#include <string>

class Creature
{
private:
	std::string n_name;
	int n_health = 1;
	int n_attackMin = 0;
	int n_attackVariance = 0;
	int n_ability = 0;

public:
	Creature()
	{
	}

	//Getter and setter method for creature name
	void SetName(const std::string& name)
	{
		n_name = name;
	}

	const std::string& GetName() const
	{
		return n_name;
	}

	//Getter and setter fuction for creature health
	void SetHealth(const int health)
	{
		n_health = health;
	}

	const int GetHealth() const
	{
		return n_health;
	}

	//Setter fuction for creature attack
	void SetAttack(const int attackMin, const int attackVar)
	{
		n_attackMin = attackMin;
		n_attackVariance = attackVar;
	}

	//Use for creature attack
	int UseAttack()
	{
		//Generate random numbers using the current time
		srand(time(NULL));
		
		return ((rand() % n_attackVariance) + n_attackMin);
	}

	//Getter and setter fuction for creature ability
	void SetAbility(const int ability)
	{
		n_ability = ability;
	}

	const int GetAbility() const
	{
		return n_ability;
	}
};