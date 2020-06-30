#pragma once

#include "Player.h"
#include "Creature.h"
#include "GameLoop.h"
#include <string>

class Battle
{
private:
	Player m_player;
	Creature n_creature;

	void GetPlayerOptions();
	void SpawnCreature();
public:

	void TotalSpells(int spells);
	void TotalPotion(int potion);
	int RoomBattle(std::string name, int health);
};