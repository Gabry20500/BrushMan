#include "GameManager.h"
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
				//tutorialscreen(enumlevel)

				while (!m_LevelCompleted)
				{
					switch (m_CurrentLevel)
					{
					case 1:

						break;

					case 2:

						break;

					case 3:

						break;

					case 4:

						break;

					case 5:

						break;

					case 6:

						break;

					default:
						GameManager::LevelNotfound();
					}

					//Filippo's Function
					//looplevel

					//if(condition)
					//{ 
					//m_LevelCompleted=true;
					//}
				}

				GameManager::NextLevel(1);

			}
			GameManager::ResetLevel();

			//endgamescreen

			m_exit = GameManager::Menu();
		}
	}
}

bool GameManager::Menu()
{
	//Menùscreen
	return false;
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