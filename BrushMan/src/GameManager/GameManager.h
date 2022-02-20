#pragma once

#include  "../UserInterface/userinterface.h"




class GameManager
{

public:
	

	//Creation of a Default new game
	GameManager();

	//Creation of a Custom new game with new levels
	GameManager(int MaxLevel, int CurrentLevel);

	//The game is running until m_exit is negative
	void Run();

	//The player can choose if He wants to play or not
	bool Menu();

	//Every Level need a tutorial that explains new feature in each level
	void ShowTutorial(int m_CurrentLevel);


	void NextLevel(int level);


	void ResetLevel();


	void LevelNotfound();
protected:
	int m_CurrentLevel;
private:
	int m_MaxLevel;
	int m_FirstPlayableLevel;
	bool m_LevelCompleted;
	bool m_exit;
	UserInterface m_Interface;
};

