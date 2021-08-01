#include "Tetris.hpp"

void Tetris::InitIntro() const
{
	WindowConsoleControl::SETTITLE("Tetris JS - ver 0.1");
	WindowConsoleControl::SETSIZE(CONSOLE_INTRO_WIDTH, CONSOLE_INTRO_HEIGHT);
	WindowConsoleControl::SETFONT(CONSOLE_FONT_WIDTH, CONSOLE_FONT_HEIGHT, L"굴림체", false);
	WindowConsoleControl::CURSORVISIBLE(false);

	SoundManager::GetInstance()->SoundPlay(SOUND_INTRO_BACKGROUND);
}
void Tetris::DrawIntro() const
{
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(2, 2);					std::cout << "■■■■";
	for(int i = 0; i < 4; i++) {
		WindowConsoleControl::SETPOSITION(5, 3 + i);			std::cout << "■";
	}

	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_L), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(11, 2);					std::cout << "■■■";
	WindowConsoleControl::SETPOSITION(11, 3);					std::cout << "■";
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(11, 4);					std::cout << "■■■■";
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_J), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(11, 5);					std::cout << "■";
	WindowConsoleControl::SETPOSITION(11, 6);					std::cout << "■■■";

	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(18, 2);					std::cout << "■■■■";
	for(int i = 0; i < 4; i++) {
		WindowConsoleControl::SETPOSITION(21, 3 + i);			std::cout << "■";
	}

	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	for(int i = 0; i < 4; i++) {
		WindowConsoleControl::SETPOSITION(27, 3 + i);			std::cout << "■";
	}
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_J), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(27, 2);					std::cout << "■■■";
	WindowConsoleControl::SETPOSITION(31, 3);					std::cout << "■";
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_S), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(29, 4);					std::cout << "■";
	WindowConsoleControl::SETPOSITION(29, 5);					std::cout << "■■";
	WindowConsoleControl::SETPOSITION(31, 6);					std::cout << "■";

	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_T), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(34, 2);					std::cout << "■■■";
	WindowConsoleControl::SETPOSITION(36, 3);					std::cout << "■";
	WindowConsoleControl::SETPOSITION(36, 5);					std::cout << "■";
	WindowConsoleControl::SETPOSITION(34, 6);					std::cout << "■■■";

	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(41, 2);					std::cout << "■■■■";
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_J), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(41, 3);					std::cout << "■";
	WindowConsoleControl::SETPOSITION(41, 4);					std::cout << "■■■";
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_L), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(47, 4);					std::cout << "■■";
	WindowConsoleControl::SETPOSITION(49, 5);					std::cout << "■";
	WindowConsoleControl::SETPOSITION(49, 6);					std::cout << "■";
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(41, 6);					std::cout << "■■■■";

	WindowConsoleControl::SETPOSITION(14, 12);	std::cout << "Please Start to any key!!!";
}
void Tetris::DrawMenu() const
{
	WindowConsoleControl::CLEAR();
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_INTERFACE), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETSIZE(CONSOLE_INTRO_WIDTH, CONSOLE_INTRO_HEIGHT);
	WindowConsoleControl::CURSORVISIBLE(false);
	
	WindowConsoleControl::SETPOSITION(20, 4);
	std::cout << "Game Start";

	WindowConsoleControl::SETPOSITION(20, 6);
	std::cout << "High Score";

	WindowConsoleControl::SETPOSITION(23, 8);
	std::cout << "Help";

	WindowConsoleControl::SETPOSITION(23, 10);
	std::cout << "Exit";
}
int Tetris::MenuSelect()
{
	int select_menu = 0;
	bool is_selected = false;

	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_SELECTED), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(18, 4);
	std::cout << ">";
	WindowConsoleControl::SETPOSITION(31, 4);
	std::cout << "<";

	Sleep(300);

	while(!is_selected)
	{
		if(GetAsyncKeyState(VK_UP) & 0x8000)
		{
			if(!isPressed_UP)
			{
				isPressed_UP = true;

				switch(select_menu)
				{
				case 0:
					WindowConsoleControl::SETPOSITION(18, 4);
					std::cout << " ";
					WindowConsoleControl::SETPOSITION(31, 4);
					std::cout << " ";
					break;

				case 1:
					WindowConsoleControl::SETPOSITION(18, 6);
					std::cout << " ";
					WindowConsoleControl::SETPOSITION(31, 6);
					std::cout << " ";
					break;

				case 2:
					WindowConsoleControl::SETPOSITION(21, 8);
					std::cout << " ";
					WindowConsoleControl::SETPOSITION(28, 8);
					std::cout << " ";
					break;

				case 3:
					WindowConsoleControl::SETPOSITION(21, 10);
					std::cout << " ";
					WindowConsoleControl::SETPOSITION(28, 10);
					std::cout << " ";
					break;
				}
				select_menu = (select_menu + 3) % 4;
				switch(select_menu)
				{
				case 0:
					WindowConsoleControl::SETPOSITION(18, 4);
					std::cout << ">";
					WindowConsoleControl::SETPOSITION(31, 4);
					std::cout << "<";
					break;

				case 1:
					WindowConsoleControl::SETPOSITION(18, 6);
					std::cout << ">";
					WindowConsoleControl::SETPOSITION(31, 6);
					std::cout << "<";
					break;

				case 2:
					WindowConsoleControl::SETPOSITION(21, 8);
					std::cout << ">";
					WindowConsoleControl::SETPOSITION(28, 8);
					std::cout << "<";
					break;

				case 3:
					WindowConsoleControl::SETPOSITION(21, 10);
					std::cout << ">";
					WindowConsoleControl::SETPOSITION(28, 10);
					std::cout << "<";
					break;
				}
			}
		}
		else
			isPressed_UP = false;
		if(GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			if(!isPressed_DOWN)
			{
				isPressed_DOWN = true;

				switch(select_menu)
				{
				case 0:
					WindowConsoleControl::SETPOSITION(18, 4);
					std::cout << " ";
					WindowConsoleControl::SETPOSITION(31, 4);
					std::cout << " ";
					break;

				case 1:
					WindowConsoleControl::SETPOSITION(18, 6);
					std::cout << " ";
					WindowConsoleControl::SETPOSITION(31, 6);
					std::cout << " ";
					break;

				case 2:
					WindowConsoleControl::SETPOSITION(21, 8);
					std::cout << " ";
					WindowConsoleControl::SETPOSITION(28, 8);
					std::cout << " ";
					break;

				case 3:
					WindowConsoleControl::SETPOSITION(21, 10);
					std::cout << " ";
					WindowConsoleControl::SETPOSITION(28, 10);
					std::cout << " ";
					break;
				}
				select_menu = (select_menu + 1) % 4;
				switch(select_menu)
				{
				case 0:
					WindowConsoleControl::SETPOSITION(18, 4);
					std::cout << ">";
					WindowConsoleControl::SETPOSITION(31, 4);
					std::cout << "<";
					break;

				case 1:
					WindowConsoleControl::SETPOSITION(18, 6);
					std::cout << ">";
					WindowConsoleControl::SETPOSITION(31, 6);
					std::cout << "<";
					break;

				case 2:
					WindowConsoleControl::SETPOSITION(21, 8);
					std::cout << ">";
					WindowConsoleControl::SETPOSITION(28, 8);
					std::cout << "<";
					break;

				case 3:
					WindowConsoleControl::SETPOSITION(21, 10);
					std::cout << ">";
					WindowConsoleControl::SETPOSITION(28, 10);
					std::cout << "<";
					break;
				}
			}
		}
		else
			isPressed_DOWN = false;
		if(GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			if(!isPressed_RETURN)
			{
				isPressed_RETURN = true;

				is_selected = true;
			}
		}
		else
			isPressed_RETURN = false;
	}

	return select_menu;
}

void Tetris::DrawHelp() const
{
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_INTERFACE), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETSIZE(CONSOLE_HELP_WIDTH, CONSOLE_HELP_HEIGHT);
	WindowConsoleControl::CLEAR();

	std::cout << "* 조작법 *" << std::endl;
	std::cout << "←\t\t현재 블럭 한 칸 좌측 이동" << std::endl << std::endl;
	std::cout << "→\t\t현재 블럭 한 칸 우측 이동" << std::endl << std::endl;
	std::cout << "↑, X\t\t현재 블럭 시계 방향 회전" << std::endl << std::endl;
	std::cout << "Ctrl, Z\t\t현재 블럭 반시계 방향 회전" << std::endl << std::endl;
	std::cout << "Shift, C\t현재 블럭 홀드" << std::endl << std::endl;
	std::cout << "↓\t\t현재 블럭 한 칸 아래 이동 (소프트 드랍)" << std::endl << std::endl;
	std::cout << "Space\t\t현재 블럭 가능한 최하단 이동 후 고정 (하드 드랍)" << std::endl << std::endl;
	std::cout << std::endl;
	std::cout << "* 기본 설정 *" << std::endl;
	std::cout << "게임 필드\t가로 10칸 세로 20칸입니다." << std::endl << std::endl;
	std::cout << "테트로미노\t게임에 등장하는 블럭들의 이름이며 총 7가지가 존재합니다.";
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(1, 22);
	std::cout << "I ■■■■";
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_O), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(14, 21);
	std::cout << "■■";
	WindowConsoleControl::SETPOSITION(12, 22);
	std::cout << "O ■■";
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_T), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(23, 21);
	std::cout << "■";
	WindowConsoleControl::SETPOSITION(19, 22);
	std::cout << "T ■■■";
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_S), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(32, 21);
	std::cout << "■■";
	WindowConsoleControl::SETPOSITION(28, 22);
	std::cout << "S ■■";
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_Z), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(38, 21);
	std::cout << "■■";
	WindowConsoleControl::SETPOSITION(37, 22);
	std::cout << "Z  ■■";
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_J), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(47, 21);
	std::cout << "■";
	WindowConsoleControl::SETPOSITION(45, 22);
	std::cout << "J ■■■";
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_L), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(60, 21);
	std::cout << "■";
	WindowConsoleControl::SETPOSITION(54, 22);
	std::cout << "L ■■■";
	std::cout << std::endl << std::endl;
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_INTERFACE), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	std::cout << "NEXT\t\t다음에 나올 블럭을 최대 3개까지 보여줍니다." << std::endl << std::endl;
	std::cout << "HOLD\t\t현재 블럭을 사용하지 않고 홀드시킵니다.\n\t\t기존 홀드 블럭이 있으면 해당 블럭과 대체되며,\n\t\t없으면 다음 블럭을 플레이합니다." << std::endl << std::endl;
	std::cout << "레벨\t\t현재 레벨을 나타냅니다.\n\t\t레벨이 높을수록 획득 점수와 블럭 낙하속도가 빨라집니다." << std::endl << std::endl;
	std::cout << "점수\t\t현재까지 획득한 점수를 나타냅니다." << std::endl << std::endl;
	std::cout << "\tSingle\t한 줄 클리어100 X 현재 레벨" << std::endl;
	std::cout << "\tDouble\t두 줄 클리어300 X 현재 레벨" << std::endl;
	std::cout << "\tTriple\t세 줄 클리어500 X 현재 레벨" << std::endl;
	std::cout << "\tTetris\t네 줄 클리어800 X 현재 레벨" << std::endl;
	std::cout << "남은 라인\t다음 레벨에 도달하기 위해 지워야하는 라인 수를 나탑냅니다." << std::endl << std::endl;
}

void Tetris::DrawInterface() const
{
	DrawStageField();
	DrawNextField();
	DrawHoldField();
	DrawLevelField();
	DrawScoreField();
	DrawRemainLineField();
}
void Tetris::DrawStageField() const
{
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_DEADZONE), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	for(int i = DEAD_FIELD_TOP; i <= DEAD_FIELD_BOTTOM; i++) {
		WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT, i);								std::cout << "    ■                    ■";
	}

	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_INTERFACE), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	for(int i = GAME_FIELD_TOP; i <= GAME_FIELD_BOTTOM; i++) {
		WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT, i);								std::cout << "    ■                    ■";
	}

	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT, GAME_FIELD_BOTTOM + BLOCK_SIZE_Y);	std::cout << "    ■■■■■■■■■■■■";
}
void Tetris::DrawNextField() const
{
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_INTERFACE), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(NEXT1_FIELD_LEFT, NEXT1_FIELD_TOP);		std::cout << "┏   NEXT  ┓";
	for(int i = NEXT1_FIELD_TOP + 1; i < NEXT1_FIELD_BOTTOM; i++) {
		WindowConsoleControl::SETPOSITION(NEXT1_FIELD_LEFT, i);					std::cout << "┃         ┃";
	}
	WindowConsoleControl::SETPOSITION(NEXT1_FIELD_LEFT, NEXT1_FIELD_BOTTOM);	std::cout << "┗━━━━━━━━━┛";

	for(int i = NEXT2_FIELD_TOP; i < NEXT2_FIELD_BOTTOM; i++) {
		WindowConsoleControl::SETPOSITION(NEXT2_FIELD_LEFT, i);					std::cout << "│         │";
	}
	WindowConsoleControl::SETPOSITION(NEXT2_FIELD_LEFT, NEXT2_FIELD_BOTTOM);	std::cout << "└─────────┘";

	for(int i = NEXT3_FIELD_TOP; i < NEXT3_FIELD_BOTTOM; i++) {
		WindowConsoleControl::SETPOSITION(NEXT3_FIELD_LEFT, i);					std::cout << "│         │";
	}
	WindowConsoleControl::SETPOSITION(NEXT3_FIELD_LEFT, NEXT3_FIELD_BOTTOM);	std::cout << "└─────────┘";
}
void Tetris::DrawHoldField() const
{
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_INTERFACE), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(HOLD_FIELD_LEFT, HOLD_FIELD_TOP);		std::cout << "┏   HOLD  ┓";
	for(int i = HOLD_FIELD_TOP + 1; i < HOLD_FIELD_BOTTOM; i++) {
		WindowConsoleControl::SETPOSITION(HOLD_FIELD_LEFT, i);		        std::cout << "┃         ┃";
	}
	WindowConsoleControl::SETPOSITION(HOLD_FIELD_LEFT, HOLD_FIELD_BOTTOM);	std::cout << "┗━━━━━━━━━┛";
}
void Tetris::DrawLevelField() const
{
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_INTERFACE), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(LEVEL_FIELD_LEFT, LEVEL_FIELD_TOP);       std::cout << "┏   레벨  ┓";
	WindowConsoleControl::SETPOSITION(LEVEL_FIELD_LEFT, LEVEL_FIELD_TOP + 1);   std::cout << "┃         ┃";
	WindowConsoleControl::SETPOSITION(LEVEL_FIELD_LEFT, LEVEL_FIELD_BOTTOM);	std::cout << "┗━━━━━━━━━┛";
}
void Tetris::DrawScoreField() const
{
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_INTERFACE), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(SCORE_FIELD_LEFT, SCORE_FIELD_TOP);       std::cout << "┏   점수  ┓";
	WindowConsoleControl::SETPOSITION(SCORE_FIELD_LEFT, SCORE_FIELD_TOP + 1);   std::cout << "┃         ┃";
	WindowConsoleControl::SETPOSITION(SCORE_FIELD_LEFT, SCORE_FIELD_BOTTOM);	std::cout << "┗━━━━━━━━━┛";
}
void Tetris::DrawRemainLineField() const
{
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_INTERFACE), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(REMAIN_LINE_FIELD_LEFT, REMAIN_LINE_FIELD_TOP);		std::cout << "┏ 남은 라인┓";
	WindowConsoleControl::SETPOSITION(REMAIN_LINE_FIELD_LEFT, REMAIN_LINE_FIELD_TOP + 1);	std::cout << "┃          ┃";
	WindowConsoleControl::SETPOSITION(REMAIN_LINE_FIELD_LEFT, REMAIN_LINE_FIELD_BOTTOM);	std::cout << "┗━━━━━━━━━━┛";
}

void Tetris::InitGame()
{
	now_tetromino = nullptr;
	next1_tetromino = nullptr;
	next2_tetromino = nullptr;
	next3_tetromino = nullptr;
	ghost_tetromino = nullptr;
	hold_tetromino = nullptr;

	isBlockLock = false;
	isPressed_UP = false;
	isPressed_RIGHT = false;
	isPressed_DOWN = false;
	isPressed_LEFT = false;
	isPressed_SPACE_BAR = false;
	isPressed_SHIFT = false;
	isPressed_CTRL = false;
	isPressed_X = false;
	isPressed_C = false;
	isPressed_Z = false;
	isPressed_ESC = false;
	isPressed_F1 = false;
	isPressed_RETURN = false;
	canHold = true;
	isTSpin = false;
	isMiniTSpin = false;
	isSingle = false;
	isDouble = false;
	isTriple = false;
	isTetris = false;
	isBTB = false;
	isPrevBTB = false;

	game_status = GAME_STATUS::GAME_PLAYING;
	next_block_index = 0;
	player_score = 0;
	player_level = 1;
	combo_count = 0;
	remain_line = 5;
	block_down_frame = FRAME_RATE;
	lock_delay_frame = 0.5 * FRAME_RATE;

	dre.seed(rd());
	SetBlockRandomGeneratorList();

	/*
	game_field (0) : 가로 0 ~ 15 (16개) / 세로 0 ~ 26 (27개) 
	game_field_color (BLACK) : 이상 동일
	*/
	for(size_t i = 0; i < game_field.size(); i++)
	{
		game_field.at(i).fill(0);
		game_field_color.at(i).fill(WINDOW_CONSOLE_COLOR::BLACK);
	}
	/**/

	/* 벽 (-1) */
	// 0, 1, 2		: 왼쪽 벽 3개
	// 13, 14, 15	: 오른쪽 벽 3개
	for(int i = 0; i < WALL_LEFT_BOTTOM; i++)
		game_field.at(i).at(0) =
		game_field.at(i).at(1) =
		game_field.at(i).at(2) =
		game_field.at(i).at(13) =
		game_field.at(i).at(14) =
		game_field.at(i).at(15) =
		-1;

	// 24, 25, 26 : 아래쪽 벽 3개
	for(int i = 0; i < STAGE_FIELD_WIDTH; i++)
		game_field.at(STAGE_FIELD_BOTTOM).at(i) =
		game_field.at(STAGE_FIELD_BOTTOM - BLOCK_SIZE_Y).at(i) =
		game_field.at(STAGE_FIELD_BOTTOM - 2 * BLOCK_SIZE_Y).at(i) =
		-1;
	/**/

	SoundManager::GetInstance()->SoundStop(SOUND_INTRO_BACKGROUND);

	WindowConsoleControl::SETSIZE(CONSOLE_PLAY_WIDTH, CONSOLE_PLAY_HEIGHT);
	WindowConsoleControl::CLEAR();
	WindowConsoleControl::CURSORVISIBLE(false);
}
void Tetris::StartCount() const
{
	SoundManager::GetInstance()->SoundPlay(SOUND_START_COUNT);

	Sleep(850);

	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_COUNT_3), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 12, STAGE_FIELD_TOP + 8);	std::cout << "■■■■";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 18, STAGE_FIELD_TOP + 9);	std::cout << "■";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 12, STAGE_FIELD_TOP + 10);	std::cout << "■■■■";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 18, STAGE_FIELD_TOP + 11);	std::cout << "■";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 12, STAGE_FIELD_TOP + 12);	std::cout << "■■■■";

	Sleep(1100);

	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 12, STAGE_FIELD_TOP + 8);	std::cout << "        ";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 18, STAGE_FIELD_TOP + 9);	std::cout << "  ";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 12, STAGE_FIELD_TOP + 10);	std::cout << "        ";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 18, STAGE_FIELD_TOP + 11);	std::cout << "  ";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 12, STAGE_FIELD_TOP + 12);	std::cout << "        ";

	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_COUNT_2), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 12, STAGE_FIELD_TOP + 8);	std::cout << "■■■■";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 18, STAGE_FIELD_TOP + 9);	std::cout << "■";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 12, STAGE_FIELD_TOP + 10);	std::cout << "■■■■";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 12, STAGE_FIELD_TOP + 11);	std::cout << "■";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 12, STAGE_FIELD_TOP + 12);	std::cout << "■■■■";

	Sleep(1000);

	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 12, STAGE_FIELD_TOP + 8);	std::cout << "        ";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 18, STAGE_FIELD_TOP + 9);	std::cout << "  ";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 12, STAGE_FIELD_TOP + 10);	std::cout << "        ";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 12, STAGE_FIELD_TOP + 11);	std::cout << "  ";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 12, STAGE_FIELD_TOP + 12);	std::cout << "        ";

	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_COUNT_1), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 15, STAGE_FIELD_TOP + 8);	std::cout << "■";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 15, STAGE_FIELD_TOP + 9);	std::cout << "■";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 15, STAGE_FIELD_TOP + 10);	std::cout << "■";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 15, STAGE_FIELD_TOP + 11);	std::cout << "■";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 15, STAGE_FIELD_TOP + 12);	std::cout << "■";

	Sleep(1000);

	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 15, STAGE_FIELD_TOP + 8);	std::cout << "  ";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 15, STAGE_FIELD_TOP + 9);	std::cout << "  ";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 15, STAGE_FIELD_TOP + 10);	std::cout << "  ";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 15, STAGE_FIELD_TOP + 11);	std::cout << "  ";
	WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + 15, STAGE_FIELD_TOP + 12);	std::cout << "  ";
}

bool Tetris::MoveOK(const BLOCKSHAPE _shape, const ROTATE _rotate, const MOVE _direction)
{
	bool result = false;
	const int now_x = now_tetromino->GetPosition().first;
	const int now_y = now_tetromino->GetPosition().second;

	switch(_shape)
	{
		// I
	case BLOCKSHAPE::I:
		switch(_rotate)
		{
		case ROTATE::SPAWN:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 1 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y - 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y - 1).at(now_x) == 0 &&
					   game_field.at(now_y - 1).at(now_x + 1) == 0 &&
					   game_field.at(now_y - 1).at(now_x + 2) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 3 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y).at(now_x + 3) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 1 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y + 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 2) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 2 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y).at(now_x - 2) == 0)
						result = true;
				break;
			}
			break;

		case ROTATE::RIGHT:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 2 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y - 2).at(now_x) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 1 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y - 1).at(now_x + 1) == 0 &&
					   game_field.at(now_y).at(now_x + 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 1) == 0 &&
					   game_field.at(now_y + 2).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 3 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y + 3).at(now_x) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 1 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y - 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 2).at(now_x - 1) == 0)
						result = true;
				break;
			}
			break;

		case ROTATE::TWICE:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 1 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y - 1).at(now_x - 2) == 0 &&
					   game_field.at(now_y - 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y - 1).at(now_x) == 0 &&
					   game_field.at(now_y - 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 2 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y).at(now_x + 2) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 1 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y + 1).at(now_x - 2) == 0 &&
					   game_field.at(now_y + 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 3 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y).at(now_x - 3) == 0)
						result = true;
				break;
			}
			break;

		case ROTATE::LEFT:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 3 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y - 3).at(now_x) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 1 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y - 2).at(now_x + 1) == 0 &&
					   game_field.at(now_y - 1).at(now_x + 1) == 0 &&
					   game_field.at(now_y).at(now_x + 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 2 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y + 2).at(now_x) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 1 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y - 2).at(now_x - 1) == 0 &&
					   game_field.at(now_y - 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x - 1) == 0)
						result = true;
				break;
			}
			break;
		}
		break;

		// O
	case BLOCKSHAPE::O:
		switch(_direction)
		{
		case MOVE::UP:
			if(now_y - 2 >= BLOCK_MOVEABLE_TOP)
				if(game_field.at(now_y - 2).at(now_x) == 0 &&
				   game_field.at(now_y - 2).at(now_x + 1) == 0)
					result = true;
			   break;

		case MOVE::RIGHT:
			if(now_x + 2 <= BLOCK_MOVEABLE_RIGHT)
				if(game_field.at(now_y - 1).at(now_x + 2) == 0 &&
				   game_field.at(now_y).at(now_x + 2) == 0)
					result = true;
			break;

		case MOVE::DOWN:
			if(now_y + 1 <= BLOCK_MOVEABLE_BOTTOM)
				if(game_field.at(now_y + 1).at(now_x) == 0 &&
				   game_field.at(now_y + 1).at(now_x + 1) == 0)
					result = true;
			break;

		case MOVE::LEFT:
			if(now_x - 1 >= BLOCK_MOVEABLE_LEFT)
				if(game_field.at(now_y - 1).at(now_x - 1) == 0 &&
				   game_field.at(now_y).at(now_x - 1) == 0)
					result = true;
			break;
		}
		break;

		// T
	case BLOCKSHAPE::T:
		switch(_rotate)
		{
		case ROTATE::SPAWN:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 2 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y - 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y - 2).at(now_x) == 0 &&
					   game_field.at(now_y - 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 2 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y - 1).at(now_x + 1) == 0 &&
					   game_field.at(now_y).at(now_x + 2) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 1 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y + 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 2 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y - 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y).at(now_x - 2) == 0)
						result = true;
				break;
			}
			break;

		case ROTATE::RIGHT:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 2 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y - 2).at(now_x) == 0 &&
					   game_field.at(now_y - 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 2 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y - 1).at(now_x + 1) == 0 &&
					   game_field.at(now_y).at(now_x + 2) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 2 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y + 1).at(now_x + 1) == 0 &&
					   game_field.at(now_y + 2).at(now_x) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 1 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y - 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x - 1) == 0)
						result = true;
				break;
			}
			break;

		case ROTATE::TWICE:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 1 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y).at(now_x) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 2 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y).at(now_x + 2) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 2 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y + 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 2).at(now_x) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 2 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y).at(now_x - 2) == 0 &&
					   game_field.at(now_y + 1).at(now_x - 1) == 0)
						result = true;
				break;
			}
			break;

		case ROTATE::LEFT:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 2 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y - 2).at(now_x) == 0 &&
					   game_field.at(now_y - 1).at(now_x - 1) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 1 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y - 1).at(now_x + 1) == 0 &&
					   game_field.at(now_y).at(now_x + 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 2 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y + 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 2).at(now_x) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 2 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y - 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y).at(now_x - 2) == 0 &&
					   game_field.at(now_y + 1).at(now_x - 1) == 0)
						result = true;
				break;
			}
			break;
		}
		break;

		// S
	case BLOCKSHAPE::S:
		switch(_rotate)
		{
		case ROTATE::SPAWN:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 2 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y - 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y - 2).at(now_x) == 0 &&
					   game_field.at(now_y - 2).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 2 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y - 1).at(now_x + 2) == 0 &&
					   game_field.at(now_y).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 1 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y + 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x) == 0 &&
					   game_field.at(now_y).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 2 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y - 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y).at(now_x - 2) == 0)
						result = true;
				break;
			}
			break;

		case ROTATE::RIGHT:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 2 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y - 2).at(now_x) == 0 &&
					   game_field.at(now_y - 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 2 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y - 1).at(now_x + 1) == 0 &&
					   game_field.at(now_y).at(now_x + 2) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 2) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 2 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y + 1).at(now_x) == 0 &&
					   game_field.at(now_y + 2).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 1 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y - 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x) == 0)
						result = true;
				break;
			}
			break;

		case ROTATE::TWICE:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 1 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y).at(now_x - 1) == 0 &&
					   game_field.at(now_y - 1).at(now_x) == 0 &&
					   game_field.at(now_y - 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 2 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y).at(now_x + 2) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 2 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y + 2).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 2).at(now_x) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 2 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x - 2) == 0)
						result = true;
				break;
			}
			break;

		case ROTATE::LEFT:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 2 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y - 2).at(now_x - 1) == 0 &&
					   game_field.at(now_y - 1).at(now_x) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 1 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y - 1).at(now_x) == 0 &&
					   game_field.at(now_y).at(now_x + 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 2 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y + 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 2).at(now_x) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 2 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y - 1).at(now_x - 2) == 0 &&
					   game_field.at(now_y).at(now_x - 2) == 0 &&
					   game_field.at(now_y + 1).at(now_x - 1) == 0)
						result = true;
				break;
			}
			break;
		}
		break;

		// Z
	case BLOCKSHAPE::Z:
		switch(_rotate)
		{
		case ROTATE::SPAWN:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 2 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y - 2).at(now_x - 1) == 0 &&
					   game_field.at(now_y - 2).at(now_x) == 0 &&
					   game_field.at(now_y - 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 2 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y - 1).at(now_x + 1) == 0 &&
					   game_field.at(now_y).at(now_x + 2) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 1 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 2 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y - 1).at(now_x - 2) == 0 &&
					   game_field.at(now_y).at(now_x - 1) == 0)
						result = true;
				break;
			}
			break;

		case ROTATE::RIGHT:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 2 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y - 1).at(now_x) == 0 &&
					   game_field.at(now_y - 2).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 2 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y - 1).at(now_x + 2) == 0 &&
					   game_field.at(now_y).at(now_x + 2) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 2 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y + 2).at(now_x) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 1 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y - 1).at(now_x) == 0 &&
					   game_field.at(now_y).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x - 1) == 0)
						result = true;
				break;
			}
			break;

		case ROTATE::TWICE:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 1 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y - 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y - 1).at(now_x) == 0 &&
					   game_field.at(now_y).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 2 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y).at(now_x + 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 2) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 2 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y + 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 2).at(now_x) == 0 &&
					   game_field.at(now_y + 2).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 2)
					if(game_field.at(now_y).at(now_x - 2) == 0 &&
					   game_field.at(now_y + 1).at(now_x - 1) == 0)
						result = true;
				break;
			}
			break;

		case ROTATE::LEFT:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 2 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y - 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y - 2).at(now_x) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 1 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y - 1).at(now_x + 1) == 0 &&
					   game_field.at(now_y).at(now_x + 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 2 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y + 2).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 2 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y - 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y).at(now_x - 2) == 0 &&
					   game_field.at(now_y + 1).at(now_x - 2) == 0)
						result = true;
				break;
			}
			break;
		}
		break;

		// J
	case BLOCKSHAPE::J:
		switch(_rotate)
		{
		case ROTATE::SPAWN:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 2 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y - 2).at(now_x - 1) == 0 &&
					   game_field.at(now_y - 1).at(now_x) == 0 &&
					   game_field.at(now_y - 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 2 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y - 1).at(now_x) == 0 &&
					   game_field.at(now_y).at(now_x + 2) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 1 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y + 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 2 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y - 1).at(now_x - 2) == 0 &&
					   game_field.at(now_y).at(now_x - 2) == 0)
						result = true;
				break;
			}
			break;

		case ROTATE::RIGHT:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 2 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y - 2).at(now_x) == 0 &&
					   game_field.at(now_y - 2).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 2 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y - 1).at(now_x + 2) == 0 &&
					   game_field.at(now_y).at(now_x + 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 2 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y + 2).at(now_x) == 0 &&
					   game_field.at(now_y).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 1 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y - 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x - 1) == 0)
						result = true;
				break;
			}
			break;

		case ROTATE::TWICE:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 1 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y - 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y - 1).at(now_x) == 0 &&
					   game_field.at(now_y - 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 2 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y).at(now_x + 2) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 2) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 2 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y + 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x) == 0 &&
					   game_field.at(now_y + 2).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 2 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y).at(now_x - 2) == 0 &&
					   game_field.at(now_y + 1).at(now_x) == 0)
						result = true;
				break;
			}
			break;

		case ROTATE::LEFT:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 2 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y).at(now_x - 1) == 0 &&
					   game_field.at(now_y - 2).at(now_x) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 1 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y - 1).at(now_x + 1) == 0 &&
					   game_field.at(now_y).at(now_x + 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 2 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y + 2).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 2).at(now_x) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 2 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y - 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x - 2) == 0)
						result = true;
				break;
			}
			break;
		}
		break;

		// L
	case BLOCKSHAPE::L:
		switch(_rotate)
		{
		case ROTATE::SPAWN:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 2 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y - 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y - 1).at(now_x) == 0 &&
					   game_field.at(now_y - 2).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 2 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y - 1).at(now_x + 2) == 0 &&
					   game_field.at(now_y).at(now_x + 2) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 1 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y + 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 2 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y - 1).at(now_x) == 0 &&
					   game_field.at(now_y).at(now_x - 2) == 0)
						result = true;
				break;
			}
			break;

		case ROTATE::RIGHT:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 2 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y - 2).at(now_x) == 0 &&
					   game_field.at(now_y).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 2 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y - 1).at(now_x + 1) == 0 &&
					   game_field.at(now_y).at(now_x + 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 2) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 2 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y + 2).at(now_x) == 0 &&
					   game_field.at(now_y + 2).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 1 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y - 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x - 1) == 0)
						result = true;
				break;
			}
			break;

		case ROTATE::TWICE:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 1 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y - 1).at(now_x - 1) == 0 &&
					   game_field.at(now_y - 1).at(now_x) == 0 &&
					   game_field.at(now_y - 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 2 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y).at(now_x + 2) == 0 &&
					   game_field.at(now_y + 1).at(now_x) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 2 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y + 2).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 2 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y).at(now_x - 2) == 0 &&
					   game_field.at(now_y + 1).at(now_x - 2) == 0)
						result = true;
				break;
			}
			break;

		case ROTATE::LEFT:
			switch(_direction)
			{
			case MOVE::UP:
				if(now_y - 2 >= BLOCK_MOVEABLE_TOP)
					if(game_field.at(now_y - 2).at(now_x - 1) == 0 &&
					   game_field.at(now_y - 2).at(now_x) == 0)
						result = true;
				break;

			case MOVE::RIGHT:
				if(now_x + 1 <= BLOCK_MOVEABLE_RIGHT)
					if(game_field.at(now_y - 1).at(now_x + 1) == 0 &&
					   game_field.at(now_y).at(now_x + 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x + 1) == 0)
						result = true;
				break;

			case MOVE::DOWN:
				if(now_y + 2 <= BLOCK_MOVEABLE_BOTTOM)
					if(game_field.at(now_y).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 2).at(now_x) == 0)
						result = true;
				break;

			case MOVE::LEFT:
				if(now_x - 2 >= BLOCK_MOVEABLE_LEFT)
					if(game_field.at(now_y - 1).at(now_x - 2) == 0 &&
					   game_field.at(now_y).at(now_x - 1) == 0 &&
					   game_field.at(now_y + 1).at(now_x - 1) == 0)
						result = true;
				break;
			}
			break;
		}
		break;
	}

	return result;
}
std::array<bool, 5> Tetris::RotateOK(const BLOCKSHAPE _shape, const ROTATE _rotation, const ROTATE _rotate_direction)
{
	std::array<bool, 5> result{false, false, false, false, false};
	int new_x, new_y;
	const int now_x = now_tetromino->GetPosition().first;
	const int now_y = now_tetromino->GetPosition().second;

	switch(_shape)
	{
	case BLOCKSHAPE::I:
		switch(_rotation)
		{
		case ROTATE::SPAWN:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_I_SRS.at(0).at(i).at(1)).at(now_x + 1 + BLOCK_I_SRS.at(0).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_I_SRS.at(0).at(i).at(1)).at(now_x + 1 + BLOCK_I_SRS.at(0).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_I_SRS.at(0).at(i).at(1)).at(now_x + 1 + BLOCK_I_SRS.at(0).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 2 - BLOCK_I_SRS.at(0).at(i).at(1)).at(now_x + 1 + BLOCK_I_SRS.at(0).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_I_SRS.at(1).at(i).at(1)).at(now_x + BLOCK_I_SRS.at(1).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_I_SRS.at(1).at(i).at(1)).at(now_x + BLOCK_I_SRS.at(1).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_I_SRS.at(1).at(i).at(1)).at(now_x + BLOCK_I_SRS.at(1).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 2 - BLOCK_I_SRS.at(1).at(i).at(1)).at(now_x + BLOCK_I_SRS.at(1).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			break;

		case ROTATE::RIGHT:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y + 1 - BLOCK_I_SRS.at(2).at(i).at(1)).at(now_x - 2 + BLOCK_I_SRS.at(2).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_I_SRS.at(2).at(i).at(1)).at(now_x - 1 + BLOCK_I_SRS.at(2).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_I_SRS.at(2).at(i).at(1)).at(now_x + BLOCK_I_SRS.at(2).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_I_SRS.at(2).at(i).at(1)).at(now_x + 1 + BLOCK_I_SRS.at(2).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - BLOCK_I_SRS.at(3).at(i).at(1)).at(now_x - 2 + BLOCK_I_SRS.at(3).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_I_SRS.at(3).at(i).at(1)).at(now_x - 1 + BLOCK_I_SRS.at(3).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_I_SRS.at(3).at(i).at(1)).at(now_x + BLOCK_I_SRS.at(3).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_I_SRS.at(3).at(i).at(1)).at(now_x + 1 + BLOCK_I_SRS.at(3).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			break;

		case ROTATE::TWICE:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 2 - BLOCK_I_SRS.at(4).at(i).at(1)).at(now_x - 1 + BLOCK_I_SRS.at(4).at(i).at(0)) == 0 &&
					   game_field.at(now_y - 1 - BLOCK_I_SRS.at(4).at(i).at(1)).at(now_x - 1 + BLOCK_I_SRS.at(4).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_I_SRS.at(4).at(i).at(1)).at(now_x - 1 + BLOCK_I_SRS.at(4).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_I_SRS.at(4).at(i).at(1)).at(now_x - 1 + BLOCK_I_SRS.at(4).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 2 - BLOCK_I_SRS.at(5).at(i).at(1)).at(now_x + BLOCK_I_SRS.at(5).at(i).at(0)) == 0 &&
					   game_field.at(now_y - 1 - BLOCK_I_SRS.at(5).at(i).at(1)).at(now_x + BLOCK_I_SRS.at(5).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_I_SRS.at(5).at(i).at(1)).at(now_x + BLOCK_I_SRS.at(5).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_I_SRS.at(5).at(i).at(1)).at(now_x + BLOCK_I_SRS.at(5).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			break;

		case ROTATE::LEFT:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_I_SRS.at(6).at(i).at(1)).at(now_x - 1 + BLOCK_I_SRS.at(6).at(i).at(0)) == 0 &&
					   game_field.at(now_y - 1 - BLOCK_I_SRS.at(6).at(i).at(1)).at(now_x + BLOCK_I_SRS.at(6).at(i).at(0)) == 0 &&
					   game_field.at(now_y - 1 - BLOCK_I_SRS.at(6).at(i).at(1)).at(now_x + 1 + BLOCK_I_SRS.at(6).at(i).at(0)) == 0 &&
					   game_field.at(now_y - 1 - BLOCK_I_SRS.at(6).at(i).at(1)).at(now_x + 2 + BLOCK_I_SRS.at(6).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - BLOCK_I_SRS.at(7).at(i).at(1)).at(now_x - 1 + BLOCK_I_SRS.at(7).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_I_SRS.at(7).at(i).at(1)).at(now_x + BLOCK_I_SRS.at(7).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_I_SRS.at(7).at(i).at(1)).at(now_x + 1 + BLOCK_I_SRS.at(7).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_I_SRS.at(7).at(i).at(1)).at(now_x + 2 + BLOCK_I_SRS.at(7).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			break;
		}
		break;

	case BLOCKSHAPE::O:
		break;

	case BLOCKSHAPE::T:
		switch(_rotation)
		{
		case ROTATE::SPAWN:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(0).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(0).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(0).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(0).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						new_x = now_x + BLOCK_JLSTZ_SRS.at(0).at(i).at(0);
						new_y = now_y - BLOCK_JLSTZ_SRS.at(0).at(i).at(1);
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(1).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(1).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(1).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(1).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						new_x = now_x + BLOCK_JLSTZ_SRS.at(1).at(i).at(0);
						new_y = now_y - BLOCK_JLSTZ_SRS.at(1).at(i).at(1);
						break;
					}
				}
			}
			break;

		case ROTATE::RIGHT:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(3).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(3).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(3).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(3).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						new_x = now_x + BLOCK_JLSTZ_SRS.at(3).at(i).at(0);
						new_y = now_y - BLOCK_JLSTZ_SRS.at(3).at(i).at(1);
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(2).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(2).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(2).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(2).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						new_x = now_x + BLOCK_JLSTZ_SRS.at(2).at(i).at(0);
						new_y = now_y - BLOCK_JLSTZ_SRS.at(2).at(i).at(1);
						break;
					}
				}
			}
			break;

		case ROTATE::TWICE:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(5).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(5).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(5).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(5).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						new_x = now_x + BLOCK_JLSTZ_SRS.at(5).at(i).at(0);
						new_y = now_y - BLOCK_JLSTZ_SRS.at(5).at(i).at(1);
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(4).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(4).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(4).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(4).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						new_x = now_x + BLOCK_JLSTZ_SRS.at(4).at(i).at(0);
						new_y = now_y - BLOCK_JLSTZ_SRS.at(4).at(i).at(1);
						break;
					}
				}
			}
			break;

		case ROTATE::LEFT:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(7).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(7).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(7).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(7).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						new_x = now_x + BLOCK_JLSTZ_SRS.at(7).at(i).at(0);
						new_y = now_y - BLOCK_JLSTZ_SRS.at(7).at(i).at(1);
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(6).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(6).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(6).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(6).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						new_x = now_x + BLOCK_JLSTZ_SRS.at(6).at(i).at(0);
						new_y = now_y - BLOCK_JLSTZ_SRS.at(6).at(i).at(1);
						break;
					}
				}
			}
			break;
		}
		break;

	case BLOCKSHAPE::S:
		switch(_rotation)
		{
		case ROTATE::SPAWN:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(0).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(0).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(0).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(0).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(1).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(1).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(1).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(1).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			break;

		case ROTATE::RIGHT:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(3).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(3).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(3).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(3).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(2).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(2).at(i).at(0)) == 0 &&
					   game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(2).at(i).at(0)) == 0 &&
					   game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(2).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			break;

		case ROTATE::TWICE:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(5).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(5).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(5).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(5).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(4).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(4).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(4).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(4).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			break;

		case ROTATE::LEFT:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(7).at(i).at(0)) == 0 &&
					   game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(7).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(7).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(7).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(6).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(6).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(6).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(6).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			break;
		}
		break;

	case BLOCKSHAPE::Z:
		switch(_rotation)
		{
		case ROTATE::SPAWN:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(0).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(0).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(0).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(0).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(1).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(1).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(1).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(1).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			break;

		case ROTATE::RIGHT:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(3).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(3).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(3).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(3).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(2).at(i).at(0)) == 0 &&
					   game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(2).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(2).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(2).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			break;

		case ROTATE::TWICE:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(5).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(5).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(5).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(5).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(4).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(4).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(4).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(4).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			break;

		case ROTATE::LEFT:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(7).at(i).at(0)) == 0 &&
					   game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(7).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(7).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(7).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(6).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(6).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(6).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(6).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			break;
		}
		break;

	case BLOCKSHAPE::J:
		switch(_rotation)
		{
		case ROTATE::SPAWN:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(0).at(i).at(0)) == 0 &&
					   game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(0).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(0).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(0).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(1).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(1).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(1).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(1).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			break;

		case ROTATE::RIGHT:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(3).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(3).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(3).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(3).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(2).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(2).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(2).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(2).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			break;

		case ROTATE::TWICE:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(5).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(5).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(5).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(5).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(4).at(i).at(0)) == 0 &&
					   game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(4).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(4).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(4).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			break;

		case ROTATE::LEFT:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(7).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(7).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(7).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(7).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(6).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(6).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(6).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(6).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			break;
		}
		break;

	case BLOCKSHAPE::L:
		switch(_rotation)
		{
		case ROTATE::SPAWN:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(0).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(0).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(0).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(0).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(1).at(i).at(0)) == 0 &&
					   game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(1).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(1).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(1).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			break;

		case ROTATE::RIGHT:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(3).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(3).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(3).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(3).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(2).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(2).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(2).at(i).at(0)) == 0 &&
					   game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(2).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			break;

		case ROTATE::TWICE:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(5).at(i).at(0)) == 0 &&
					   game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(5).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(5).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(5).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(4).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(4).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(4).at(i).at(0)) == 0 &&
					   game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(4).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			break;

		case ROTATE::LEFT:
			if(_rotate_direction == ROTATE::CLOCKWISE)
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(7).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(7).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(7).at(i).at(0)) == 0 &&
					   game_field.at(now_y - 1 - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(7).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			else
			{
				for(int i = 0; i < SRS_TEST_COUNT; i++)
				{
					if(game_field.at(now_y + 1 - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(6).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)).at(now_x - 1 + BLOCK_JLSTZ_SRS.at(6).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)).at(now_x + BLOCK_JLSTZ_SRS.at(6).at(i).at(0)) == 0 &&
					   game_field.at(now_y - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)).at(now_x + 1 + BLOCK_JLSTZ_SRS.at(6).at(i).at(0)) == 0)
					{
						result.at(i) = true;
						break;
					}
				}
			}
			break;
		}
		break;
	}

	if(result.at(0) || result.at(1) || result.at(2) || result.at(3) || result.at(4))
	{
		if(_shape == BLOCKSHAPE::T)
		{
			int occupied_corner_count = 0;

			if(game_field.at(new_y - 1).at(new_x - 1) != 0) occupied_corner_count++;
			if(game_field.at(new_y - 1).at(new_x + 1) != 0) occupied_corner_count++;
			if(game_field.at(new_y + 1).at(new_x - 1) != 0) occupied_corner_count++;
			if(game_field.at(new_y + 1).at(new_x - 1) != 0) occupied_corner_count++;

			if(occupied_corner_count >= 3)
			{
				isTSpin = true;

				if(MoveOK(now_tetromino->GetShape(), now_tetromino->GetRotation(), MOVE::UP) ||
				   MoveOK(now_tetromino->GetShape(), now_tetromino->GetRotation(), MOVE::LEFT) ||
				   MoveOK(now_tetromino->GetShape(), now_tetromino->GetRotation(), MOVE::RIGHT) ||
				   MoveOK(now_tetromino->GetShape(), now_tetromino->GetRotation(), MOVE::DOWN))
					isMiniTSpin = true;
			}
			else
			{
				isTSpin = false;
				isMiniTSpin = false;
			}
		}
		else
		{
			isTSpin = false;
			isMiniTSpin = false;
		}
	}

	return result;
}

void Tetris::SetBlockRandomGeneratorList()
{
	for(auto iter = std::begin(next_block_array); iter != std::end(next_block_array);)
	{
		std::array<BLOCKSHAPE, 7> inner_generator = {BLOCKSHAPE::I, BLOCKSHAPE::O, BLOCKSHAPE::T, BLOCKSHAPE::S, BLOCKSHAPE::Z, BLOCKSHAPE::J, BLOCKSHAPE::L};

		std::shuffle(std::begin(inner_generator), std::end(inner_generator), dre);

		int _n = 7;

		while(_n--)
		{
			*iter = inner_generator.at(_n);
			iter++;
		}
	}

	next_block_index = 0;
}
Tetromino* Tetris::LoadNextBlock()
{
	Tetromino* rt = nullptr;

	if(next_block_index >= next_block_array.size())
		SetBlockRandomGeneratorList();

	switch(next_block_array.at(next_block_index++))
	{
		case BLOCKSHAPE::I: rt = new TetrominoI(); break;
		case BLOCKSHAPE::O: rt = new TetrominoO(); break;
		case BLOCKSHAPE::T: rt = new TetrominoT(); break;
		case BLOCKSHAPE::S: rt = new TetrominoS(); break;
		case BLOCKSHAPE::Z: rt = new TetrominoZ(); break;
		case BLOCKSHAPE::J: rt = new TetrominoJ(); break;
		case BLOCKSHAPE::L: rt = new TetrominoL(); break;
	}

	return rt;
}
void Tetris::BlockHold()
{
	if(hold_tetromino == nullptr)
	{
		now_tetromino->UnDraw();
		now_tetromino->SetRotation(ROTATE::SPAWN);
		now_tetromino->SetPosition(DrawPositionToPosition({HOLD_BLOCK_X, HOLD_BLOCK_Y}));

		switch(now_tetromino->GetShape())
		{
		case BLOCKSHAPE::I: hold_tetromino = new TetrominoI(); break;
		case BLOCKSHAPE::O: hold_tetromino = new TetrominoO(); break;
		case BLOCKSHAPE::T: hold_tetromino = new TetrominoT(); break;
		case BLOCKSHAPE::S: hold_tetromino = new TetrominoS(); break;
		case BLOCKSHAPE::Z: hold_tetromino = new TetrominoZ(); break;
		case BLOCKSHAPE::J: hold_tetromino = new TetrominoJ(); break;
		case BLOCKSHAPE::L: hold_tetromino = new TetrominoL(); break;
		}

		hold_tetromino->SetPosition(now_tetromino->GetPosition());
		hold_tetromino->Draw();

		PlayNextBlock();
	}
	else
	{
		now_tetromino->UnDraw();
		hold_tetromino->UnDraw();
		std::swap(now_tetromino, hold_tetromino);
		
		hold_tetromino->SetPosition(DrawPositionToPosition({HOLD_BLOCK_X, HOLD_BLOCK_Y}));
		hold_tetromino->SetRotation(ROTATE::SPAWN);

		now_tetromino->SetPosition(DrawPositionToPosition({SPAWNING_BLOCK_X, SPAWNING_BLOCK_Y}));
		now_tetromino->SetRotation(ROTATE::SPAWN);
		ghost_tetromino->SetPosition(now_tetromino->GetPosition());
		ghost_tetromino->SetRotation(now_tetromino->GetRotation());
		ghost_tetromino->SetShape(now_tetromino->GetShape());

		hold_tetromino->Draw();
	}

	canHold = false;
}

void Tetris::GameUpdate()
{
	if(isBlockLock)
	{
		BlockLocking();
		LineClear();
		Scoring();
		LevelUpCheck();
		PlayNextBlock();

		isBlockLock = false;
		isTSpin = false;
	}

	ghost_tetromino->UnDraw();
	now_tetromino->UnDraw();

	if(block_down_frame_count >= block_down_frame)
	{
		BlockFrameDown();
		block_down_frame_count = 0.0;
	}

	ReadKeyInput();
	GhostBlockCalculation();
}
void Tetris::BlockFrameDown()
{
	if(MoveOK(now_tetromino->GetShape(), now_tetromino->GetRotation(), MOVE::DOWN))
	{
		now_tetromino->Move(MOVE::DOWN);

		if(!MoveOK(now_tetromino->GetShape(), now_tetromino->GetRotation(), MOVE::DOWN))
			lock_delay_start = gClock::now();
	}
	else
	{
		lock_delay_counter = std::chrono::duration_cast<gFrame>(gClock::now() - lock_delay_start);
		
		if(lock_delay_counter.count() >= lock_delay_frame)
			isBlockLock = true;
	}
}
void Tetris::ReadKeyInput()
{
	// Clockwise rotation
	if(GetAsyncKeyState(VK_UP) & 0x8000)
	{
		if(!isPressed_UP)
		{
			isPressed_UP = true;

			auto result_array = RotateOK(now_tetromino->GetShape(), now_tetromino->GetRotation(), ROTATE::CLOCKWISE);

			if(result_array.at(0) || result_array.at(1) || result_array.at(2) || result_array.at(3) || result_array.at(4))
			{
				lock_delay_start = gClock::now();
				now_tetromino->Rotate(ROTATE::CLOCKWISE, result_array);
			}
		}
	}
	else
		isPressed_UP = false;

	// Move right
	if(GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		if(!isPressed_RIGHT)
		{
			isPressed_RIGHT = true;

			if(MoveOK(now_tetromino->GetShape(), now_tetromino->GetRotation(), MOVE::RIGHT))
			{
				isTSpin = false;
				lock_delay_start = gClock::now();
				now_tetromino->Move(MOVE::RIGHT);
			}
		}
	}
	else
		isPressed_RIGHT = false;

	// Move down, soft drop
	if(GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		if(!isPressed_DOWN)
		{
			isPressed_DOWN = true;

			if(MoveOK(now_tetromino->GetShape(), now_tetromino->GetRotation(), MOVE::DOWN))
			{
				isTSpin = false;
				
				if(!MoveOK(now_tetromino->GetShape(), now_tetromino->GetRotation(), MOVE::DOWN))
					lock_delay_start = gClock::now();
				
				now_tetromino->Move(MOVE::DOWN);
				player_score += 1;
			}
		}
	}
	else
		isPressed_DOWN = false;

	// Move left
	if(GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		if(!isPressed_LEFT)
		{
			isPressed_LEFT = true;

			if(MoveOK(now_tetromino->GetShape(), now_tetromino->GetRotation(), MOVE::LEFT))
			{
				isTSpin = false;
				lock_delay_start = gClock::now();
				now_tetromino->Move(MOVE::LEFT);
			}
		}
	}
	else
		isPressed_LEFT = false;

	// Hard drop
	if(GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		if(!isPressed_SPACE_BAR)
		{
			isPressed_SPACE_BAR = true;

			player_score += (ghost_tetromino->GetPosition().second - now_tetromino->GetPosition().second) * 2;
			now_tetromino->SetPosition(ghost_tetromino->GetPosition());

			isBlockLock = true;
		}
	}
	else
		isPressed_SPACE_BAR = false;

	// Hold
	if(GetAsyncKeyState(VK_SHIFT) & 0x8000)
	{
		if(!isPressed_SHIFT)
		{
			isPressed_SHIFT = true;

			if(canHold)
				BlockHold();
		}
	}
	else
		isPressed_SHIFT = false;

	// Counterclockwise rotation
	if(GetAsyncKeyState(VK_LCONTROL) & 0x8000)
	{
		if(!isPressed_CTRL)
		{
			isPressed_CTRL = true;

			auto result_array = RotateOK(now_tetromino->GetShape(), now_tetromino->GetRotation(), ROTATE::COUNTERCLOCKWISE);

			if(result_array.at(0) || result_array.at(1) || result_array.at(2) || result_array.at(3) || result_array.at(4))
			{
				lock_delay_start = gClock::now();
				now_tetromino->Rotate(ROTATE::COUNTERCLOCKWISE, result_array);
			}
		}
	}
	else
		isPressed_CTRL = false;

	// Clockwise rotation
	if(GetAsyncKeyState(static_cast<int>('X')) & 0x8000)
	{
		if(!isPressed_X)
		{
			isPressed_X = true;

			auto result_array = RotateOK(now_tetromino->GetShape(), now_tetromino->GetRotation(), ROTATE::CLOCKWISE);

			if(result_array.at(0) || result_array.at(1) || result_array.at(2) || result_array.at(3) || result_array.at(4))
			{
				lock_delay_start = gClock::now();
				now_tetromino->Rotate(ROTATE::CLOCKWISE, result_array);
			}
		}
	}
	else
		isPressed_X = false;

	// Hold
	if(GetAsyncKeyState(static_cast<int>('C')) & 0x8000)
	{
		if(!isPressed_C)
		{
			isPressed_C = true;

			if(canHold)
				BlockHold();
		}
	}
	else
		isPressed_C = false;

	// Counterclockwise rotation
	if(GetAsyncKeyState(static_cast<int>('Z')) & 0x8000)
	{
		if(!isPressed_Z)
		{
			isPressed_Z = true;

			auto result_array = RotateOK(now_tetromino->GetShape(), now_tetromino->GetRotation(), ROTATE::COUNTERCLOCKWISE);

			if(result_array.at(0) || result_array.at(1) || result_array.at(2) || result_array.at(3) || result_array.at(4))
			{
				lock_delay_start = gClock::now();
				now_tetromino->Rotate(ROTATE::COUNTERCLOCKWISE, result_array);
			}
		}
	}
	else
		isPressed_Z = false;

	if(GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		if(!isPressed_ESC)
			isPressed_ESC = true;
	}
	else
		isPressed_ESC = false;

	if(GetAsyncKeyState(VK_F1) & 0x8000)
	{
		if(!isPressed_F1)
			isPressed_F1 = true;
	}
	else
		isPressed_F1 = false;
}
void Tetris::GhostBlockCalculation()
{
	const int now_x = now_tetromino->GetPosition().first;
	int now_y = now_tetromino->GetPosition().second;

	switch(now_tetromino->GetShape())
	{
		case BLOCKSHAPE::I:
			switch(now_tetromino->GetRotation())
			{
				case ROTATE::SPAWN:
					while(game_field.at(now_y + 1).at(now_x - 1) == 0 &&
						  game_field.at(now_y + 1).at(now_x) == 0 &&
						  game_field.at(now_y + 1).at(now_x + 1) == 0 &&
						  game_field.at(now_y + 1).at(now_x + 2) == 0) now_y++;
					break;

				case ROTATE::RIGHT:
					while(game_field.at(now_y + 3).at(now_x) == 0) now_y++;
					break;

				case ROTATE::TWICE:
					while(game_field.at(now_y + 1).at(now_x - 2) == 0 &&
						  game_field.at(now_y + 1).at(now_x - 1) == 0 &&
						  game_field.at(now_y + 1).at(now_x) == 0 &&
						  game_field.at(now_y + 1).at(now_x + 1) == 0) now_y++;
					break;

				case ROTATE::LEFT:
					while(game_field.at(now_y + 2).at(now_x) == 0) now_y++;
					break;
			}
			break;

		case BLOCKSHAPE::O:
			while(game_field.at(now_y + 1).at(now_x) == 0 &&
				  game_field.at(now_y + 1).at(now_x + 1) == 0) now_y++;
			break;

		case BLOCKSHAPE::T:
			switch(now_tetromino->GetRotation())
			{
				case ROTATE::SPAWN:
					while(game_field.at(now_y + 1).at(now_x - 1) == 0 &&
						  game_field.at(now_y + 1).at(now_x) == 0 &&
						  game_field.at(now_y + 1).at(now_x + 1) == 0) now_y++;
					break;

				case ROTATE::RIGHT:
					while(game_field.at(now_y + 2).at(now_x) == 0 &&
						  game_field.at(now_y + 1).at(now_x + 1) == 0) now_y++;
					break;

				case ROTATE::TWICE:
					while(game_field.at(now_y + 1).at(now_x - 1) == 0 &&
						  game_field.at(now_y + 2).at(now_x) == 0 &&
						  game_field.at(now_y + 1).at(now_x + 1) == 0) now_y++;
					break;

				case ROTATE::LEFT:
					while(game_field.at(now_y + 1).at(now_x - 1) == 0 &&
						  game_field.at(now_y + 2).at(now_x) == 0) now_y++;
					break;
			}
			break;

		case BLOCKSHAPE::S:
			switch(now_tetromino->GetRotation())
			{
				case ROTATE::SPAWN:
					while(game_field.at(now_y + 1).at(now_x - 1) == 0 &&
						  game_field.at(now_y + 1).at(now_x) == 0 &&
						  game_field.at(now_y).at(now_x + 1) == 0) now_y++;
					break;

				case ROTATE::RIGHT:
					while(game_field.at(now_y + 1).at(now_x) == 0 &&
						  game_field.at(now_y + 2).at(now_x + 1) == 0) now_y++;
					break;

				case ROTATE::TWICE:
					while(game_field.at(now_y + 2).at(now_x - 1) == 0 &&
						  game_field.at(now_y + 2).at(now_x) == 0 &&
						  game_field.at(now_y + 1).at(now_x + 1) == 0) now_y++;
					break;

				case ROTATE::LEFT:
					while(game_field.at(now_y + 1).at(now_x - 1) == 0 &&
						  game_field.at(now_y + 2).at(now_x) == 0) now_y++;
					break;
			}
			break;

		case BLOCKSHAPE::Z:
			switch(now_tetromino->GetRotation())
			{
				case ROTATE::SPAWN:
					while(game_field.at(now_y).at(now_x - 1) == 0 &&
						  game_field.at(now_y + 1).at(now_x) == 0 &&
						  game_field.at(now_y + 1).at(now_x + 1) == 0) now_y++;
					break;

				case ROTATE::RIGHT:
					while(game_field.at(now_y + 2).at(now_x) == 0 &&
						  game_field.at(now_y + 1).at(now_x + 1) == 0) now_y++;
					break;

				case ROTATE::TWICE:
					while(game_field.at(now_y + 1).at(now_x - 1) == 0 &&
						  game_field.at(now_y + 2).at(now_x) == 0 &&
						  game_field.at(now_y + 2).at(now_x + 1) == 0) now_y++;
					break;

				case ROTATE::LEFT:
					while(game_field.at(now_y + 2).at(now_x - 1) == 0 &&
						  game_field.at(now_y + 1).at(now_x) == 0) now_y++;
					break;
			}
			break;

		case BLOCKSHAPE::J:
			switch(now_tetromino->GetRotation())
			{
				case ROTATE::SPAWN:
					while(game_field.at(now_y + 1).at(now_x - 1) == 0 &&
						  game_field.at(now_y + 1).at(now_x) == 0 &&
						  game_field.at(now_y + 1).at(now_x + 1) == 0) now_y++;
					break;

				case ROTATE::RIGHT:
					while(game_field.at(now_y + 2).at(now_x) == 0 &&
						  game_field.at(now_y).at(now_x + 1) == 0) now_y++;
					break;

				case ROTATE::TWICE:
					while(game_field.at(now_y + 1).at(now_x - 1) == 0 &&
						  game_field.at(now_y + 1).at(now_x) == 0 &&
						  game_field.at(now_y + 2).at(now_x + 1) == 0) now_y++;
					break;

				case ROTATE::LEFT:
					while(game_field.at(now_y + 2).at(now_x - 1) == 0 &&
						  game_field.at(now_y + 2).at(now_x) == 0) now_y++;
					break;
			}
			break;

		case BLOCKSHAPE::L:
			switch(now_tetromino->GetRotation())
			{
				case ROTATE::SPAWN:
					while(game_field.at(now_y + 1).at(now_x - 1) == 0 &&
						  game_field.at(now_y + 1).at(now_x) == 0 &&
						  game_field.at(now_y + 1).at(now_x + 1) == 0) now_y++;
					break;

				case ROTATE::RIGHT:
					while(game_field.at(now_y + 2).at(now_x) == 0 &&
						  game_field.at(now_y + 2).at(now_x + 1) == 0) now_y++;
					break;

				case ROTATE::TWICE:
					while(game_field.at(now_y + 2).at(now_x - 1) == 0 &&
						  game_field.at(now_y + 1).at(now_x) == 0 &&
						  game_field.at(now_y + 1).at(now_x + 1) == 0) now_y++;
					break;

				case ROTATE::LEFT:
					while(game_field.at(now_y).at(now_x - 1) == 0 &&
						  game_field.at(now_y + 2).at(now_x) == 0) now_y++;
					break;
			}
			break;
	}

	ghost_tetromino->SetPosition({now_x, now_y});
	ghost_tetromino->SetRotation(now_tetromino->GetRotation());
}
void Tetris::BlockLocking()
{
	const int now_x = now_tetromino->GetPosition().first;
	const int now_y = now_tetromino->GetPosition().second;

	switch(now_tetromino->GetShape())
	{
		case BLOCKSHAPE::I:
			switch(now_tetromino->GetRotation())
			{
				case ROTATE::SPAWN:
					game_field.at(now_y).at(now_x - 1) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y).at(now_x + 1) = 1;
					game_field.at(now_y).at(now_x + 2) = 1;
					game_field_color.at(now_y).at(now_x - 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I);
					game_field_color.at(now_y).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I);
					game_field_color.at(now_y).at(now_x + 2) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I);
					break;

				case ROTATE::RIGHT:
					game_field.at(now_y - 1).at(now_x) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y + 1).at(now_x) = 1;
					game_field.at(now_y + 2).at(now_x) = 1;
					game_field_color.at(now_y - 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I);
					game_field_color.at(now_y + 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I);
					game_field_color.at(now_y + 2).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I);
					break;

				case ROTATE::TWICE:
					game_field.at(now_y).at(now_x - 2) = 1;
					game_field.at(now_y).at(now_x - 1) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y).at(now_x + 1) = 1;
					game_field_color.at(now_y).at(now_x - 2) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I);
					game_field_color.at(now_y).at(now_x - 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I);
					game_field_color.at(now_y).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I);
					break;

				case ROTATE::LEFT:
					game_field.at(now_y - 2).at(now_x) = 1;
					game_field.at(now_y - 1).at(now_x) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y + 1).at(now_x) = 1;
					game_field_color.at(now_y - 2).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I);
					game_field_color.at(now_y - 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I);
					game_field_color.at(now_y + 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I);
					break;
			}
			break;

		case BLOCKSHAPE::O:
			game_field.at(now_y).at(now_x) = 1;
			game_field.at(now_y).at(now_x + 1) = 1;
			game_field.at(now_y - 1).at(now_x) = 1;
			game_field.at(now_y - 1).at(now_x + 1) = 1;
			game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_O);
			game_field_color.at(now_y).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_O);
			game_field_color.at(now_y - 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_O);
			game_field_color.at(now_y - 1).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_O);
			break;

		case BLOCKSHAPE::T:
			switch(now_tetromino->GetRotation())
			{
				case ROTATE::SPAWN:
					game_field.at(now_y).at(now_x - 1) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y).at(now_x + 1) = 1;
					game_field.at(now_y - 1).at(now_x) = 1;
					game_field_color.at(now_y).at(now_x - 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_T);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_T);
					game_field_color.at(now_y).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_T);
					game_field_color.at(now_y - 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_T);
					break;

				case ROTATE::RIGHT:
					game_field.at(now_y - 1).at(now_x) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y + 1).at(now_x) = 1;
					game_field.at(now_y).at(now_x + 1) = 1;
					game_field_color.at(now_y - 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_T);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_T);
					game_field_color.at(now_y + 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_T);
					game_field_color.at(now_y).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_T);
					break;

				case ROTATE::TWICE:
					game_field.at(now_y).at(now_x - 1) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y).at(now_x + 1) = 1;
					game_field.at(now_y + 1).at(now_x) = 1;
					game_field_color.at(now_y).at(now_x - 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_T);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_T);
					game_field_color.at(now_y).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_T);
					game_field_color.at(now_y + 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_T);
					break;

				case ROTATE::LEFT:
					game_field.at(now_y - 1).at(now_x) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y + 1).at(now_x) = 1;
					game_field.at(now_y).at(now_x - 1) = 1;
					game_field_color.at(now_y - 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_T);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_T);
					game_field_color.at(now_y + 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_T);
					game_field_color.at(now_y).at(now_x - 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_T);
					break;
			}
			break;

		case BLOCKSHAPE::S:
			switch(now_tetromino->GetRotation())
			{
				case ROTATE::SPAWN:
					game_field.at(now_y).at(now_x - 1) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y - 1).at(now_x) = 1;
					game_field.at(now_y - 1).at(now_x + 1) = 1;
					game_field_color.at(now_y).at(now_x - 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_S);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_S);
					game_field_color.at(now_y - 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_S);
					game_field_color.at(now_y - 1).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_S);
					break;

				case ROTATE::RIGHT:
					game_field.at(now_y - 1).at(now_x) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y).at(now_x + 1) = 1;
					game_field.at(now_y + 1).at(now_x + 1) = 1;
					game_field_color.at(now_y - 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_S);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_S);
					game_field_color.at(now_y).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_S);
					game_field_color.at(now_y + 1).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_S);
					break;

				case ROTATE::TWICE:
					game_field.at(now_y + 1).at(now_x - 1) = 1;
					game_field.at(now_y + 1).at(now_x) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y).at(now_x + 1) = 1;
					game_field_color.at(now_y + 1).at(now_x - 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_S);
					game_field_color.at(now_y + 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_S);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_S);
					game_field_color.at(now_y).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_S);
					break;

				case ROTATE::LEFT:
					game_field.at(now_y - 1).at(now_x - 1) = 1;
					game_field.at(now_y).at(now_x - 1) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y + 1).at(now_x) = 1;
					game_field_color.at(now_y - 1).at(now_x - 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_S);
					game_field_color.at(now_y).at(now_x - 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_S);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_S);
					game_field_color.at(now_y + 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_S);
					break;
			}
			break;

		case BLOCKSHAPE::Z:
			switch(now_tetromino->GetRotation())
			{
				case ROTATE::SPAWN:
					game_field.at(now_y - 1).at(now_x - 1) = 1;
					game_field.at(now_y - 1).at(now_x) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y).at(now_x + 1) = 1;
					game_field_color.at(now_y - 1).at(now_x - 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_Z);
					game_field_color.at(now_y - 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_Z);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_Z);
					game_field_color.at(now_y).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_Z);
					break;

				case ROTATE::RIGHT:
					game_field.at(now_y - 1).at(now_x + 1) = 1;
					game_field.at(now_y).at(now_x + 1) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y + 1).at(now_x) = 1;
					game_field_color.at(now_y - 1).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_Z);
					game_field_color.at(now_y).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_Z);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_Z);
					game_field_color.at(now_y + 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_Z);
					break;

				case ROTATE::TWICE:
					game_field.at(now_y).at(now_x - 1) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y + 1).at(now_x) = 1;
					game_field.at(now_y + 1).at(now_x + 1) = 1;
					game_field_color.at(now_y).at(now_x - 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_Z);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_Z);
					game_field_color.at(now_y + 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_Z);
					game_field_color.at(now_y + 1).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_Z);
					break;

				case ROTATE::LEFT:
					game_field.at(now_y - 1).at(now_x) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y).at(now_x - 1) = 1;
					game_field.at(now_y + 1).at(now_x - 1) = 1;
					game_field_color.at(now_y - 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_Z);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_Z);
					game_field_color.at(now_y).at(now_x - 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_Z);
					game_field_color.at(now_y + 1).at(now_x - 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_Z);
					break;
			}
			break;

		case BLOCKSHAPE::J:
			switch(now_tetromino->GetRotation())
			{
				case ROTATE::SPAWN:
					game_field.at(now_y - 1).at(now_x - 1) = 1;
					game_field.at(now_y).at(now_x - 1) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y).at(now_x + 1) = 1;
					game_field_color.at(now_y - 1).at(now_x - 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_J);
					game_field_color.at(now_y).at(now_x - 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_J);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_J);
					game_field_color.at(now_y).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_J);
					break;

				case ROTATE::RIGHT:
					game_field.at(now_y + 1).at(now_x) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y - 1).at(now_x) = 1;
					game_field.at(now_y - 1).at(now_x + 1) = 1;
					game_field_color.at(now_y + 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_J);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_J);
					game_field_color.at(now_y - 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_J);
					game_field_color.at(now_y - 1).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_J);
					break;

				case ROTATE::TWICE:
					game_field.at(now_y).at(now_x - 1) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y).at(now_x + 1) = 1;
					game_field.at(now_y + 1).at(now_x + 1) = 1;
					game_field_color.at(now_y).at(now_x - 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_J);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_J);
					game_field_color.at(now_y).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_J);
					game_field_color.at(now_y + 1).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_J);
					break;

				case ROTATE::LEFT:
					game_field.at(now_y + 1).at(now_x - 1) = 1;
					game_field.at(now_y + 1).at(now_x) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y - 1).at(now_x) = 1;
					game_field_color.at(now_y + 1).at(now_x - 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_J);
					game_field_color.at(now_y + 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_J);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_J);
					game_field_color.at(now_y - 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_J);
					break;
			}
			break;

		case BLOCKSHAPE::L:
			switch(now_tetromino->GetRotation())
			{
				case ROTATE::SPAWN:
					game_field.at(now_y).at(now_x - 1) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y).at(now_x + 1) = 1;
					game_field.at(now_y - 1).at(now_x + 1) = 1;
					game_field_color.at(now_y).at(now_x - 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_L);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_L);
					game_field_color.at(now_y).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_L);
					game_field_color.at(now_y - 1).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_L);
					break;

				case ROTATE::RIGHT:
					game_field.at(now_y - 1).at(now_x) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y + 1).at(now_x) = 1;
					game_field.at(now_y + 1).at(now_x + 1) = 1;
					game_field_color.at(now_y - 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_L);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_L);
					game_field_color.at(now_y + 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_L);
					game_field_color.at(now_y + 1).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_L);
					break;

				case ROTATE::TWICE:
					game_field.at(now_y).at(now_x - 1) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y).at(now_x + 1) = 1;
					game_field.at(now_y + 1).at(now_x - 1) = 1;
					game_field_color.at(now_y).at(now_x - 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_L);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_L);
					game_field_color.at(now_y).at(now_x + 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_L);
					game_field_color.at(now_y + 1).at(now_x - 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_L);
					break;

				case ROTATE::LEFT:
					game_field.at(now_y - 1).at(now_x - 1) = 1;
					game_field.at(now_y - 1).at(now_x) = 1;
					game_field.at(now_y).at(now_x) = 1;
					game_field.at(now_y + 1).at(now_x) = 1;
					game_field_color.at(now_y - 1).at(now_x - 1) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_L);
					game_field_color.at(now_y - 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_L);
					game_field_color.at(now_y).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_L);
					game_field_color.at(now_y + 1).at(now_x) = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_L);
					break;
			}
			break;
	}

	if(isBlockInDeadZone())
		game_status = GAME_STATUS::GAME_OVER;
}
void Tetris::LineClear()
{
	int clear_count = 0;
	const int now_y = now_tetromino->GetPosition().second;
	const int check_st = (BLOCK_MOVEABLE_TOP + 4 >= now_y - 2 ? BLOCK_MOVEABLE_TOP + 4 : now_y - 2);
	const int check_ed = (BLOCK_MOVEABLE_BOTTOM <= now_y + 2 ? BLOCK_MOVEABLE_BOTTOM : now_y + 2);

	isSingle = isDouble = isTriple = isTetris = false;

	for(int i = check_st; i <= check_ed; i++)
	{
		bool isClearLine = true;

		for(int j = BLOCK_MOVEABLE_LEFT; j <= BLOCK_MOVEABLE_RIGHT; j++)
		{
			if(game_field.at(i).at(j) != 1)
			{
				isClearLine = false;
				break;
			}
		}

		if(isClearLine)
		{
			for(int j = BLOCK_MOVEABLE_LEFT; j <= BLOCK_MOVEABLE_RIGHT; j++)
			{
				game_field.at(i).at(j) = 0;
				WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + (j * BLOCK_SIZE_X), i + STAGE_FIELD_TOP);
				std::cout << "  ";
			}

			for(int j = i; j > BLOCK_MOVEABLE_TOP; j--)
			{
				for(int k = BLOCK_MOVEABLE_LEFT; k <= BLOCK_MOVEABLE_RIGHT; k++)
				{
					game_field.at(j).at(k) = game_field.at(j - 1).at(k);
					game_field_color.at(j).at(k) = game_field_color.at(j - 1).at(k);
					WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + (k * BLOCK_SIZE_X), (j - 1) + STAGE_FIELD_TOP);
					std::cout << "  ";

					if(game_field.at(j).at(k) == 1)
					{
						WindowConsoleControl::SETTEXTCOLOR(game_field_color.at(j).at(k), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
						WindowConsoleControl::SETPOSITION(STAGE_FIELD_LEFT + (k * BLOCK_SIZE_X), j + STAGE_FIELD_TOP);
						std::cout << "■";
					}
				}
			}

			clear_count++;
		}
	}

	switch(clear_count)
	{
		case 1:
			isSingle = true;
			break;

		case 2:
			isDouble = true;
			break;

		case 3:
			isTriple = true;
			break;

		case 4:
			isTetris = true;
			break;
	}
}
void Tetris::Scoring()
{
	int basic_score = 0;
	int delete_line = 0;

	if(isSingle)
	{
		combo_count++;

		if(isTSpin)
		{
			if(isMiniTSpin)
			{
				basic_score = 200;
				delete_line = 2;
			}
			else
			{
				basic_score = 800;
				delete_line = 8;
			}

			if(isPrevBTB)
				isBTB = true;
			else
				isBTB = false;

			isPrevBTB = true;
		}
		else
		{
			basic_score = 100;
			delete_line = 1;

			isBTB = false;
			isPrevBTB = false;
		}
	}
	else if(isDouble)
	{
		combo_count++;

		if(isTSpin)
		{
			if(isMiniTSpin)
			{
				basic_score = 600;
				delete_line = 6;
			}
			else
			{
				basic_score = 1200;
				delete_line = 12;
			}

			if(isPrevBTB)
				isBTB = true;
			else
				isBTB = false;

			isPrevBTB = true;
		}
		else
		{
			basic_score = 300;
			delete_line = 3;

			isBTB = false;
			isPrevBTB = false;
		}
	}
	else if(isTriple)
	{
		combo_count++;

		if(isTSpin)
		{
			basic_score = 1600;
			delete_line = 16;

			if(isPrevBTB)
				isBTB = true;
			else
				isBTB = false;

			isPrevBTB = true;
		}
		else
		{
			basic_score = 500;
			delete_line = 5;

			isBTB = false;
			isPrevBTB = false;
		}
	}
	else if(isTetris)
	{
		combo_count++;
		basic_score = 800;
		delete_line = 8;

		if(isPrevBTB)
			isBTB = true;
		else
			isBTB = false;

		isPrevBTB = true;
	}
	else
	{
		combo_count = 0;
		delete_line = 0;

		if(isTSpin)
		{
			// T-Spin mini
			if(isMiniTSpin)
			{
				basic_score = 100;
				delete_line = 1;
			}
			// T-Spin
			else
			{
				basic_score = 400;
				delete_line = 4;
			}

			if(isPrevBTB)
				isBTB = true;
			else
				isBTB = false;

			isPrevBTB = true;
		}
	}

	remain_line = remain_line - static_cast<int>(isBTB ? delete_line * 1.5 : delete_line);
	player_score += (static_cast<int>(isBTB ? basic_score * 1.5 : basic_score) + (combo_count == 0 ? 0 : combo_count - 1) * 50) * player_level;
	ShowScoreInfo();
}
void Tetris::LevelUpCheck()
{
	if(remain_line <= 0)
	{
		player_level = player_level + 1;
		remain_line = player_level * 5;
		block_down_frame = pow((0.8l - ((player_level - 1) * 0.007l)), player_level - 1) * 30;

		WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_LEVEL_UP), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
		WindowConsoleControl::SETPOSITION(LEVEL_UP_SHOW_X, LEVEL_UP_SHOW_Y);
		std::cout << "UP!";
	}
	else
	{
		WindowConsoleControl::SETPOSITION(LEVEL_UP_SHOW_X, LEVEL_UP_SHOW_Y);
		std::cout << "   ";
	}
}
void Tetris::ShowScoreInfo() const
{
	if(isSingle)
	{
		WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_SINGLE), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
		WindowConsoleControl::SETPOSITION(LINE_CLEAR_SHOW_X, LINE_CLEAR_SHOW_Y);
		std::cout << "Single!";
	}
	else if(isDouble)
	{
		WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_DOUBLE), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
		WindowConsoleControl::SETPOSITION(LINE_CLEAR_SHOW_X, LINE_CLEAR_SHOW_Y);
		std::cout << "Double!";
	}
	else if(isTriple)
	{
		WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_TRIPLE), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
		WindowConsoleControl::SETPOSITION(LINE_CLEAR_SHOW_X, LINE_CLEAR_SHOW_Y);
		std::cout << "Triple!";
	}
	else if(isTetris)
	{
		WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_TETRIS), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
		WindowConsoleControl::SETPOSITION(LINE_CLEAR_SHOW_X, LINE_CLEAR_SHOW_Y);
		std::cout << "TETRIS!";
	}
	else
	{
		WindowConsoleControl::SETPOSITION(LINE_CLEAR_SHOW_X, LINE_CLEAR_SHOW_Y);
		std::cout << "       ";
	}

	if(isTSpin)
	{
		WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_TSPIN), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
		WindowConsoleControl::SETPOSITION(TSPIN_SHOW_X, TSPIN_SHOW_Y);
		std::cout << "T-Spin";

		if(isMiniTSpin)
		{
			WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_MINI), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
			WindowConsoleControl::SETPOSITION(MINI_SHOW_X, MINI_SHOW_Y);
			std::cout << "mini";
		}
		else
		{
			WindowConsoleControl::SETPOSITION(MINI_SHOW_X, MINI_SHOW_Y);
			std::cout << "    ";
		}
	}
	else
	{
		WindowConsoleControl::SETPOSITION(TSPIN_SHOW_X, TSPIN_SHOW_Y);
		std::cout << "      ";
		WindowConsoleControl::SETPOSITION(MINI_SHOW_X, MINI_SHOW_Y);
		std::cout << "    ";
	}

	if(isBTB && (isSingle || isDouble || isTriple || isTetris))
	{
		WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BTB), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
		WindowConsoleControl::SETPOSITION(BTB_SHOW_X, BTB_SHOW_Y);
		std::cout << "Back-to-Back";
	}
	else
	{
		WindowConsoleControl::SETPOSITION(BTB_SHOW_X, BTB_SHOW_Y);
		std::cout << "            ";
	}

	if(combo_count > 1)
	{
		WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_COMBO), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
		WindowConsoleControl::SETPOSITION(COMBO_SHOW_X, COMBO_SHOW_Y);
		std::cout << combo_count - 1 << " combo!";
	}
	else
	{
		WindowConsoleControl::SETPOSITION(COMBO_SHOW_X, COMBO_SHOW_Y);
		std::cout << "         ";
	}
}
bool Tetris::isBlockInDeadZone() const
{
	int result = false;

	for(int i = BLOCK_MOVEABLE_TOP + 3; i >= BLOCK_MOVEABLE_TOP; i--)
	{
		for(int j = BLOCK_MOVEABLE_LEFT; j <= BLOCK_MOVEABLE_RIGHT ; j++)
		{
			if(game_field.at(i).at(j) == 1)
			{
				result = true;
				break;
			}
		}

		if(result)
			break;
	}

	return result;
}
void Tetris::PlayNextBlock()
{
	delete now_tetromino;
	next1_tetromino->UnDraw();
	next2_tetromino->UnDraw();
	next3_tetromino->UnDraw();

	now_tetromino = next1_tetromino;
	next1_tetromino = next2_tetromino;
	next2_tetromino = next3_tetromino;
	next3_tetromino = LoadNextBlock();

	next1_tetromino->SetPosition(DrawPositionToPosition({NEXT1_BLOCK_X, NEXT1_BLOCK_Y}));
	next2_tetromino->SetPosition(DrawPositionToPosition({NEXT2_BLOCK_X, NEXT2_BLOCK_Y}));
	next3_tetromino->SetPosition(DrawPositionToPosition({NEXT3_BLOCK_X, NEXT3_BLOCK_Y}));

	next1_tetromino->Draw();
	next2_tetromino->Draw();
	next3_tetromino->Draw();

	now_tetromino->SetPosition(DrawPositionToPosition({SPAWNING_BLOCK_X, SPAWNING_BLOCK_Y}));
	ghost_tetromino->SetShape(now_tetromino->GetShape());
	ghost_tetromino->SetPosition(DrawPositionToPosition({SPAWNING_BLOCK_X, SPAWNING_BLOCK_Y}));

	canHold = true;
}

void Tetris::GameRender() const
{
	DrawScore();
	DrawLevel();
	DrawRemainLine();
	ghost_tetromino->Draw();
	now_tetromino->Draw();
}
void Tetris::DrawLevel() const
{
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_INTERFACE), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(LEVEL_X, LEVEL_Y);

	std::cout << std::setw(2) << player_level;
}
void Tetris::DrawScore() const
{
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_INTERFACE), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(SCORE_X, SCORE_Y);

	std::stringstream score_with_number;
	score_with_number.imbue(std::locale(""));
	score_with_number << std::fixed << player_score;
	std::cout << std::setw(7) << score_with_number.str();
}
void Tetris::DrawRemainLine() const
{
	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_INTERFACE), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));
	WindowConsoleControl::SETPOSITION(REMAIN_LINE_SHOW_X, REMAIN_LINE_SHOW_Y);
	
	std::cout<< std::setw(3) << remain_line;
}

void Tetris::Play()
{
	InitGame();
	DrawInterface();
	StartCount();

	SoundManager::GetInstance()->SoundPlay(SOUND_PLAY_BACKGROUND);

	now_tetromino = LoadNextBlock();
	now_tetromino->SetPosition(DrawPositionToPosition({SPAWNING_BLOCK_X, SPAWNING_BLOCK_Y}));

	ghost_tetromino = new TetrominoGhost(now_tetromino->GetPosition(), now_tetromino->GetShape(), now_tetromino->GetRotation());
	GhostBlockCalculation();

	next1_tetromino = LoadNextBlock();
	next1_tetromino->SetPosition(DrawPositionToPosition({NEXT1_BLOCK_X, NEXT1_BLOCK_Y}));
	next1_tetromino->Draw();

	next2_tetromino = LoadNextBlock();
	next2_tetromino->SetPosition(DrawPositionToPosition({NEXT2_BLOCK_X, NEXT2_BLOCK_Y}));
	next2_tetromino->Draw();

	next3_tetromino = LoadNextBlock();
	next3_tetromino->SetPosition(DrawPositionToPosition({NEXT3_BLOCK_X, NEXT3_BLOCK_Y}));
	next3_tetromino->Draw();

	auto frame_start = gClock::now();
	gFrame frame_counter;

	while(game_status == GAME_STATUS::GAME_PLAYING)
	{
		auto now_frame_point = gClock::now();
		frame_counter = std::chrono::duration_cast<gFrame>(now_frame_point - frame_start);

		if(frame_counter.count() >= 1.0)
		{
			frame_start = now_frame_point;
			block_down_frame_count++;

			SoundManager::GetInstance()->SoundUpdate();
			GameUpdate();
			GameRender();
		}
	}
}

void Tetris::Intro()
{
	InitIntro();
	DrawIntro();
}
void Tetris::Menu()
{
	int sel_menu;
	while(true)
	{
		DrawMenu();
		sel_menu = MenuSelect();

		switch(sel_menu)
		{
		case 0:
			Play();
			break;

		case 1:
			break;

		case 2:
			DrawHelp();
			break;

		case 3:
			return;
		}
	}
}