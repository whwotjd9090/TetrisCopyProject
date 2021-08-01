#include "Tetris.hpp"
#include "SoundManager.hpp"
#include <conio.h>

int main()
{
	SoundManager::GetInstance()->SoundInit();
	SoundManager::GetInstance()->SoundLoading();

	Tetris tetris;

	tetris.Intro();

	while(true)
	{
		SoundManager::GetInstance()->SoundUpdate();

		if(_kbhit())
		{
			tetris.Menu();
			break;
		}
	}
}