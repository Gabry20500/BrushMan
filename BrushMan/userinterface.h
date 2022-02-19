#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

class UserInterface {

public:

	/// <summary>
	/// This is the game main menu, player can choose whether  to play or exit the game
	/// </summary>
	bool mainmenu() {

		SetConsoleTextAttribute(hconsole, 4); //Red text

		std::cout << ":----------: \n";
		std::cout << "|          | \n";
		std::cout << "| BRUSHMAN | \n";
		std::cout << "|          | \n";
		std::cout << ":----------: \n";
		std::cout << "\n\n\n";

		SetConsoleTextAttribute(hconsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE); //White text

		std::cout << "BrushMan \n";
		std::cout << "Copyright (c) 2021, 2022 GP1, Inc. All rights reserved. \n";
		std::cout << "BrushMan is a registered trademark of GP1, Inc. \n";
		std::cout << "\n \n \n";

		std::cout << "[1] |PLAY| \n";
		std::cout << "\n \n";
		std::cout << "[2] |EXIT| \n";
		std::cout << "\n \n";
		

		std::string choice;

		do { //input control

			std::cout << ">";
			std::cin >> choice;
			for (auto& c : choice) c = tolower(c);

			if (choice == "play" || choice == "1")
			{
				return true;
			}
			else if (choice == "exit" || choice == "2")
			{
				return false;
			}

		} while (choice != "play" || choice != "1" || choice != "exit" || choice != "2");

	}

	/// <summary>
	/// Show to the player how he can move around the map.
	/// </summary>
	void movementtutorial() {

		SetConsoleTextAttribute(hconsole, 4); //Red text

		std::cout << "**********MOVEMENT TUTORIAL********** \n \n";

		SetConsoleTextAttribute(hconsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE); //White text

		std::cout << "In order to move the character around the map you have to use W, A, S, D. \n \n";

		std::cout << "	    [W]\n \n";

		std::cout << "	[A] [S] [D]\n \n";
	
		std::cout << "Press a key to continue . . . ";
		(void)_getch();
		std::cout << "\n";

	}

	/// <summary>
	/// Show to the player what is the bomb and what it does.
	/// </summary>
	void bombtutorial() {

		SetConsoleTextAttribute(hconsole, 4); //Red text

		std::cout << "**********BOMB TUTORIAL********** \n \n";

		SetConsoleTextAttribute(hconsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE); //White text

		std::cout << "The bomb is an obstacle that you can find around the map and it's represented by the symbol 'O'. \n";
		std::cout << "As the player pass through it, the player lose a life point. \n \n";

		std::cout << "Press a key to continue . . . ";
		(void)_getch();
		std::cout << "\n";

	}

	/// <summary>
	/// Show to the player what is the heart and what it does.
	/// </summary>
	void heartutorial() {

		SetConsoleTextAttribute(hconsole, 4); //Red text

		std::cout << "**********HEART TUTORIAL********** \n \n";

		SetConsoleTextAttribute(hconsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE); //White text

		std::cout << "The heart is a powerup that you can find around the map and it's represented by the symbol '$'. \n";
		std::cout << "As the player pass through it, it regens a life point. \n \n";

		std::cout << "Press a key to continue . . . ";
		(void)_getch();
		std::cout << "\n";

	}

	/// <summary>
	/// Show to the player what is the snowflake and what it does.
	/// </summary>
	void snowflaketutorial() {

		SetConsoleTextAttribute(hconsole, 4); //Red text

		std::cout << "**********SNOWFLAKE TUTORIAL********** \n \n";

		SetConsoleTextAttribute(hconsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE); //White text

		std::cout << "The snowflake is an obstacle that you can find around the map and it's represented by the symbol '#'. \n";
		std::cout << "As the player pass through it, it blocks player's inputs so as the player can't move. \n \n";

		std::cout << "Press a key to continue . . . ";
		(void)_getch();
		std::cout << "\n";
	}

	/// <summary>
	/// Show to the player what is the wall and what it does.
	/// </summary>
	void walltutorial() {

		SetConsoleTextAttribute(hconsole, 4); //Red text

		std::cout << "**********WALL TUTORIAL********** \n \n";

		SetConsoleTextAttribute(hconsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE); //White text

		std::cout << "The wall is an obstacle that you can find around the map and it's represented by the symbol '/'. \n";
		std::cout << "As the player pass through it, it moves the player back one cell based on his direction. \n \n";

		std::cout << "Press a key to continue . . . ";
		(void)_getch();
		std::cout << "\n";
	}

	/// <summary>
	/// Tell the player that he's approaching the final level.
	/// </summary>
	void finalleveladvise() {

		SetConsoleTextAttribute(hconsole, 4); //Red text

		std::cout << "**********PAY ATTENTION PLEASE********** \n \n";

		SetConsoleTextAttribute(hconsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE); //White text

		std::cout << "You're now approaching the final level of BrushMan. \n";
		std::cout << "Take a good amount of caffeine and keep your mind focused! \n";
		std::cout << "Good luck player! \n \n";

		std::cout << "Press a key to continue . . . ";
		(void)_getch();
		std::cout << "\n";
	}

	/// <summary>
	/// This is the endgame screen with credits.
	/// This brings back to the main menu.
	/// </summary>
	void endgamescreen() {

		SetConsoleTextAttribute(hconsole, 4); //Red text

		std::cout << "**********CONGRATS********** \n \n";

		SetConsoleTextAttribute(hconsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE); //White text

		std::cout << "You've completed all the six levels of BrushMan. \n";
		std::cout << "Are you terminator? \n";
		std::cout << "Anyway, thanks for playing our game! \n";
		std::cout << "We hope you had fun! \n \n";

		std::cout << "	***Credits*** \n \n";

		std::cout << "	[Bersini Davide]\n";
		std::cout << "	[De Bonis Marcello]\n";
		std::cout << "	[Fiorentino Gabriele]\n";
		std::cout << "	[Latella Nicola]\n";
		std::cout << "	[Roveda Filippo]\n";
		std::cout << "	[Salimbeni Kevin]\n \n";

		std::cout << "BrushMan \n";
		std::cout << "Copyright (c) 2021, 2022 GP1, Inc. All rights reserved. \n";
		std::cout << "BrushMan is a registered trademark of GP1, Inc. \n";
		std::cout << "\n \n \n";

		std::cout << "Press a key to continue . . . ";
		(void)_getch();
		std::cout << "\n";

	}


};
