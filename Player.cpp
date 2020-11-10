#include "Player.h"

Player::Player()
{
	setPlayerHealth(50);
	setPlayerShield(0);
}

void Player::setPlayerName(std::string newName)
{
    name = newName;
}

void Player::setPlayerHealth(int newHealth)
{
    health = newHealth;
	if (health > 50)
	{
		health = 50;
	}
}

void Player::setPlayerArmour(int newArmour)
{
	armour = newArmour;
}

void Player::setPlayerShield(int newShield)
{
    shield = newShield;
}

void Player::setCoins(int amt)
{
	coins = amt;
}

std::string Player:: getPlayerName()
{
    return name;
}

int Player::getPlayerHealth()
{
    return health;
}

int Player::getPlayerArmour()
{
	return armour;
}


int Player::getPlayerShield()
{
    return shield;
}

int Player::getCoins()
{
	return coins;
}

void Player::takesDamage(int damage)
{
	if (armour <= 0)
	{
		health -= damage;
	}
	else
	{
		armourTakesHit(damage);
	}
}

void Player::armourTakesHit(int damage)
{
	armour -= damage;
	if (this->armour < 0)
	{
		health += armour; //eg: if armour is 10 and enemy deals 20 damage, health will be reduced by remaining damage
	}
}

void Player::shieldTakesHit(int damage)
{
	shield -= damage;
	if (this->shield < 0)
	{
		armourTakesHit(-shield); //eg: if shield is 10 and enemy deals 20 damage, health will be reduced by remaining damage
		shield = 0;
	}
}

bool Player::isDead()
{
	return (this->health <= 0) ? true : false;
}