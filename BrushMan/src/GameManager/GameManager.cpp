#include "GameManager.h"
#include <thread>
#include <chrono>

//Creation of a Default new game
GameManager::GameManager()
{
	m_MaxLevel = 6;
	m_CurrentLevel = 1;
	m_FirstPlayableLevel = m_CurrentLevel;
	m_LevelCompleted = false;
	m_exit = false;
	UserInterface Interface = m_Interface;
};

//Creation of a Custom new game with new levels
GameManager::GameManager(int MaxLevel, int CurrentLevel)
{
	m_MaxLevel = MaxLevel;
	m_CurrentLevel = CurrentLevel;
	m_FirstPlayableLevel = m_CurrentLevel;
	m_LevelCompleted = false;
	m_exit = false;
	UserInterface Interface=m_Interface;
}

//The game is running until m_exit is negative
void GameManager::Run()
{
	while (!m_exit)
	{
		//The player can choose if He wants to play or not
		m_exit = GameManager::Menu();

		//If the player wants to play
		if (!m_exit)
		{
			while (m_CurrentLevel != (m_MaxLevel + 1))
			{
				//Every Level need a tutorial that explains new feature in each level
				GameManager::ShowTutorial(m_CurrentLevel);

				//Until the level isn't completed, redo that level
				while (!m_LevelCompleted)
				{
					//Choose the level and apply that specified things
					switch (m_CurrentLevel)
					{
					case 1:

						//m_LevelCompleted=funclevelloop

						break;

					case 2:

						//m_LevelCompleted=funclevelloop

						break;

					case 3:

						//m_LevelCompleted=funclevelloop

						break;

					case 4:

						//m_LevelCompleted=funclevelloop

						break;

					case 5:

						//m_LevelCompleted=funclevelloop

						break;

					case 6:

						//m_LevelCompleted=funclevelloop

						break;

					default:
						GameManager::LevelNotfound();
					}
				}

				//Everytime a level is completed go to the next(s)
				GameManager::NextLevel(1);
			}

			//The next current level become the first one playable
			GameManager::ResetLevel();

			//Screen of endgame
			m_Interface.endgamescreen();

		}
	}
}

//The player can choose if He wants to play or not
bool GameManager::Menu()
{
	bool Play;
	Play = m_Interface.mainmenu();
	
	if (Play)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void GameManager::ShowTutorial(int m_CurrentLevel)
{
	switch (m_CurrentLevel)
	{
	case 1:

		m_Interface.movementtutorial();

		break;
	case 2:

		m_Interface.bombtutorial();

		break;

	case 3:

		m_Interface.heartutorial();

		break;

	case 4:

		m_Interface.snowflaketutorial();

		break;
	case 5:

		m_Interface.walltutorial();

		break;
	case 6:

		m_Interface.finalleveladvise();

		break;
	}
}


void GameManager::NextLevel(int level)
{
	m_LevelCompleted = false;
	m_CurrentLevel += level;
}

void GameManager::ResetLevel()
{
	m_CurrentLevel = m_FirstPlayableLevel;
}

void GameManager::LevelNotfound()
{
	std::cout << "Error 999999999, the level number";
	std::cout << m_CurrentLevel;
	std::cout << "not found";
	std::this_thread::sleep_for(3s);
}

int GameManager::GetCurrentLevel()
{
	return m_CurrentLevel;
}
