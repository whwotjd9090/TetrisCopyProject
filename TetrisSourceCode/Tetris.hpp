#pragma once
#ifndef TETRIS_HPP_INCLUDED
#define TETRIS_HPP_INCLUDED
#include "WindowConsoleControl.hpp"
#include "TetrisConstant.hpp"
#include "Tetromino.hpp"
#include "SoundManager.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <random>
#include <chrono>
#include <sstream>
#include <locale>
#include <cmath>
#include <conio.h>

class Tetris
{
private:
	std::random_device rd;
	std::default_random_engine dre;
	std::array<std::array<int, STAGE_FIELD_WIDTH>, STAGE_FIELD_HEIGHT> game_field;
	std::array<std::array<WINDOW_CONSOLE_COLOR, STAGE_FIELD_WIDTH>, STAGE_FIELD_HEIGHT> game_field_color;
	std::array<BLOCKSHAPE, 140> next_block_array;
	using gClock = std::chrono::high_resolution_clock;
	using gFrame = std::chrono::duration<double, std::ratio<1, FRAME_RATE> >;
	std::chrono::time_point<gClock> lock_delay_start;
	gFrame lock_delay_counter;
	GAME_STATUS game_status;

	size_t next_block_index;
	int player_score;
	int player_level;
	int combo_count;
	int remain_line;
	double block_down_frame;
	double block_down_frame_count;
	double lock_delay_frame;

	TetrominoGhost* ghost_tetromino;
	Tetromino* now_tetromino;
	Tetromino* next1_tetromino;
	Tetromino* next2_tetromino;
	Tetromino* next3_tetromino;
	Tetromino* hold_tetromino;

	bool isBlockLock;
	bool isPressed_UP;
	bool isPressed_RIGHT;
	bool isPressed_DOWN;
	bool isPressed_LEFT;
	bool isPressed_SPACE_BAR;
	bool isPressed_SHIFT;
	bool isPressed_CTRL;
	bool isPressed_X;
	bool isPressed_C;
	bool isPressed_Z;
	bool isPressed_ESC;
	bool isPressed_F1;
	bool isPressed_RETURN;
	bool canHold;
	bool isTSpin;
	bool isMiniTSpin;
	bool isSingle;
	bool isDouble;
	bool isTriple;
	bool isTetris;
	bool isBTB;
	bool isPrevBTB;

	void InitIntro() const;
	void DrawIntro() const;
	void DrawMenu() const;
	int MenuSelect();

	void DrawHelp() const;

	void DrawInterface() const;
	void DrawStageField() const;
	void DrawNextField() const;
	void DrawHoldField() const;
	void DrawLevelField() const;
	void DrawScoreField() const;
	void DrawRemainLineField() const;

	void InitGame();
	void StartCount() const;

	bool MoveOK(const BLOCKSHAPE _shape, const ROTATE _rotate, const MOVE _direction);
	std::array<bool, 5> RotateOK(const BLOCKSHAPE _shape, const ROTATE _rotation, const ROTATE _rotate_direction);
	
	void SetBlockRandomGeneratorList();
	Tetromino* LoadNextBlock();
	void BlockHold();
	
	void GameUpdate();
	void BlockFrameDown();
	void ReadKeyInput();
	void GhostBlockCalculation();
	void BlockLocking();
	void LineClear();
	void Scoring();
	void LevelUpCheck();
	void ShowScoreInfo() const;
	bool isBlockInDeadZone() const;
	void PlayNextBlock();

	void GameRender() const;
	void DrawLevel() const;
	void DrawScore() const;
	void DrawRemainLine() const;

	void Play();

public:
	void Intro();
	void Menu();
};

#endif