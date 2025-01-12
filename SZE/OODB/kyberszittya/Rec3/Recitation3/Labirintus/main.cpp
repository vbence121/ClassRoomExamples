// Labirintus.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

#include "Hero.h"
#include "Padloelem.h"
#include "Labirintus.h"
#include "common.h"

#ifdef _WIN32
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

bool isMovingCommand(const std::string& cmd)
{
	return cmd.compare("east") == 0 || cmd.compare("west") == 0 || cmd.compare("north") == 0 || cmd.compare("south") == 0;
}

void game()
{
	Hero hero("Gipsz Jakab", 100, 13, 15, 10);

	Labirintus labirintus(hero, 5);

	labirintus.initializeNeighbors();
	labirintus.initHeroPosition(2, 2);
	labirintus.initMonsterPosition(0, 3, 3);
	labirintus.initMonsterPosition(1, 6, 3);
	labirintus.initMonsterPosition(2, 1, 1);
	labirintus.initMonsterPosition(3, 7, 4);
	labirintus.initMonsterPosition(4, 9, 1);

	std::string cmd;
	MovingDirection dir;

	while (true)
	{
		labirintus.print();
		std::cout << hero << '\n';
		std::cout << "command: ";
		std::cin >> cmd;
		if (isMovingCommand(cmd))
		{
			if (cmd.compare("east") == 0)
			{
				dir = MovingDirection::KELET;
			}
			else if (cmd.compare("west") == 0)
			{
				dir = MovingDirection::NYUGAT;
			}
			else if (cmd.compare("north") == 0)
			{
				dir = MovingDirection::ESZAK;
			}
			else if (cmd.compare("south") == 0)
			{
				dir = MovingDirection::DEL;
			}
			if (!hero.move(dir))
			{
				std::cout << "Invalid direction" << '\n';
			}
		}
		else if (cmd.compare("stay") == 0)
		{

		}
		else if (cmd.compare("exit"))
		{
			break;
		}

	}

	std::cout << "Bye!\n";
}

int main()
{
	game();
#ifdef _WIN32
	_CrtDumpMemoryLeaks();
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
#endif // _WIN32
	return 0;
}

