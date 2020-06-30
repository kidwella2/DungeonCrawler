#include "RoomBattle.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

int Battle::RoomBattle(string name, int health)
{
	//pAtk is player attack, cAtk is creature attack
	int round = 0;
	char playerOption = ' ';
	int pAtk = 0, cAtk = 0;

	//Set player info
	m_player.SetName(name);
	m_player.SetHealth(health);

	//Spawn a creature in the room
	SpawnCreature();

	//Display hero and creature name and health
	cout << m_player.GetName() << ": Health = " << m_player.GetHealth() << "\t-Spells: " << m_player.GetSpells()
		<< "\t-Potions: " << m_player.GetPotion() << endl;
	cout << n_creature.GetName() << ": Health = " << n_creature.GetHealth() << endl;

	//Battle until player or creature dies
	while (m_player.GetHealth() > 0 && n_creature.GetHealth() > 0) {
		++round;
		cout << endl << "Round " << round << endl;
		
		//Player turn options
		GetPlayerOptions();

		//Get creature attack if creature is alive
		if (n_creature.GetHealth() > 0) {
			cAtk = n_creature.UseAttack();
			cout << n_creature.GetName() << " attacked " << m_player.GetName() << " for " << cAtk << " damage!" << endl;
			m_player.SetHealth(m_player.GetHealth() - cAtk);
		}

		cout << m_player.GetName() << ": Health = " << m_player.GetHealth() << "\t-Spells: " << m_player.GetSpells()
			<< "\t-Potions: " << m_player.GetPotion() << endl;
		cout << n_creature.GetName() << ": Health = " << n_creature.GetHealth() << endl;
	}
	if (m_player.GetHealth() <= 0) {
		cout << m_player.GetName() << " died!" << endl;
	}
	else if (n_creature.GetHealth() <= 0) {
		cout << n_creature.GetName() << " died!" << endl;
	}
	return m_player.GetHealth();
}

//Function to get spells into the room battle
void Battle::TotalSpells(int spells)
{
	m_player.SetSpells(spells);
}

//Function to get potions into the room battle
void Battle::TotalPotion(int potion)
{
	m_player.SetPotion(potion);
}

void Battle::GetPlayerOptions()
{
	//pAtk is player attack, cAtk is creature attack
	char playerOption = ' ';
	int pAtk = 0, cAtk = 0;

	//Only letter options are 's/b/m/p/q'
	while (playerOption != 's' && playerOption != 'b' && playerOption != 'm' &&
		playerOption != 'p' && playerOption != 'q') {
		//No spells and potions
		if (m_player.GetSpells() == 0 && m_player.GetPotion() == 0) {
			//Get the player to choose an option
			cout << "Choose an option: sword attack, bow attack, or quit (s/b/q)" << endl;
			cin >> playerOption;

			//Sword attack option
			if (playerOption == 's') {
				pAtk = m_player.UseSword();
				//50% chance miss for flying creatures
				if (((rand() % 2) + 0) == 0 && n_creature.GetAbility() == 1) {
					cout << n_creature.GetName() << " is flying and hard to hit!" << endl;
					cout << m_player.GetName() << " missed the attack!" << endl;
				}
				//50% reduced damage against armor creatures
				else if (n_creature.GetAbility() == 2) {
					pAtk = pAtk / 2;
					cout << n_creature.GetName() << " has armor and takes reduced damage!" << endl;
					cout << m_player.GetName() << " attacked " << n_creature.GetName() << " with a sword for " << pAtk << " damage!" << endl;
					n_creature.SetHealth(n_creature.GetHealth() - pAtk);
				}
				else {
					cout << m_player.GetName() << " attacked " << n_creature.GetName() << " with a sword for " << pAtk << " damage!" << endl;
					n_creature.SetHealth(n_creature.GetHealth() - pAtk);
				}
			}
			//Bow attack option
			else if (playerOption == 'b') {
				pAtk = m_player.UseBow();
				//50% reduced damage against armor creatures
				if (n_creature.GetAbility() == 2) {
					pAtk = pAtk / 2;
					cout << n_creature.GetName() << " has armor and takes reduced damage!" << endl;
					cout << m_player.GetName() << " attacked " << n_creature.GetName() << " with a bow for " << pAtk << " damage!" << endl;
					n_creature.SetHealth(n_creature.GetHealth() - pAtk);
				}
				else {
					cout << m_player.GetName() << " attacked " << n_creature.GetName() << " with a bow for " << pAtk << " damage!" << endl;
					n_creature.SetHealth(n_creature.GetHealth() - pAtk);
				}
			}
			//Quit option
			else if (playerOption == 'q') {
				cout << m_player.GetName() << " quit!" << endl;
				m_player.SetHealth(0);
			}
		}
		//No spells
		else if (m_player.GetSpells() == 0) {
			//Get the player to choose an option
			cout << "Choose an option: sword attack, bow attack, use potion, or quit (s/b/p/q)" << endl;
			cin >> playerOption;

			//Sword attack option
			if (playerOption == 's') {
				pAtk = m_player.UseSword();
				//50% chance miss for flying creatures
				if (((rand() % 2) + 0) == 0 && n_creature.GetAbility() == 1) {
					cout << n_creature.GetName() << " is flying and hard to hit!" << endl;
					cout << m_player.GetName() << " missed the attack!" << endl;
				}
				//50% reduced damage against armor creatures
				else if (n_creature.GetAbility() == 2) {
					pAtk = pAtk / 2;
					cout << n_creature.GetName() << " has armor and takes reduced damage!" << endl;
					cout << m_player.GetName() << " attacked " << n_creature.GetName() << " with a sword for " << pAtk << " damage!" << endl;
					n_creature.SetHealth(n_creature.GetHealth() - pAtk);
				}
				else {
					cout << m_player.GetName() << " attacked " << n_creature.GetName() << " with a sword for " << pAtk << " damage!" << endl;
					n_creature.SetHealth(n_creature.GetHealth() - pAtk);
				}
			}
			//Bow attack option
			else if (playerOption == 'b') {
				pAtk = m_player.UseBow();
				//50% reduced damage against armor creatures
				if (n_creature.GetAbility() == 2) {
					pAtk = pAtk / 2;
					cout << n_creature.GetName() << " has armor and takes reduced damage!" << endl;
					cout << m_player.GetName() << " attacked " << n_creature.GetName() << " with a bow for " << pAtk << " damage!" << endl;
					n_creature.SetHealth(n_creature.GetHealth() - pAtk);
				}
				else {
					cout << m_player.GetName() << " attacked " << n_creature.GetName() << " with a bow for " << pAtk << " damage!" << endl;
					n_creature.SetHealth(n_creature.GetHealth() - pAtk);
				}
			}
			//Use potion option
			else if (playerOption == 'p') {
				m_player.UsePotion();
				cout << m_player.GetName() << " healed with a potion!" << endl;
			}
			//Quit option
			else if (playerOption == 'q') {
				cout << m_player.GetName() << " quit!" << endl;
				m_player.SetHealth(0);
			}
		}
		//No potions
		else if (m_player.GetPotion() == 0) {
			//Get the player to choose an option
			cout << "Choose an option: sword attack, bow attack, magic attack, or quit (s/b/m/q)" << endl;
			cin >> playerOption;

			//Sword attack option
			if (playerOption == 's') {
				pAtk = m_player.UseSword();
				//50% chance miss for flying creatures
				if (((rand() % 2) + 0) == 0 && n_creature.GetAbility() == 1) {
					cout << n_creature.GetName() << " is flying and hard to hit!" << endl;
					cout << m_player.GetName() << " missed the attack!" << endl;
				}
				//50% reduced damage against armor creatures
				else if (n_creature.GetAbility() == 2) {
					pAtk = pAtk / 2;
					cout << n_creature.GetName() << " has armor and takes reduced damage!" << endl;
					cout << m_player.GetName() << " attacked " << n_creature.GetName() << " with a sword for " << pAtk << " damage!" << endl;
					n_creature.SetHealth(n_creature.GetHealth() - pAtk);
				}
				else {
					cout << m_player.GetName() << " attacked " << n_creature.GetName() << " with a sword for " << pAtk << " damage!" << endl;
					n_creature.SetHealth(n_creature.GetHealth() - pAtk);
				}
			}
			//Bow attack option
			else if (playerOption == 'b') {
				pAtk = m_player.UseBow();
				//50% reduced damage against armor creatures
				if (n_creature.GetAbility() == 2) {
					pAtk = pAtk / 2;
					cout << n_creature.GetName() << " has armor and takes reduced damage!" << endl;
					cout << m_player.GetName() << " attacked " << n_creature.GetName() << " with a bow for " << pAtk << " damage!" << endl;
					n_creature.SetHealth(n_creature.GetHealth() - pAtk);
				}
				else {
					cout << m_player.GetName() << " attacked " << n_creature.GetName() << " with a bow for " << pAtk << " damage!" << endl;
					n_creature.SetHealth(n_creature.GetHealth() - pAtk);
				}
			}
			//Magic attack option
			else if (playerOption == 'm') {
				pAtk = m_player.UseMagic();
				m_player.UseSpells();
				//50% reduced damage against magic armor creatures
				if (n_creature.GetAbility() == 3) {
					pAtk = pAtk / 2;
					cout << n_creature.GetName() << " has magic resistance and takes reduced damage!" << endl;
					cout << m_player.GetName() << " attacked " << n_creature.GetName() << " with magic for " << pAtk << " damage!" << endl;
					n_creature.SetHealth(n_creature.GetHealth() - pAtk);
				}
				else {
					cout << m_player.GetName() << " attacked " << n_creature.GetName() << " with magic for " << pAtk << " damage!" << endl;
					n_creature.SetHealth(n_creature.GetHealth() - pAtk);
				}
			}
			//Quit option
			else if (playerOption == 'q') {
				cout << m_player.GetName() << " quit!" << endl;
				m_player.SetHealth(0);
			}
		}
		//All options available
		else {
			//Get the player to choose an option
			cout << "Choose an option: sword attack, bow attack, magic attack, use potion, or quit (s/b/m/p/q)" << endl;
			cin >> playerOption;

			//Sword attack option
			if (playerOption == 's') {
				pAtk = m_player.UseSword();
				//50% chance miss for flying creatures
				if (((rand() % 2) + 0) == 0 && n_creature.GetAbility() == 1) {
					cout << n_creature.GetName() << " is flying and hard to hit!" << endl;
					cout << m_player.GetName() << " missed the attack!" << endl;
				}
				//50% reduced damage against armor creatures
				else if (n_creature.GetAbility() == 2) {
					pAtk = pAtk / 2;
					cout << n_creature.GetName() << " has armor and takes reduced damage!" << endl;
					cout << m_player.GetName() << " attacked " << n_creature.GetName() << " with a sword for " << pAtk << " damage!" << endl;
					n_creature.SetHealth(n_creature.GetHealth() - pAtk);
				}
				else {
					cout << m_player.GetName() << " attacked " << n_creature.GetName() << " with a sword for " << pAtk << " damage!" << endl;
					n_creature.SetHealth(n_creature.GetHealth() - pAtk);
				}
			}
			//Bow attack option
			else if (playerOption == 'b') {
				pAtk = m_player.UseBow();
				//50% reduced damage against armor creatures
				if (n_creature.GetAbility() == 2) {
					pAtk = pAtk / 2;
					cout << n_creature.GetName() << " has armor and takes reduced damage!" << endl;
					cout << m_player.GetName() << " attacked " << n_creature.GetName() << " with a bow for " << pAtk << " damage!" << endl;
					n_creature.SetHealth(n_creature.GetHealth() - pAtk);
				}
				else {
					cout << m_player.GetName() << " attacked " << n_creature.GetName() << " with a bow for " << pAtk << " damage!" << endl;
					n_creature.SetHealth(n_creature.GetHealth() - pAtk);
				}
			}
			//Magic attack option
			else if (playerOption == 'm') {
				pAtk = m_player.UseMagic();
				m_player.UseSpells();
				//50% reduced damage against magic armor creatures
				if (n_creature.GetAbility() == 3) {
					pAtk = pAtk / 2;
					cout << n_creature.GetName() << " has magic resistance and takes reduced damage!" << endl;
					cout << m_player.GetName() << " attacked " << n_creature.GetName() << " with magic for " << pAtk << " damage!" << endl;
					n_creature.SetHealth(n_creature.GetHealth() - pAtk);
				}
				else {
					cout << m_player.GetName() << " attacked " << n_creature.GetName() << " with magic for " << pAtk << " damage!" << endl;
					n_creature.SetHealth(n_creature.GetHealth() - pAtk);
				}
			}
			//Use potion option
			else if (playerOption == 'p') {
				m_player.UsePotion();
				cout << m_player.GetName() << " healed with a potion!" << endl;
			}
			//Quit option
			else if (playerOption == 'q') {
				cout << m_player.GetName() << " quit!" << endl;
				m_player.SetHealth(0);
			}
		}
	}
}

//Function used to spawn a creature with its respected values
void Battle::SpawnCreature() {
	//No ability
	int n, ability = 0;

	//Generate random numbers using the current time
	srand(time(NULL));

	//Set n to a random value 1-20
	n = (rand() % 20) + 1;

	//1: slime, 2: rat, 3: bat, 4: spider, 5:goblin
	//6: snake, 7: giant rat, 8: clay soldier, 9: giant spider, 10: skeleton
	//11: giant snake, 12: orc, 13: ghoul, 14: warlock, 15: wyvern
	//16: zombie, 17: stone soldier, 18: golem, 19: ogre, 20: dragon
	//flying: 3, 15, 20 (sword has half acc)
	//armor: 17, 18 (sword and bow does half dmg)
	//magic armor: 14, 19 (magic does half dmg)
	switch (n) {//choose room spawn
	case 1: n_creature.SetName("Slime");
		//health 14-18
		n_creature.SetHealth((rand() % 5) + 14);
		//attack 1-3
		n_creature.SetAttack(1, 3);
		break;
	case 2: n_creature.SetName("Rat");
		//health 15-19
		n_creature.SetHealth((rand() % 5) + 15);
		//attack 2-4
		n_creature.SetAttack(2, 3);
		break;
	case 3: n_creature.SetName("Bat");
		//health 16-20
		n_creature.SetHealth((rand() % 5) + 16);
		//attack 1-5
		n_creature.SetAttack(1, 5);
		//Flying ability
		n_creature.SetAbility(1);
		break;
	case 4: n_creature.SetName("Spider");
		//health 15-19
		n_creature.SetHealth((rand() % 5) + 15);
		//attack 2-5
		n_creature.SetAttack(2, 4);
		break;
	case 5: n_creature.SetName("Goblin");
		//health 16-21
		n_creature.SetHealth((rand() % 6) + 16);
		//attack 2-5
		n_creature.SetAttack(2, 4);
		break;
	case 6: n_creature.SetName("Snake");
		//health 15-20
		n_creature.SetHealth((rand() % 6) + 15);
		//attack 2-6
		n_creature.SetAttack(2, 5);
		break;
	case 7: n_creature.SetName("Giant Rat");
		//health 17-21
		n_creature.SetHealth((rand() % 5) + 17);
		//attack 3-5
		n_creature.SetAttack(3, 3);
		break;
	case 8: n_creature.SetName("Clay Soldier");
		//health 20-26
		n_creature.SetHealth((rand() % 7) + 20);
		//attack 1-5
		n_creature.SetAttack(1, 5);
		break;
	case 9: n_creature.SetName("Giant Spider");
		//health 18-23
		n_creature.SetHealth((rand() % 6) + 18);
		//attack 3-5
		n_creature.SetAttack(3, 3);
		break;
	case 10: n_creature.SetName("Skeleton");
		//health 19-25
		n_creature.SetHealth((rand() % 7) + 19);
		//attack 3-6
		n_creature.SetAttack(3, 4);
		break;
	case 11: n_creature.SetName("Giant Snake");
		//health 20-25
		n_creature.SetHealth((rand() % 6) + 20);
		//attack 3-7
		n_creature.SetAttack(3, 5);
		break;
	case 12: n_creature.SetName("Orc");
		//health 23-28
		n_creature.SetHealth((rand() % 6) + 23);
		//attack 3-7
		n_creature.SetAttack(3, 5);
		break;
	case 13: n_creature.SetName("Ghoul");
		//health 21-30
		n_creature.SetHealth((rand() % 10) + 21);
		//attack 1-7
		n_creature.SetAttack(1, 7);
		break;
	case 14: n_creature.SetName("Warlock");
		//health 17-22
		n_creature.SetHealth((rand() % 6) + 17);
		//attack 4-12
		n_creature.SetAttack(4, 9);
		//Magic Armor ability
		n_creature.SetAbility(3);
		break;
	case 15: n_creature.SetName("Wyvern");
		//health 19-25
		n_creature.SetHealth((rand() % 7) + 19);
		//attack 4-13
		n_creature.SetAttack(4, 10);
		//Flying ability
		n_creature.SetAbility(1);
		break;
	case 16: n_creature.SetName("Zombie");
		//health 27-32
		n_creature.SetHealth((rand() % 6) + 27);
		//attack 4-7
		n_creature.SetAttack(4, 4);
		break;
	case 17: n_creature.SetName("Stone Soldier");
		//health 22-29
		n_creature.SetHealth((rand() % 8) + 22);
		//attack 3-8
		n_creature.SetAttack(3, 6);
		//Armor ability
		n_creature.SetAbility(2);
		break;
	case 18: n_creature.SetName("Golem");
		//health 30-40
		n_creature.SetHealth((rand() % 11) + 30);
		//attack 2-6
		n_creature.SetAttack(2, 5);
		//Armor ability
		n_creature.SetAbility(2);
		break;
	case 19: n_creature.SetName("Ogre");
		//health 27-34
		n_creature.SetHealth((rand() % 8) + 27);
		//attack 4-12
		n_creature.SetAttack(4, 9);
		//Magic Armor ability
		n_creature.SetAbility(3);
		break;
	case 20: n_creature.SetName("Dragon");
		//health 35-42
		n_creature.SetHealth((rand() % 8) + 35);
		//attack 5-16
		n_creature.SetAttack(5, 12);
		//Flying ability
		n_creature.SetAbility(1);
		break;
	}
}