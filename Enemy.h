#include <iostream>
#include <string>

enum class enemyTypes
{
	dead,
	skeleton,
	zombie,
	miniBoss,
	boss
};

class Enemy
{
	public:
		Enemy();
		Enemy(enemyTypes _type);
		Enemy(enemyTypes _type, std::string _name, int _coins);

		void setType(enemyTypes _type);
		void setName(std::string _name);
		void setCoins(int amt);

		std::string getName();
		enemyTypes getType();
		int getLife();
		int getArmour();
		int getMaxDamage();
		int getCoins();

		void takesDamage(int num);

		bool isDead();


	private:
		std::string name;
		enemyTypes type;
		int maxDamage;
		int life;
		int armour;
		int coins = 0;
};