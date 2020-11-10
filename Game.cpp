#include "Game.h"

void Game::WelcomeScreen()
{
	std::cout << "=============================================" << std::endl;
	std::cout << "\tAdventures of the Wasteland" << std::endl;
	std::cout << "=============================================" << std::endl;
	std::cout << "\nYou wake up in an unfamiliar room. You look around and see a middle aged man who looks like a wizard. \n";
	std::cout << "\"Oh! You're finally awake!\" exclaimed the wizard.\n\n";
	std::cout << "\n\"Tell me your name stranger\" asks the wizard.";
}

void Game::Run()
{
	while(game_engine.Execute())
	{
		if (game_engine.gameState == GameStates::onboarding)
		{
			WelcomeScreen();
			game_engine.onboardPlayer();
		}

		game_engine.Process();
	}
}