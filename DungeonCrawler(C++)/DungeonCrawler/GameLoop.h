#pragma once

#include "Player.h"
#include "RoomBattle.h"

class Game
{
private:
	Player m_player;

	void SetPlayerName();
	void SetDungeonRooms();
	void GameRounds();
public:

	void RunGame();
};