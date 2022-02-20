#include "GameManager.h"
#include "../UserInterface/userinterface.h"
#include <thread>
#include <chrono>

GameManager::GameManager()
{
	m_MaxLevel = 6;
	m_CurrentLevel = 1;
	m_FirstPlayableLevel = m_CurrentLevel;
	m_LevelCompleted = false;
	m_exit = false;

};

GameManager::GameManager(int MaxLevel, int CurrentLevel)
{
	m_MaxLevel = MaxLevel;
	m_CurrentLevel = CurrentLevel;
	m_FirstPlayableLevel = m_CurrentLevel;
	m_LevelCompleted = false;
	m_exit = false;

}

void GameManager::Run()
{
	while (!m_exit)
	{
		m_exit = GameManager::Menu();

		if (!m_exit)
		{
			while (m_CurrentLevel != (m_MaxLevel + 1))
			{
				GameManager::ShowTutorial(m_CurrentLevel);

				while (!m_LevelCompleted)
				{
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
				GameManager::NextLevel(1);
			}
			GameManager::ResetLevel();

			//UserInterface::endgamescreen;

			m_exit = GameManager::Menu();
		}
	}
}

bool GameManager::Menu()
{
	bool Play;
	Play = false; //(UserInterface::mainmenu);
	
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

		//UserInterface::movementtutorial;

		break;
	case 2:

		//UserInterface::bombtutorial;

		break;

	case 3:

		//UserInterface::heartutorial;

		break;

	case 4:

		//UserInterface::snowflaketutorial;

		break;
	case 5:

		//UserInterface::walltutorial;

		break;
	case 6:

		//UserInterface::finalleveladvise;

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