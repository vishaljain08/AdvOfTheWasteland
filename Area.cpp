#include "Area.h"

Area::Area(int areaCode)
{
	Item tempItem0;
	Item tempItem1;
	Item tempItem2;

	/*I found out that switch is more effective and requires less code than if else https://www.geeksforgeeks.org/switch-vs-else/#:~:text=A%20switch%20statement%20is%20usually,a%20set%20of%20nested%20ifs.&text=The%20compiler%20can%20do%20this,compiler%20has%20no%20such%20knowledge. */

	switch(areaCode)
	{
		case 0:
			name = "The Dumpyard";
			area = Areas::dumpyard;

			shop = true;

			tempItem0.setType("Steel Sword", ItemTypes::sword, 20, 100);
			tempItem1.setType("Leather Armour", ItemTypes::armour, 30, 100);
			tempItem2.setType("Wooden Shield", ItemTypes::shield, 20, 100);

			shopItems.add(tempItem0);
			shopItems.add(tempItem1);
			shopItems.add(tempItem2);

			north = true;
			south = false;
			west = false;
			east = false;
			north_west = true;
			north_east = true;
			south_west = false;
			south_east = false;

			chiefExists = false;

			break;

		case 1:
			name = "Plain of the Armoured Warriors";
			area = Areas::plain;
			
			shop = true;
			tempItem0.setType("Steel Sword", ItemTypes::sword, 20, 100);
			tempItem1.setType("Leather Armour", ItemTypes::armour, 30, 100);
			tempItem2.setType("Wooden Shield", ItemTypes::shield, 20, 100);

			shopItems.add(tempItem0);
			shopItems.add(tempItem1);
			shopItems.add(tempItem2);

			north = false;
			south = false;
			west = false;
			east = true;
			north_west = false;
			north_east = true;
			south_west = false;
			south_east = true;

			chiefExists = true;
			
			break;

		case 2:
			name = "Mountain of the Shieldmakers";
			area = Areas::mountain;

			shop = true;
			tempItem0.setType("Iron Sword", ItemTypes::sword, 30, 200);
			tempItem1.setType("Iron Armour", ItemTypes::armour, 50, 200);
			tempItem2.setType("Iron Shield", ItemTypes::shield, 40, 200);

			shopItems.add(tempItem0);
			shopItems.add(tempItem1);
			shopItems.add(tempItem2);

			north = false;
			south = false;
			west = true;
			east = false;
			north_west = true;
			north_east = false;
			south_west = true;
			south_east = false;

			chiefExists = true;

			break;
		
		case 3:
			name = "Valley of the Swordsmen";
			area = Areas::valley;

			shop = true;
			tempItem0.setType("Iron Sword", ItemTypes::sword, 30, 200);
			tempItem1.setType("Iron Armour", ItemTypes::armour, 50, 200);
			tempItem2.setType("Iron Shield", ItemTypes::shield, 40, 200);

			shopItems.add(tempItem0);
			shopItems.add(tempItem1);
			shopItems.add(tempItem2);

			north = true;
			south = true;
			west = false;
			east = false;
			north_west = false;
			north_east = false;
			south_west = true;
			south_east = true;

			chiefExists = true;

			break;

		case 4:
			name = "The Wasteland";
			area = Areas::wasteland;
			shop = false;

			north = false;
			south = true;
			west = false;
			east = false;
			north_west = false;
			north_east = false;
			south_west = false;
			south_east = false;

			chiefExists = false;
			bossExists = true;

			break;
	}

	Item tempItem[7];
	for (int i = 0; i < 7; i++)
	{
		tempItem[i].setType("Health Potion", ItemTypes::healthPotion, 20, 50);
		
		this->shopItems.add(tempItem[i]);
	}
}

void Area::bossDied() 
{
	this->bossDead = true;
}

void Area::playerVisitsChief()
{
	this->chiefVisited = true;
}

std::string Area::getName()
{
	return name;
}

void Area::welcomeMessage()
{
	EmptyLine();
	DashedLine();
	std::cout << "\n\t  Welcome to " << name;
	DashedLine();
}

bool Area::alreadyVisitedChief()
{
	return this->chiefVisited;
}

bool Area::hasBoss()
{
	return this->bossExists;
}

bool Area::bossIsDead()
{
	return this->bossDead;
}

bool Area::hasChief()
{
	return this->chiefExists;
}

bool Area::hasShop()
{
	return this->shop;
}

bool Area::checkDirection(std::string dir) //returns whether the direction of movement from this area is valid or not
{
	if (dir == "n") return north;
	if (dir == "s") return south;
	if (dir == "w") return west;
	if (dir == "e") return east;
	if (dir == "nw") return north_west;
	if (dir == "ne") return north_east;
	if (dir == "sw") return south_west;
	if (dir == "se") return south_east;
	return false;
}