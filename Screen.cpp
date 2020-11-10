#include "Screen.h"

void Screen::Write(std::string text)
{
	std::cout << "\n"<< text;
}

void Screen::EmptyLine()
{
	Write("");
}

void Screen::DashedLine()
{
	Write("==========================================================");
}

void Screen::showHelp()
{
	std::cout << "Type 'inventory' or 'inv' to access your inventory \nType the direction you want to go to (e.g noth, south, north east, etc) \nType 'visit shop' or 'vs' to open shop \nType 'fight boss' when you are in the wasteland to fight Thanos \nType 'visit chief' to visit area chief";
}