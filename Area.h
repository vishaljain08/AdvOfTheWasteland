#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Inventory.h"

enum class Areas
{
	dumpyard,
	plain,
	valley,
	mountain,
	wasteland
};

class Area : public Screen
{
	public:
		Area(int areaCode);

		void bossDied(); //sets the boss as dead
		void playerVisitsChief(); //sets true if chief has been visited once by player

		std::string getName();
		bool checkDirection(std::string dir);
		bool hasBoss(); // checks if area has boss or not
		bool bossIsDead(); //check if the Area's boss is dead or not
		bool alreadyVisitedChief(); //checks whether player has visited the chief before or not
		bool hasChief();
		bool hasShop();

		void welcomeMessage();
		

		Areas area; //The area type variable which determines area

		Inventory shopItems;

	private:
		std::string name;
	
		//directions
		bool north;
		bool south;
		bool west;
		bool east;
		bool north_west;
		bool north_east;
		bool south_west;
		bool south_east;

		//indicators for player gameplay
		bool chiefExists;
		bool chiefVisited  = false;
		bool bossExists = false;
		bool bossDead = false;
		bool shop;
};

