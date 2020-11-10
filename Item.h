#pragma once

#include <iostream>

#include <string>

enum class ItemTypes
{
	none,
	sword,
	shield,
	armour,
	healthPotion
};

class Item
{
	public:
		Item();
		Item(ItemTypes type);
		Item(std::string name, ItemTypes type, int data, int price);

		void setType(ItemTypes type);
		void setType(std::string name, ItemTypes type, int data, int price);
		
		void setCurrentCapacity(int capacity);

		ItemTypes getType();
		std::string getName();
		int getCapacity();
		int getCurrentCapacity();
		int getDamage();
		int getHeal();
		int getPrice();

		Item getDuplicateObject();

		void copy(Item item);

	private:
		std::string name;
		ItemTypes type;
		int maxDamage;
		int maxCapacity;
		int currentCapacity;
		int heal;
		int price;
};

