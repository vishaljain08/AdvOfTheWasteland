#pragma once

#include <iostream>
#include <cstdlib>
#include <time.h>

#include "Parser.h"
#include "Player.h"
#include "Enemy.h"
//#include "Inventory.h"
#include "Area.h"


enum class GameStates
{
	onboarding,
	playing,
	quit_game,
	game_over,
	game_won
};

class Engine 
{
	public:
		Engine();

		GameStates gameState = GameStates::onboarding;
		bool Execute();
		void Process();

		int randomNum(int max); //function to return random number from 1 to specified number

		void Quit();
		void onboardPlayer();

		void refreshPlayerStats();

		void PlayerStats();

		//player movements
		void moveNorth();
		void moveSouth();
		void moveWest();
		void moveEast();
		void moveNorthWest();
		void moveNorthEast();
		void moveSouthWest();
		void moveSouthEast();
		
		//inventory actions
		void checkInventory();
		void dropItem();
		void equipItem();

		//Fight functions
		void randomEncounter(); //Fights when moving from one area to another
		void initiateFight(); //initiate Fight function
		void bossEncounter();
		void fightStats(); //Display fight info on screen

		inline void playerAttack();
		inline void playerBlock();
		inline bool usePotion(); // uses potion if available returns false if no potion available
	
		inline void enemyAttack();

		int enemyDamage();//Return random damage given by enemy

		//Area actions
		void visitAreaChief();
		void visitAreaShop();

	private:
		Parser parser;
		Player player;

		Enemy randomEnemy;
		Enemy *currentEnemy;

		Inventory inventory;

		//Areas
		Area dumpyard = Area(0);
		Area plain = Area(1);
		Area mountain = Area(2);
		Area valley = Area(3);
		Area wasteland = Area(4);

		Area *currentArea; //points to the area we currently are in
};

