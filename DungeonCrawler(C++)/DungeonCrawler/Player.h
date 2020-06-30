#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

class Player
{
private:
	std::string m_name;
	int m_health = 1;
	int m_dungeonSize = 1;
	int m_potion = 0;
	int m_spells = 0;

public:
	Player()
	{
	}

	//Getter and setter method for player name
	void SetName(const std::string& name)
	{
		m_name = name;
		SetHealth(50);
	}

	const std::string& GetName() const
	{
		return m_name;
	}

	//Getter and setter fuction for player health
	void SetHealth(const int health)
	{
		m_health = health;
	}

	const int GetHealth() const
	{
		return m_health;
	}

	//Getter and setter fuction for dungeon size
	void SetDungeonSize(const int size)
	{
		m_dungeonSize = size;
	}

	const int GetDungeonSize() const
	{
		return m_dungeonSize;
	}

	//Getter and setter fuction for potions
	void SetPotion(const int potion)
	{
		m_potion = potion;
	}

	const int GetPotion() const
	{
		return m_potion;
	}

	//Function to use potion (heal 20 health)
	void UsePotion()
	{
		if (m_potion > 0) {
			if (GetHealth() > 30) {
				SetHealth(50);
				--m_potion;
			}
			else {
				SetHealth(GetHealth() + 20);
				--m_potion;
			}
			
		}
	}

	//Used to get sword attack
	int UseSword()
	{
		//Generate random numbers using the current time
		srand(time(NULL));
		//attack 7-11
		return ((rand() % 5) + 7);
	}

	//Used to get bow attack
	int UseBow()
	{
		//Generate random numbers using the current time
		srand(time(NULL));
		//attack 2-15
		return ((rand() % 14) + 2);
	}

	//Used to get magic attack
	int UseMagic()
	{
		//Generate random numbers using the current time
		srand(time(NULL));
		//attack 8-19
		return ((rand() % 12) + 8);
	}

	//Getter and setter fuction for magic spells
	void SetSpells(const int spells)
	{
		m_spells = spells;
	}

	const int GetSpells() const
	{
		return m_spells;
	}

	//Function to use magic spell
	void UseSpells()
	{
		if (m_spells > 0) {
			--m_spells;
		}
	}
};