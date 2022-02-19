#pragma once
#include <iostream>


using namespace std;

class GameManager
{

public:

	GameManager();
	GameManager(int MaxLevel, int CurrentLevel);

	void Run();
	bool Menu();
	void NextLevel(int level);
	void ResetLevel();
	void LevelNotfound();

private:
	int m_MaxLevel;
	int m_CurrentLevel;
	int m_FirstPlayableLevel;
	bool m_LevelCompleted;
	bool m_exit;

};

