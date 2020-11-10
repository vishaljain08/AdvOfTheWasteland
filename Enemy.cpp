#include "Enemy.h"

Enemy::Enemy()
{
	setType(enemyTypes::dead);
}

Enemy::Enemy(enemyTypes _type)
{
	setType(_type);
}

Enemy::Enemy(enemyTypes _type, std::string _name, int _coins)
{
	setType(_type);
	setName(_name);
	setCoins(_coins);
}

void Enemy::setType(enemyTypes _type)
{
	this->type = _type;
	switch (_type)
	{
		case enemyTypes::dead:
			this->name = "Dead Enemy";
			this->life = 0;
			this->armour = 0;
			this->maxDamage = 0;
			break;

		case enemyTypes::skeleton:
			this->name = "Skeleton Army";
			this->life = 50;
			this->armour = 50;
			this->maxDamage = 20;
			break;

		case enemyTypes::zombie:
			this->name = "Zombie Horde";
			this->life = 50;
			this->armour = 0;
			this->maxDamage = 10;
			break;

		case enemyTypes::miniBoss:
			this->name = "Unnamed Mini Boss";
			this->life = 100;
			this->armour = 50;
			this->maxDamage = 20;
			break;

		case enemyTypes::boss:
			this->name = "Thanos";
			this->life = 10;
			this->armour = 0;
			this->maxDamage = 40;
			break;

		default:
			this->name = "Unknown Enemy";
			this->life = 10;
			this->armour = 0;
			this->maxDamage = 0;
			break;
	}
}

void Enemy::setName(std::string _name)
{
	this->name = _name;
}

void Enemy::setCoins(int amt)
{
	this->coins = amt;
}

std::string Enemy::getName()
{
	return this->name;
}

enemyTypes Enemy::getType()
{
	return this->type;
}

int Enemy::getLife()
{
	return this->life;
}

int Enemy::getArmour()
{
	return this->armour;
}

int Enemy::getMaxDamage()
{
	return this->maxDamage;
}

int Enemy::getCoins() 
{
	return this->coins;
}

void Enemy::takesDamage(int num)
{
	if (armour <= 0)
	{
		this->life -= num;
		if (life < 0) this->life = 0;
	}
	else
	{
		this->armour -= num;
		if (armour < 0)
		{
			this->life += armour;//eg: If armour = 10 and damage is 20, then reduce remaining damage from life
			this->armour = 0;
		}
	}
}

bool Enemy::isDead()
{
	return (this->life <= 0) ? true : false;
}