#include "Item.h"

Item::Item()
{
	this->type = ItemTypes::none;
	this->name = "Unnamed Item";
	this->maxCapacity = 0;
	this->currentCapacity = 0;
	this->maxDamage = 0;
	this->heal = 0;
	this->price = 0;
}

Item::Item(ItemTypes type)
{
	setType(type);
}

Item::Item(std::string name, ItemTypes type, int data, int price)
{
	setType(name, type, data, price);
}

void Item::setType(ItemTypes type)
{
	this->name = "Empty Space";
	this->type = type;
	this->maxCapacity = 0;
	this->currentCapacity = 0;
	this->maxDamage = 0;
	this->heal = 0;
	this->price = 0;
}

void Item::setType(std::string name, ItemTypes type, int data, int price)
{
	this->name = name;
	this->type = type;
	this->price = price;
	//std::cout<<("\nDebug: Item created: ");
	//std::cout << "Name:" << this->name << " Price:" << this->price;
	switch (type)
	{
		case ItemTypes::sword:
			this->maxDamage = data;
			break;

		case ItemTypes::shield:
			this->maxCapacity = data;
			this->currentCapacity = this->maxCapacity;
			break;

		case ItemTypes::armour:
			this->maxCapacity = data;
			this->currentCapacity = this->maxCapacity;
			break;

		case ItemTypes::healthPotion:
			this->heal = data;
			break;

		default:
			this->maxCapacity = 0;
			this->maxDamage = 0;
			this->heal = 0;
			break;
	}
}

void Item::setCurrentCapacity(int capacity)
{
	this->currentCapacity = capacity;
}

ItemTypes Item::getType()
{
	return this->type;
}

std::string Item::getName()
{
	return this->name;

}

int Item::getCapacity()
{
	return this->maxCapacity;
}

int Item::getCurrentCapacity()
{
	return this->currentCapacity;
}

int Item::getDamage()
{
	return this->maxDamage;
}

int Item::getHeal()
{
	return this->heal;
}

int Item::getPrice()
{
	return this->price;
}

Item Item::getDuplicateObject()
{
	Item duplicate;

	switch (this->type)
	{
		case ItemTypes::sword:
			duplicate.setType(name, type, maxDamage, price);
			duplicate.setCurrentCapacity(currentCapacity);
			break;

		case ItemTypes::shield:
		case ItemTypes::armour:
			duplicate.setType(name, type, maxDamage, price);
			duplicate.setCurrentCapacity(currentCapacity);
			break;

		default:
			duplicate.setType(ItemTypes::none);
			break;
	}
	
	return duplicate;
}

void Item::copy(Item item)
{
	int data;
	switch (item.getType())
	{
		case ItemTypes::sword:
			data = item.getDamage();
			break;

		case ItemTypes::shield:
			data = item.getCurrentCapacity();
			break;

		case ItemTypes::armour:
			data = item.getCurrentCapacity();
			break;

		case ItemTypes::healthPotion:
			data = item.getHeal();
			break;

		default:
			data = 0;
			break;
	}

	setType(item.getName(), item.getType(), data, item.getPrice());
}