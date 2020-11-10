#pragma once

#include <algorithm>

#include "Screen.h"

class Parser : public Screen
{
	public:
		void Read();
		void ReadRaw();

		void Choice();

		int Parse();

		bool YesNo();

		void Pause();

		std::string getInput();
		int getChoice();

	private:
		std::string player_input;
		
		std::string yes_no;
		int choice;
};

