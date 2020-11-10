#pragma once

#include <vector>

#include "Screen.h"
#include "Item.h"

class Inventory : public Screen
{
	public:
		Inventory();

		void add(Item item);
		void remove(int itemNum);
		void equip(int itemNum);

		void check();
		void equipmentCheck();
		void setItemCapacity(int itemNum, int cap);
		
		bool isFull();
		int totalCapacity();
		int used();

		//functions for potions usage 
		int useHealthPotion();
		int getHealthPotionCount();

		//accessing item data
		Item getItem(int Pos);
		int getItemCapacity(int itemPos);
		int getItemDamage(int itemPos);
		/*std::string getItemName();
		;
		int getItemCapacity();*/

	public:
		int capacity = 10;
		int usedSpace = 0;
		
		/*
			Last 4 places of the vector and the array used for equipping items.
			Starting from 0, the places at 10,11,12 used for Sword, Armour and Shield
			and 13 used as a temporary storage of items during equipping function.
		*/
		std::vector<Item *> inventorySpace;
		Item item[14];

};

