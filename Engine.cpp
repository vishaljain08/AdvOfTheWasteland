#include "Engine.h"

Engine::Engine()
{
	//Loading the areas into vectors
	currentArea = &dumpyard;
	
	/*
	Item tempItem = Item("The Sword of the dead", ItemTypes::sword, 20, 1200);
	Item tempItem1 = Item("The Armour of the gods", ItemTypes::armour, 50, 1200);
	Item tempItem2 = Item("The Shield of the mighty", ItemTypes::shield , 50, 1200);
	Item tempItem3 = Item("Health Potion", ItemTypes::healthPotion, 20, 1200);
	inventory.add(tempItem);
	inventory.add(tempItem1);
	inventory.add(tempItem2);
	inventory.add(tempItem3);*/
}

bool Engine::Execute()
{
	if (gameState == GameStates::quit_game)
	{
		return false;
	}
	
	if (gameState == GameStates::game_won)
	{
		return false;
	}

	if (gameState == GameStates::game_over)
	{
		parser.EmptyLine();
		parser.DashedLine();
		parser.Write("Game Over!!");
		parser.DashedLine();
		parser.EmptyLine();
		parser.Pause();
		return false;
	}
	
	return true;
}

void Engine::Process()
{
	parser.Read();
	switch (parser.Parse())
	{
		case 0:
			Quit();
			break;

		case 1:
			moveNorth();
			break;

		case 2:
			moveSouth();
			break;

		case 3:
			moveWest();
			break;

		case 4:
			moveEast();
			break;

		case 5:
			moveNorthWest();
			break;

		case 6:
			moveNorthEast();
			break;

		case 7:
			moveSouthWest();
			break;

		case 8:
			moveSouthEast();
			break;

		case 9:
			parser.showHelp();
			break;
		
		case 10:
			checkInventory();
			break;

		case 11:
			dropItem();
			break;

		case 12:
			equipItem();
			break;

		case 13:
			usePotion();
			break;

		case 14:
			PlayerStats();
			break;

		case 15:
			bossEncounter();
			break;

		case 16:
			visitAreaChief();
			break;

		case 17:
			visitAreaShop();
			break;

		default:
			parser.Write("Excuse me, i dont get it");
	}
}

int Engine::randomNum(int max)
{
	/*Random number geberation taken reference from http://www.cplusplus.com/reference/cstdlib/rand/ */

	srand(time(NULL));// initializing random seed
	return rand() % max + 1; //gives a random number from 1 to max
}

void Engine::Quit()
{
	parser.Write("Do you really wish to quit the game?");
	if (parser.YesNo())
	{
		gameState = GameStates::quit_game;
		parser.Write("Closing the game");
	}
}

void Engine::onboardPlayer()
{
	while(true)
	{
		parser.ReadRaw();
		parser.Write("You will be called by this name from now on, are you sure?(y/n)");
		if(parser.YesNo())
		{
			player.setPlayerName(parser.getInput());
			std::cout << "Well nice to meet you, " << player.getPlayerName() <<".";
			gameState = GameStates::playing;
			break;
		}
		parser.Write("State your name:");
	}

	parser.Write("I have given you 1000 coins! Visit the shop, buy swords and quip them");
	player.setCoins(1000);


	parser.Write("You can ask for help by just typing 'help'");
}

void Engine::refreshPlayerStats()
{
	player.setPlayerArmour(inventory.getItemCapacity(11));
	player.setPlayerShield(inventory.getItemCapacity(12));
}

//Player movement determination
void Engine::moveNorth()
{
	if(currentArea->checkDirection("n"))
	{
		randomEncounter();
		switch (currentArea->area)
		{
			case Areas::dumpyard:
				currentArea = &valley;
				if (gameState != GameStates::game_over) currentArea->welcomeMessage();
				break;

			case Areas::valley:
				currentArea = &wasteland;
				if (gameState != GameStates::game_over) currentArea->welcomeMessage();
				break;
		}
	}
	else
	{
		parser.Write("There's only a dense forest in that direction! You can't go that way.");
	}
}

void Engine::moveSouth()
{
	if (currentArea->checkDirection("s"))
	{
		randomEncounter();
		
		switch (currentArea->area)
		{
			case Areas::wasteland:
				currentArea = &valley;
				if (gameState != GameStates::game_over) currentArea->welcomeMessage();
				break;

			case Areas::valley:
				currentArea = &dumpyard;
				if (gameState != GameStates::game_over) currentArea->welcomeMessage();
				break;
		}
	}
	else
	{
		parser.Write("There's only a dense forest in that direction! You can't go that way.");
	}
}

void Engine::moveWest()
{
	if (currentArea->checkDirection("w"))
	{
		randomEncounter();
		switch (currentArea->area)
		{
			case Areas::mountain:
				currentArea = &plain;
				if (gameState != GameStates::game_over) currentArea->welcomeMessage();
				break;
		}
	}
	else
	{
		parser.Write("There's only a dense forest in that direction! You can't go that way.");
	}
}

void Engine::moveEast()
{		
	if (currentArea->checkDirection("e"))
	{
		randomEncounter();
		switch (currentArea->area)
		{
		case Areas::plain:
			currentArea = &mountain;
			if (gameState != GameStates::game_over) currentArea->welcomeMessage();
			break;
		}
	}
	else
	{
		parser.Write("There's only a dense forest in that direction! You can't go that way.");
	}
}

void Engine::moveNorthWest()
{
	if (currentArea->checkDirection("nw"))
	{
		randomEncounter();
		switch (currentArea->area)
		{
			case Areas::dumpyard:
				currentArea = &plain;
				if (gameState != GameStates::game_over) currentArea->welcomeMessage();
				break;

			case Areas::mountain:
				currentArea = &valley;
				if (gameState != GameStates::game_over) currentArea->welcomeMessage();
				break;
		}
	}
	else
	{
		parser.Write("There's only a dense forest in that direction! You can't go that way.");
	}
}

void Engine::moveNorthEast()
{
	if (currentArea->checkDirection("ne"))
	{
		randomEncounter();
		switch (currentArea->area)
		{
			case Areas::dumpyard:
				currentArea = &mountain;
				if (gameState != GameStates::game_over) currentArea->welcomeMessage();
				break;

			case Areas::plain:
				currentArea = &valley;
				if (gameState != GameStates::game_over) currentArea->welcomeMessage();
				break;
		}
	}
	else
	{
		parser.Write("There's only a dense forest in that direction! You can't go that way.");
	}
}

void Engine::moveSouthWest()
{
	if (currentArea->checkDirection("sw"))
	{
		randomEncounter();
		switch (currentArea->area)
		{
			case Areas::mountain:
				currentArea = &dumpyard;
				if (gameState != GameStates::game_over) currentArea->welcomeMessage();
				break;

			case Areas::valley:
				currentArea = &plain;
				if (gameState != GameStates::game_over) currentArea->welcomeMessage();
				break;
		}
	}
	else
	{
		parser.Write("There's only a dense forest in that direction! You can't go that way.");
	}
}

void Engine::moveSouthEast()
{
	if (currentArea->checkDirection("se"))
	{
		randomEncounter();
		switch (currentArea->area)
		{
		case Areas::plain:
			currentArea = &dumpyard;
			if (gameState != GameStates::game_over) currentArea->welcomeMessage();
			break;

		case Areas::valley:
			currentArea = &mountain;
			if (gameState != GameStates::game_over) currentArea->welcomeMessage();
			break;
		}
	}
	else
	{
		parser.Write("There's only a dense forest in that direction! You can't go that way.");
	}
}

//inventory actions
void Engine::checkInventory()
{
	parser.Write("Inventory Stats:");
	std::cout << "\n\nTotal Inventory Space: " << inventory.totalCapacity();
	std::cout << "\tLeft Inventory Space: " << inventory.totalCapacity()-inventory.used();
	inventory.check();
	inventory.equipmentCheck();
}

void Engine::dropItem()
{
	checkInventory();
	parser.Write("Select the item you want to drop");
	parser.Choice();
	inventory.remove(parser.getChoice());
}

void Engine::equipItem()
{
	checkInventory();
	parser.Write("Select the item you want to equip");
	parser.Choice();
	inventory.equip(parser.getChoice());
}

void Engine::randomEncounter()
{
	switch (randomNum(3))
	{
		case 1:
			parser.Write("You encountered a zombie horde on your way!");
			randomEnemy.setType(enemyTypes::zombie);
			randomEnemy.setCoins(50);
			currentEnemy = &randomEnemy;
			initiateFight();
			break;

		case 2:
			parser.Write("You encountered a skeleton army on your way!");
			randomEnemy.setType(enemyTypes::skeleton);
			randomEnemy.setCoins(100);
			currentEnemy = &randomEnemy;
			//std::cout << "\nInitiated fight with: " << currentEnemy->getName();
			initiateFight();
			break;

		case 3:
		default:
			parser.Write("It's your lucky day! No enemies encountered on the way!!");
			break;
	}
}

void Engine::bossEncounter()
{
	if (currentArea->hasBoss())
	{
		if (!currentArea->bossIsDead())
		{
			parser.Write("You encounter the might Thanos!\n");
			randomEnemy.setType(enemyTypes::boss);
			randomEnemy.setCoins(0);
			currentEnemy = &randomEnemy;
			initiateFight();
			if (currentEnemy->isDead())
			{
				currentArea->bossDied();
				if (currentArea->area == Areas::wasteland)
				{
					gameState = GameStates::game_won;
					parser.Write("Game Won");
				}
			}
		}
		else
		{
			parser.Write("\nYou've already killed the booss of this area!\n");
		}
	}
	else
	{
		parser.Write("\nThere's no boss in this area.\n");
	}
	
}

void Engine::initiateFight()
{
	parser.Write("You can stay and fight or choose to run away.");
	parser.Write("However if you run away, you might get hit in the back and recieve damage!");
	parser.Write("\nDo you want to stay and fight? (y/n)");
	if (parser.YesNo())
	{
		parser.Write("\nInitiated fight with: ");
		std::cout << currentEnemy->getName();

		bool playerTurn = true;

		while (!(player.isDead() || currentEnemy->isDead()))
		{
			fightStats();
			if (playerTurn)
			{
				parser.DashedLine();
				parser.Write("Your Turn:");
				parser.DashedLine();

				parser.Write("1. Attack");
				parser.Write("2. Block enemy's attack (Shield takes damage)");
				parser.Write("3. Use potion (Increases health)");
				
				parser.Choice();
				switch (parser.getChoice())
				{
					case 1:
						playerAttack();
						playerTurn = false;
						break;

					case 2:
						playerBlock();
						playerTurn = true;
						break;

					case 3:
						playerTurn = false;
						if (!usePotion()) playerTurn=true;
						break;

					default:
						parser.Write("Invalid Choice");
						playerTurn = true;
						break;
				}
			}
			else
			{
				parser.DashedLine();
				parser.Write("Enemy's Turn:");
				parser.DashedLine();

				enemyAttack();
				playerTurn = true;
			}
			parser.DashedLine();
			parser.Pause();
		}
	}
	else
	{
		parser.Write("You chose to run away...");
		switch(randomNum(3))
		{
			case 1:
				player.takesDamage(10);
				std::cout << std::endl << "You took 10 damage!" << std::endl;
				break;

			case 2:
				player.takesDamage(20);
				std::cout << std::endl << "You took 20 damage!" << std::endl;
				break;

			case 3:
			default:
				parser.Write("You luckily managed to escape unharmed!");
				break;
		}
	}
	parser.EmptyLine();
	parser.DashedLine();

	if (currentEnemy->isDead())
	{
		parser.Write("The enemy is dead!");
		parser.EmptyLine();
		std::cout << "You got " << currentEnemy->getCoins() << " coins from the enemy";

		int amt;
		amt = player.getCoins() + currentEnemy->getCoins();

		player.setCoins(amt);
	}

	if (player.isDead())
	{
		parser.Write("You are dead!");
		gameState = GameStates::game_over;
	}

	parser.DashedLine();
}

void Engine::fightStats()
{
	parser.EmptyLine();

	std::cout << "\nPlayer Stats: \t\t\t Enemy Stats:";
	std::cout << "\n============= \t\t\t ============";
	refreshPlayerStats();
	std::cout << "\n"<< player.getPlayerName() << "    \t\t\t" << currentEnemy->getName();
	std::cout << "\nLife:    " << player.getPlayerHealth() << "\t\t\t Life:   " << currentEnemy->getLife();
	std::cout << "\nPotions: " << inventory.getHealthPotionCount() << "\t\t\t Armour: " << currentEnemy->getArmour();
	std::cout << "\nArmour:  " << player.getPlayerArmour() << "\t\t\t Coins: " << currentEnemy->getCoins();
	std::cout << "\nShield:  " << player.getPlayerShield();
	std::cout << "\nCoins:   " << player.getCoins();
	std::cout << "\nSword Damage: " << inventory.getItemDamage(10);//Get damage of equipped sword

	parser.EmptyLine();
}

inline void Engine::playerAttack()
{
	parser.DashedLine();
	int damage = inventory.getItemDamage(10);
	switch (randomNum(3))
	{
		case 1:
			currentEnemy->takesDamage(damage);
			std::cout << std::endl << "You dealt " << damage << " damage to the enemy!!";
			break;

		case 2:
			currentEnemy->takesDamage((damage/2));
			std::cout << std::endl << "You dealt " << damage/2 << " damage to the enemy!!";
			break;
		
		default:
			parser.Write("Alas! The enemy did not take any damage!!");
			break;
	}
}

inline void Engine::playerBlock()
{
	parser.DashedLine();
	int dmg = enemyDamage();
	if (dmg != 0 )
	{

		int capacity; 
		capacity = player.getPlayerShield() - dmg;

		capacity = (capacity < 0) ? 0 : capacity; //if the shield or armour capacity is negative , make it zero

		player.shieldTakesHit(dmg);
		inventory.setItemCapacity(12, capacity);

		if (player.getPlayerShield() == 0) // If shield is zero, armour takes the damage
		{
			if (player.getPlayerArmour() < 0) // If armour is depleted and negative, then make it as 0 instead of a negative number
			{
				inventory.setItemCapacity(11, 0);
			}
			else
			{
				inventory.setItemCapacity(11, player.getPlayerArmour());
			}
		}
	}
}

inline bool Engine::usePotion()
{
	parser.DashedLine();
	if (inventory.getHealthPotionCount() == 0)
	{
		parser.Write("You don't have any potions to use!");
		return false;
	}
	else
	{
		if (player.getPlayerHealth() < 50)
		{
			int potion = inventory.useHealthPotion();

			int health = player.getPlayerHealth() + potion;
			player.setPlayerHealth(health);
			std::cout << "\nHealth Restored by " << potion;
		}
		else
		{
			parser.Write("Your Health is already full");
			return false;
		}
	}
	return true;
}

inline void Engine::enemyAttack()
{
	parser.DashedLine();
	int dmg = enemyDamage();
	if (dmg != 0)
	{
		int capacity;
		capacity = player.getPlayerArmour() - dmg;

		capacity = (capacity < 0) ? 0 : capacity; //if the shield or armour capacity is negative , make it zero

		player.armourTakesHit(dmg);
		inventory.setItemCapacity(11, capacity);
	}
}

int Engine::enemyDamage()
{
	int	damage = currentEnemy->getMaxDamage();

	switch (randomNum(3))
	{
		case 1:
			std::cout << std::endl << "You took " << damage << " damage from the enemy!!";
			break;

		case 2:
			damage = damage/2;
			std::cout << std::endl << "You took " << damage << " damage from the enemy!!";
			break;

		default:
			damage = 0;
			parser.Write("You did not take any damage!!");
			break;
	}

	return damage;
}

void Engine::visitAreaChief()
{
	if (currentArea->hasChief())
	{
		if (!currentArea->alreadyVisitedChief())
		{
			parser.DashedLine();
			parser.Write("\t\t\tVillage Chief:");
			parser.DashedLine();
			parser.EmptyLine();
			parser.Write("Hello Traveller!");
			parser.Write("So you're the one who is destined to finish Thanos, the prophecy will be fulfilled.");


			Item tempItem;
			switch (currentArea->area)
			{
				case Areas::plain:
					parser.EmptyLine();
					parser.Write("I suggest that you obtain the Legendary Shield which is East from here and the Legendary sword which lies to the North-East from here.");
					parser.EmptyLine();
					parser.Write("I would like to give you this Ledendary Armour worn by the White Knight!");
					parser.Write("This will help you take hits of the Thanos safely.");
					tempItem.setType("Armour of White Knight", ItemTypes::armour, 100, 10000);
									  
					break;

				case Areas::mountain:
					parser.EmptyLine();
					parser.Write("I suggest that you obtain the Legendary Armour which is West from here and the Legendary sword which lies to the North-West from here.");
					parser.EmptyLine();
					parser.Write("I would like to give you this Ledendary Shield known as Shield of Heavenly Spirits!");
					parser.Write("It is said that the spirit of our fallen ancestors provide protection to the shield holder...");
					parser.Write("This will help you block hits from the Thanos.");
					tempItem.setType("Shield of Heavenly Spirits", ItemTypes::shield, 100, 10000);
					break;

				case Areas::valley:
					parser.EmptyLine();
					parser.Write("I suggest that you obtain the Legendary Shield which is South-East from here and the Legendary shield which lies to the South-east");
					parser.Write("But if you have them already, proceed to the north from here to get to Thanos!");
					parser.EmptyLine();
					parser.Write("I would like to give you this Ledendary Sword known as the Sword of Azeroth!");
					parser.Write("This will help you block hits from the Thanos.");
					tempItem.setType("Sword of Mighty Azeroth", ItemTypes::sword, 50, 10000);
					break;

				default:
					break;
			}
			
			if(inventory.isFull())
			{
				parser.Write("Seems like your inventory is full traveler.");
				parser.Write("Please sacrifice an item and recieve my offering!");
				dropItem();
			}

			inventory.add(tempItem);
			currentArea->playerVisitsChief();
			parser.Write("Please go to your inventory and equip it afterwards.");
		}
		else
		{
			parser.Write("You have already visited the chief of this area!");
		}
	}
	else
	{
		parser.Write("There's no chief of this area!");
	}
}

void Engine::visitAreaShop()
{
	if (currentArea->hasShop())
	{
		parser.DashedLine();
		parser.Write("\t\t\tShop");
		parser.DashedLine();

		

		parser.EmptyLine();
		currentArea->shopItems.check();
		parser.EmptyLine();

		std::cout << "Player Coins: " << player.getCoins();

		parser.EmptyLine();
		parser.Write("Choose the Item You Want to Buy:");
		parser.Write(" (Choose 0 to exit shop)");
		parser.Choice();
		if (!inventory.isFull())
		{
			int choice = parser.getChoice();

			if (choice <= 0)
			{
				parser.EmptyLine();
				parser.Write("Exiting Shop without buying anything.");
				parser.EmptyLine();
			}
			else if (choice <= 10)
			{
				Item a;
				a.copy(currentArea->shopItems.getItem(choice));
				if (player.getCoins() >= a.getPrice())
				{
					inventory.add(a);
					currentArea->shopItems.remove(choice);
					parser.DashedLine();
					parser.Write("Bought ");
					std::cout << a.getName();
					parser.DashedLine();

					player.setCoins(player.getCoins() - a.getPrice());
				}
				else
				{
					parser.Write("\nYou Don't Have Enough Money!!\n");
				}
			}
			else
			{
				parser.Write("Invalid Choice");
			}
		}
		else
		{
			parser.Write("Free up your inventory first!");
		}

	}
	else
	{
		parser.Write("This area doesn't have a shop");
	}
}

void Engine::PlayerStats()
{
	refreshPlayerStats();
	parser.DashedLine();
	parser.Write("\t\tPlayer Stats");
	parser.DashedLine();
	
	parser.EmptyLine();
	std::cout << "Name:         " << player.getPlayerName() << std::endl;
	std::cout << "Life:         " << player.getPlayerHealth() << std::endl;
	std::cout << "Coins:        " << player.getCoins() << std::endl;

	std::cout << "Armour:       " << player.getPlayerArmour() << std::endl;
	std::cout << "Shield:       " << player.getPlayerShield() << std::endl;
	std::cout << "Sword Damage: " << inventory.getItemDamage(10) << std::endl;
	std::cout << "Potions:      " << inventory.getHealthPotionCount() << std::endl;
}