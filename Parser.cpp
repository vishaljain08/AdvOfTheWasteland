#include "Parser.h"

void Parser::Read()
{
	Write(">>");
	std::cin >> std::ws; //ignore buffers such as whitespace or newline before string https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/
	std::getline(std::cin, player_input);
	std::transform(player_input.begin(), player_input.end(), player_input.begin(), ::tolower);
}

void Parser::ReadRaw()
{
	Write(">>");	
	std::cin >> std::ws; //flushing the input buffer help taken from https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/
	std::getline(std::cin, player_input);
}

void Parser::Choice()
{
	Write("Enter the corresponding number/choice");
	Write(">>");
	std::cin >> std::ws;
	std::cin >> choice;
}

int Parser::Parse()
{
	if (player_input == "quit" || player_input == "q") return 0;

	if (player_input == "go north" || player_input == "north" || player_input == "go n" || player_input == "n") return 1;

	if (player_input == "go south" || player_input == "south" || player_input == "go s" || player_input == "s") return 2;

	if (player_input == "go west" || player_input == "west" || player_input == "go w" || player_input == "w") return 3;

	if (player_input == "go east" || player_input == "east" || player_input == "go e" || player_input == "e") return 4;

	if (player_input == "go north-west" || player_input == "north-west" || player_input == "go nw" || player_input == "nw") return 5;

	if (player_input == "go north-east" || player_input == "north-east" || player_input == "go ne" || player_input == "ne") return 6;

	if (player_input == "go south-west" || player_input == "south-west" || player_input == "go sw" || player_input == "sw") return 7;

	if (player_input == "go south-east" || player_input == "south-east" || player_input == "go se" || player_input == "se") return 8;

	if (player_input == "help" || player_input == "h") return 9;

	if (player_input == "inventory" || player_input == "inv") return 10;

	if (player_input == "drop" || player_input == "dr") return 11;

	if (player_input == "equip" || player_input == "eq") return 12;

	if (player_input == "heal") return 13;

	if (player_input == "status" || player_input == "stats") return 14;

	if (player_input == "fight boss" || player_input == "fb") return 15;
	
	if (player_input == "visit chief" || player_input == "vc") return 16;
	
	if (player_input == "visit shop" || player_input == "vs") return 17;

	return 999;
}

bool Parser::YesNo()
{
	std::cin >> yes_no;
	std::transform(yes_no.begin(), yes_no.end(), yes_no.begin(), ::tolower);
	if (yes_no == "yes" || yes_no == "y")
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Parser::Pause()
{
	char c;
	std::cout << "\nPress 'c' and enter to continue...";
	std::cin >> std::ws;
	std::cin >> c;
}

std::string Parser::getInput()
{
	return player_input;
}

int Parser::getChoice()
{
	return choice;
}