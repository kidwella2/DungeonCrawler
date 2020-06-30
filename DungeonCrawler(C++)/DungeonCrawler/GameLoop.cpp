
/* Name: Austin Kidwell
Date: 6/26/20
Program Name: Dungeon Crawler

Description: The program starts by getting the getting the player's
name followed by the dungeon size. Magic spells and potions are 
determined by the dungeon size. There is one battle per room and the 
creatures are randomly spawned in each room. The player's turn is before 
the creatures and the player get to select from player options to 
determine an action. The choices are sword attack, bow attack, magic 
attack, use potion, and quit. The game goes until the dungeon is cleared,
the player dies, or the player quits. A few creatures have abilities that 
make them harder to beat.
*/

#include "GameLoop.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
//Battle object global so potions and battles are together
Battle battle;

void Game::RunGame()
{
    //Set player name
    SetPlayerName();

    //Set dungeon size
    SetDungeonRooms();

    //Loop through game rounds until someone wins
    GameRounds();
}

//Function for setting player name
void Game::SetPlayerName()
{
    string name;
    cout << endl << "Enter the hero's name: " << endl;
    cin >> name;
    m_player.SetName(name);
}

//Function for setting dungeon size
void Game::SetDungeonRooms()
{
    char size = ' ';
    while (size != 's' && size != 'm' && size != 'l') {
        cout << endl << "Small is 4 rooms, medium is 7 rooms, large is 10 rooms" << endl;
        cout << "What size dungeon would you like to enter (s/m/l): " << endl;
        cin >> size;
        if (size == 's') {
            m_player.SetDungeonSize(4);
            battle.TotalSpells(1);
            battle.TotalPotion(1);
        }
        else if (size == 'm') {
            m_player.SetDungeonSize(7);
            battle.TotalSpells(3);
            battle.TotalPotion(2);
        }
        else if (size == 'l') {
            m_player.SetDungeonSize(10);
            battle.TotalSpells(6);
            battle.TotalPotion(4);
        }
    }
}

//Function for game rounds
void Game::GameRounds()
{
    int currentRoom = 1;
    bool gameOver = false;

    //Loop through player turns until someone wins
    while (!gameOver) {
        if (currentRoom <= m_player.GetDungeonSize()) {
            cout << endl << "Entering dungeon room " << currentRoom << " of " << m_player.GetDungeonSize() << endl;
            m_player.SetHealth(battle.RoomBattle(m_player.GetName(), m_player.GetHealth()));
            ++currentRoom;
            if (m_player.GetHealth() <= 0) {
                gameOver = true;
            }
        }
        else {
            cout << endl << "Congratulation on clearing the dungeon!" << endl;
            cout << endl << m_player.GetName() << " survived with " << m_player.GetHealth() << " health!" << endl;
            gameOver = true;
        }
    }
}