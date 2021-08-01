#pragma once
#ifndef TETRISCONSTANT_HPP_INCLUDED
#define TETRISCONSTANT_HPP_INCLUDED
#include <array>
#include <utility>

enum class BLOCKSHAPE
{
	I,
	O,
	T,
	S,
	Z,
	J,
	L
};
enum class ROTATE : bool
{
	SPAWN,
	RIGHT,
	TWICE,
	LEFT,
	COUNTERCLOCKWISE,
	CLOCKWISE
};
enum class MOVE
{
	UP,
	RIGHT,
	DOWN,
	LEFT
};
enum class GAME_STATUS
{
	GAME_OVER,
	GAME_PLAYING
};
enum class KEY_INPUT
{
	UP = 1,
	RIGHT = 2,
	DOWN = 4,
	LEFT = 8,
	SPACE_BAR = 16,
	SHIFT = 32,
	CTRL = 64,
	X = 128,
	C = 256,
	Z = 512,
	ESC = 1024,
	F1 = 2048
};

/* CONSOLE_COLOR : ÄÜ¼Ö ±âº» ¹è°æ»ö */
constexpr auto CONSOLE_COLOR_BACKGROUND	= 0x0;
constexpr auto CONSOLE_COLOR_INTERFACE	= 0x7;
constexpr auto CONSOLE_COLOR_SELECTED	= 0xB;
constexpr auto CONSOLE_COLOR_DEADZONE	= 0xC;
constexpr auto CONSOLE_COLOR_I			= 0xB;
constexpr auto CONSOLE_COLOR_O			= 0xE;
constexpr auto CONSOLE_COLOR_T			= 0xD;
constexpr auto CONSOLE_COLOR_S			= 0xA;
constexpr auto CONSOLE_COLOR_Z			= 0xC;
constexpr auto CONSOLE_COLOR_J			= 0x9;
constexpr auto CONSOLE_COLOR_L			= 0x6;
constexpr auto CONSOLE_COLOR_COUNT_3	= 0xB;
constexpr auto CONSOLE_COLOR_COUNT_2	= 0x9;
constexpr auto CONSOLE_COLOR_COUNT_1	= 0xC;
constexpr auto CONSOLE_COLOR_GHOST		= 0x8;
constexpr auto CONSOLE_COLOR_SINGLE		= 0xF;
constexpr auto CONSOLE_COLOR_DOUBLE		= 0xF;
constexpr auto CONSOLE_COLOR_TRIPLE		= 0xF;
constexpr auto CONSOLE_COLOR_TETRIS		= 0xB;
constexpr auto CONSOLE_COLOR_TSPIN		= 0xD;
constexpr auto CONSOLE_COLOR_MINI		= 0xE;
constexpr auto CONSOLE_COLOR_BTB		= 0xA;
constexpr auto CONSOLE_COLOR_COMBO		= 0x6;
constexpr auto CONSOLE_COLOR_LEVEL_UP	= 0x6;
/**/

/* CONSOLE Window Data */
constexpr auto CONSOLE_INTRO_WIDTH		= 450;
constexpr auto CONSOLE_INTRO_HEIGHT		= 300;
constexpr auto CONSOLE_PLAY_WIDTH		= 500;
constexpr auto CONSOLE_PLAY_HEIGHT		= 570;
constexpr auto CONSOLE_HELP_WIDTH		= 650;
constexpr auto CONSOLE_HELP_HEIGHT		= 900;
constexpr auto CONSOLE_FONT_WIDTH		= 0;	// width of each character
constexpr auto CONSOLE_FONT_HEIGHT		= 16;
/**/

/* FRAME_RATE : °ÔÀÓ ÃÊ´ç ÇÁ·¹ÀÓ */
constexpr auto FRAME_RATE_PLAY			= 60;
constexpr auto FRMAE_RATE_GAMEOVER		= 35;
/**/

/* BLOCK_SIZE : È­¸é¿¡¼­ Â÷ÁöÇÏ´Â ºí·° Å©±â */
constexpr auto BLOCK_SIZE_X				= 2;																		// Àý´ñ°ª
constexpr auto BLOCK_SIZE_Y				= 1;																		// Àý´ñ°ª
/**/

/* STAGE_FIELD : GAME_FIELD, DEAD_FIELD, WALLÀ» Æ÷ÇÔÇÑ ±âº»ÀûÀÎ °ÔÀÓ ÇÊµå */
constexpr auto STAGE_FIELD_WIDTH		= 16;																		// Àý´ñ°ª
constexpr auto STAGE_FIELD_HEIGHT		= 27;																		// Àý´ñ°ª
constexpr auto STAGE_FIELD_TOP			= 0;																		// ÄÜ¼Ö ÁÂÇ¥
constexpr auto STAGE_FIELD_BOTTOM		= STAGE_FIELD_TOP + (STAGE_FIELD_HEIGHT - 1) * BLOCK_SIZE_Y;				// ÄÜ¼Ö ÁÂÇ¥
constexpr auto STAGE_FIELD_LEFT			= 12;																		// ÄÜ¼Ö ÁÂÇ¥
constexpr auto STAGE_FIELD_RIGHT		= STAGE_FIELD_LEFT + (STAGE_FIELD_WIDTH - 1) * BLOCK_SIZE_X;				// ÄÜ¼Ö ÁÂÇ¥
/**/

/* WALL : GAME_FIELD¸¦ µÑ·¯½Î°í ÀÖ´Â ºí·° ÀÌµ¿ ÇÑ°è ±¸°£ */
constexpr auto WALL_THICKNESS			= 3;																		// Àý´ñ°ª
constexpr auto WALL_LEFT_TOP			= STAGE_FIELD_TOP;															// ÄÜ¼Ö ÁÂÇ¥
constexpr auto WALL_LEFT_BOTTOM			= STAGE_FIELD_BOTTOM;														// ÄÜ¼Ö ÁÂÇ¥
constexpr auto WALL_LEFT_LEFT			= STAGE_FIELD_LEFT;															// ÄÜ¼Ö ÁÂÇ¥
constexpr auto WALL_LEFT_RIGHT			= STAGE_FIELD_LEFT + (WALL_THICKNESS - 1) * BLOCK_SIZE_X;					// ÄÜ¼Ö ÁÂÇ¥
constexpr auto WALL_RIGHT_TOP			= STAGE_FIELD_TOP;															// ÄÜ¼Ö ÁÂÇ¥
constexpr auto WALL_RIGHT_BOTTOM		= STAGE_FIELD_BOTTOM;														// ÄÜ¼Ö ÁÂÇ¥
constexpr auto WALL_RIGHT_LEFT			= STAGE_FIELD_RIGHT - (WALL_THICKNESS - 1) * BLOCK_SIZE_X;					// ÄÜ¼Ö ÁÂÇ¥
constexpr auto WALL_RIGHT_RIGHT			= STAGE_FIELD_RIGHT;														// ÄÜ¼Ö ÁÂÇ¥
constexpr auto WALL_BOTTOM_TOP			= STAGE_FIELD_BOTTOM - (WALL_THICKNESS - 1);								// ÄÜ¼Ö ÁÂÇ¥
constexpr auto WALL_BOTTOM_BOTTOM		= STAGE_FIELD_BOTTOM;														// ÄÜ¼Ö ÁÂÇ¥
constexpr auto WALL_BOTTOM_LEFT			= STAGE_FIELD_LEFT + WALL_THICKNESS * BLOCK_SIZE_X;							// ÄÜ¼Ö ÁÂÇ¥
constexpr auto WALL_BOTTOM_RIGHT		= STAGE_FIELD_RIGHT - WALL_THICKNESS * BLOCK_SIZE_X;						// ÄÜ¼Ö ÁÂÇ¥
/**/

/* GMAE_FIELD : ºí·° ÀÌµ¿ °¡´É, ºí·° °íÁ¤ °¡´É */
constexpr auto GAME_FIELD_WIDTH			= 10;																		// Àý´ñ°ª
constexpr auto GAME_FIELD_HEIGHT		= 20;																		// Àý´ñ°ª
constexpr auto GAME_FIELD_TOP			= STAGE_FIELD_TOP + (BLOCK_SIZE_Y * 4);										// ÄÜ¼Ö ÁÂÇ¥
constexpr auto GAME_FIELD_BOTTOM		= GAME_FIELD_TOP + (GAME_FIELD_HEIGHT - 1) * BLOCK_SIZE_Y;					// ÄÜ¼Ö ÁÂÇ¥
constexpr auto GAME_FIELD_LEFT			= STAGE_FIELD_LEFT + WALL_THICKNESS * BLOCK_SIZE_X;							// ÄÜ¼Ö ÁÂÇ¥
constexpr auto GAME_FIELD_RIGHT			= GAME_FIELD_LEFT + (GAME_FIELD_WIDTH - 1) * BLOCK_SIZE_X;					// ÄÜ¼Ö ÁÂÇ¥
/**/

/* BLOCK_MOVEABLE : ºí·° ÀÌµ¿ Çã¿ë ¹üÀ§ */
constexpr auto BLOCK_MOVEABLE_TOP		= 0;																		// °ÔÀÓ ÇÊµå ÁÂÇ¥
constexpr auto BLOCK_MOVEABLE_BOTTOM	= 23;																		// °ÔÀÓ ÇÊµå ÁÂÇ¥
constexpr auto BLOCK_MOVEABLE_LEFT		= 3;																		// °ÔÀÓ ÇÊµå ÁÂÇ¥
constexpr auto BLOCK_MOVEABLE_RIGHT		= 12;																		// °ÔÀÓ ÇÊµå ÁÂÇ¥
/**/

/* DEAD_FIELD : ºí·° ÀÌµ¿ °¡´É, ºí·° °íÁ¤ ½Ã °ÔÀÓ ¿À¹ö */
constexpr auto DEAD_FIELD_WIDTH			= GAME_FIELD_WIDTH;															// Àý´ñ°ª
constexpr auto DEAD_FIELD_HEIGHT		= 4;																		// Àý´ñ°ª
constexpr auto DEAD_FIELD_TOP			= STAGE_FIELD_TOP;															// ÄÜ¼Ö ÁÂÇ¥
constexpr auto DEAD_FIELD_BOTTOM		= GAME_FIELD_TOP - BLOCK_SIZE_Y;											// ÄÜ¼Ö ÁÂÇ¥
constexpr auto DEAD_FIELD_LEFT			= GAME_FIELD_LEFT;															// ÄÜ¼Ö ÁÂÇ¥
constexpr auto DEAD_FIELD_RIGHT			= GAME_FIELD_RIGHT;															// ÄÜ¼Ö ÁÂÇ¥
/**/

/* HOLD_FIELD : È¦µå ºí·° Ç¥½Ã */
constexpr auto HOLD_FIELD_WIDTH			= 6;																		// Àý´ñ°ª
constexpr auto HOLD_FIELD_HEIGHT		= 6;																		// Àý´ñ°ª
constexpr auto HOLD_FIELD_TOP			= STAGE_FIELD_TOP;															// ÄÜ¼Ö ÁÂÇ¥
constexpr auto HOLD_FIELD_BOTTOM		= HOLD_FIELD_TOP + (HOLD_FIELD_HEIGHT - 1) * BLOCK_SIZE_Y;					// ÄÜ¼Ö ÁÂÇ¥
constexpr auto HOLD_FIELD_LEFT			= STAGE_FIELD_LEFT - HOLD_FIELD_WIDTH * BLOCK_SIZE_X;						// ÄÜ¼Ö ÁÂÇ¥
constexpr auto HOLD_FIELD_RIGHT			= STAGE_FIELD_LEFT - BLOCK_SIZE_X;											// ÄÜ¼Ö ÁÂÇ¥
/**/

/* NEXT1_FIELD : ´ÙÀ½ Ã¹¹øÂ° ºí·° Ç¥½Ã */
constexpr auto NEXT1_FIELD_WIDTH		= 6;																		// Àý´ñ°ª
constexpr auto NEXT1_FIELD_HEIGHT		= 6;																		// Àý´ñ°ª
constexpr auto NEXT1_FIELD_TOP			= STAGE_FIELD_TOP;															// ÄÜ¼Ö ÁÂÇ¥
constexpr auto NEXT1_FIELD_BOTTOM		= NEXT1_FIELD_TOP + (NEXT1_FIELD_HEIGHT - 1) * BLOCK_SIZE_Y;				// ÄÜ¼Ö ÁÂÇ¥
constexpr auto NEXT1_FIELD_LEFT			= STAGE_FIELD_RIGHT + BLOCK_SIZE_X;											// ÄÜ¼Ö ÁÂÇ¥
constexpr auto NEXT1_FIELD_RIGHT		= NEXT1_FIELD_LEFT + (NEXT1_FIELD_WIDTH - 1) * BLOCK_SIZE_X;				// ÄÜ¼Ö ÁÂÇ¥
/**/

/* NEXT2_FIELD : ´ÙÀ½ µÎ¹øÂ° ºí·° Ç¥½Ã */
constexpr auto NEXT2_FIELD_WIDTH		= 6;																		// Àý´ñ°ª
constexpr auto NEXT2_FIELD_HEIGHT		= 5;																		// Àý´ñ°ª
constexpr auto NEXT2_FIELD_TOP			= NEXT1_FIELD_BOTTOM + BLOCK_SIZE_Y;										// ÄÜ¼Ö ÁÂÇ¥
constexpr auto NEXT2_FIELD_BOTTOM		= NEXT2_FIELD_TOP + (NEXT2_FIELD_HEIGHT - 1) * BLOCK_SIZE_Y;				// ÄÜ¼Ö ÁÂÇ¥
constexpr auto NEXT2_FIELD_LEFT			= NEXT1_FIELD_LEFT;															// ÄÜ¼Ö ÁÂÇ¥
constexpr auto NEXT2_FIELD_RIGHT		= NEXT1_FIELD_RIGHT;														// ÄÜ¼Ö ÁÂÇ¥
/**/

/* NEXT3_FIELD : ´ÙÀ½ ¼¼¹øÀç ºí·° Ç¥½Ã */
constexpr auto NEXT3_FIELD_WIDTH		= 6;																		// Àý´ñ°ª
constexpr auto NEXT3_FIELD_HEIGHT		= 5;																		// Àý´ñ°ª
constexpr auto NEXT3_FIELD_TOP			= NEXT2_FIELD_BOTTOM + BLOCK_SIZE_Y;										// ÄÜ¼Ö ÁÂÇ¥
constexpr auto NEXT3_FIELD_BOTTOM		= NEXT3_FIELD_TOP + (NEXT3_FIELD_HEIGHT - 1) * BLOCK_SIZE_Y;				// ÄÜ¼Ö ÁÂÇ¥
constexpr auto NEXT3_FIELD_LEFT			= NEXT1_FIELD_LEFT;															// ÄÜ¼Ö ÁÂÇ¥
constexpr auto NEXT3_FIELD_RIGHT		= NEXT1_FIELD_RIGHT;														// ÄÜ¼Ö ÁÂÇ¥
/**/

/* LEVEL_FIELD : ÇöÀç ·¹º§ Ç¥½Ã */
constexpr auto LEVEL_FIELD_WIDTH		= 6;																		// Àý´ñ°ª
constexpr auto LEVEL_FIELD_HEIGHT		= 3;																		// Àý´ñ°ª
constexpr auto LEVEL_FIELD_TOP			= HOLD_FIELD_BOTTOM + BLOCK_SIZE_Y;											// ÄÜ¼Ö ÁÂÇ¥
constexpr auto LEVEL_FIELD_BOTTOM		= LEVEL_FIELD_TOP + (LEVEL_FIELD_HEIGHT - 1) * BLOCK_SIZE_Y;				// ÄÜ¼Ö ÁÂÇ¥
constexpr auto LEVEL_FIELD_LEFT			= HOLD_FIELD_LEFT;															// ÄÜ¼Ö ÁÂÇ¥
constexpr auto LEVEL_FIELD_RIGHT		= LEVEL_FIELD_LEFT + LEVEL_FIELD_WIDTH - 1;									// ÄÜ¼Ö ÁÂÇ¥
/**/

/* SCORE_FIELD : ÇöÀç Á¡¼ö Ç¥½Ã */
constexpr auto SCORE_FIELD_WIDTH		= 6;																		// Àý´ñ°ª
constexpr auto SCORE_FIELD_HEIGHT		= 3;																		// Àý´ñ°ª
constexpr auto SCORE_FIELD_TOP			= LEVEL_FIELD_BOTTOM + BLOCK_SIZE_Y;										// ÄÜ¼Ö ÁÂÇ¥
constexpr auto SCORE_FIELD_BOTTOM		= SCORE_FIELD_TOP + (SCORE_FIELD_HEIGHT - 1) * BLOCK_SIZE_Y;				// ÄÜ¼Ö ÁÂÇ¥
constexpr auto SCORE_FIELD_LEFT			= HOLD_FIELD_LEFT;															// ÄÜ¼Ö ÁÂÇ¥
constexpr auto SCORE_FIELD_RIGHT		= SCORE_FIELD_LEFT + SCORE_FIELD_WIDTH - 1;									// ÄÜ¼Ö ÁÂÇ¥
/**/

/* REMAIN_LINE_FIELD : ´ÙÀ½ ·¹º§±îÁö ÇÊ¿ä ¶óÀÎ ¼ö Ç¥½Ã */
constexpr auto REMAIN_LINE_FIELD_WIDTH	= 6;																		// Àý´ñ°ª
constexpr auto REMAIN_LINE_FIELD_HEIGHT	= 3;																		// Àý´ñ°ª
constexpr auto REMAIN_LINE_FIELD_TOP	= SCORE_FIELD_BOTTOM + BLOCK_SIZE_Y * 7;									// ÄÜ¼Ö ÁÂÇ¥
constexpr auto REMAIN_LINE_FIELD_BOTTOM	= REMAIN_LINE_FIELD_TOP + (REMAIN_LINE_FIELD_HEIGHT - 1) * BLOCK_SIZE_Y;	// ÄÜ¼Ö ÁÂÇ¥
constexpr auto REMAIN_LINE_FIELD_LEFT	= HOLD_FIELD_LEFT;															// ÄÜ¼Ö ÁÂÇ¥
constexpr auto REMAIN_LINE_FIELD_RIGHT	= REMAIN_LINE_FIELD_LEFT + REMAIN_LINE_FIELD_WIDTH - 1;						// ÄÜ¼Ö ÁÂÇ¥
/**/

/* °¢Á¾ µ¥ÀÌÅÍ À§Ä¡ */
constexpr auto SPAWNING_BLOCK_X			= GAME_FIELD_LEFT + (GAME_FIELD_WIDTH / 2 - 1) * BLOCK_SIZE_X;				// ÄÜ¼Ö ÁÂÇ¥
constexpr auto SPAWNING_BLOCK_Y			= DEAD_FIELD_BOTTOM;														// ÄÜ¼Ö ÁÂÇ¥
constexpr auto HOLD_BLOCK_X				= HOLD_FIELD_LEFT + 2 * BLOCK_SIZE_X;										// ÄÜ¼Ö ÁÂÇ¥
constexpr auto HOLD_BLOCK_Y				= HOLD_FIELD_TOP + (HOLD_FIELD_HEIGHT / 2) * BLOCK_SIZE_Y;					// ÄÜ¼Ö ÁÂÇ¥
constexpr auto NEXT1_BLOCK_X			= NEXT1_FIELD_LEFT + 2 * BLOCK_SIZE_X;										// ÄÜ¼Ö ÁÂÇ¥
constexpr auto NEXT1_BLOCK_Y			= NEXT1_FIELD_TOP + (NEXT1_FIELD_HEIGHT / 2) * BLOCK_SIZE_Y;				// ÄÜ¼Ö ÁÂÇ¥
constexpr auto NEXT2_BLOCK_X			= NEXT2_FIELD_LEFT + 2 * BLOCK_SIZE_X;										// ÄÜ¼Ö ÁÂÇ¥
constexpr auto NEXT2_BLOCK_Y			= NEXT2_FIELD_TOP + (NEXT2_FIELD_HEIGHT / 2) * BLOCK_SIZE_Y;				// ÄÜ¼Ö ÁÂÇ¥
constexpr auto NEXT3_BLOCK_X			= NEXT3_FIELD_LEFT + 2 * BLOCK_SIZE_X;										// ÄÜ¼Ö ÁÂÇ¥
constexpr auto NEXT3_BLOCK_Y			= NEXT3_FIELD_TOP + (NEXT3_FIELD_HEIGHT / 2) * BLOCK_SIZE_Y;				// ÄÜ¼Ö ÁÂÇ¥
constexpr auto LEVEL_X					= LEVEL_FIELD_LEFT + BLOCK_SIZE_X + 1;										// ÄÜ¼Ö ÁÂÇ¥
constexpr auto LEVEL_Y					= LEVEL_FIELD_TOP + BLOCK_SIZE_Y;											// ÄÜ¼Ö ÁÂÇ¥
constexpr auto SCORE_X					= SCORE_FIELD_LEFT + BLOCK_SIZE_X + 1;										// ÄÜ¼Ö ÁÂÇ¥
constexpr auto SCORE_Y					= SCORE_FIELD_TOP + BLOCK_SIZE_Y;											// ÄÜ¼Ö ÁÂÇ¥
constexpr auto REMAIN_LINE_SHOW_X		= REMAIN_LINE_FIELD_LEFT + 5;												// ÄÜ¼Ö ÁÂÇ¥
constexpr auto REMAIN_LINE_SHOW_Y		= REMAIN_LINE_FIELD_TOP + BLOCK_SIZE_Y;										// ÄÜ¼Ö ÁÂÇ¥
constexpr auto BTB_SHOW_X				= SCORE_FIELD_LEFT + 2;														// ÄÜ¼Ö ÁÂÇ¥
constexpr auto BTB_SHOW_Y				= SCORE_FIELD_BOTTOM + 2 * BLOCK_SIZE_Y;									// ÄÜ¼Ö ÁÂÇ¥
constexpr auto TSPIN_SHOW_X				= SCORE_FIELD_LEFT + 1;														// ÄÜ¼Ö ÁÂÇ¥
constexpr auto TSPIN_SHOW_Y				= BTB_SHOW_Y + BLOCK_SIZE_Y;												// ÄÜ¼Ö ÁÂÇ¥
constexpr auto MINI_SHOW_X				= TSPIN_SHOW_X + 7;															// ÄÜ¼Ö ÁÂÇ¥
constexpr auto MINI_SHOW_Y				= TSPIN_SHOW_Y;																// ÄÜ¼Ö ÁÂÇ¥
constexpr auto LINE_CLEAR_SHOW_X		= SCORE_FIELD_LEFT + 3;														// ÄÜ¼Ö ÁÂÇ¥
constexpr auto LINE_CLEAR_SHOW_Y		= TSPIN_SHOW_Y + BLOCK_SIZE_Y;												// ÄÜ¼Ö ÁÂÇ¥
constexpr auto COMBO_SHOW_X				= SCORE_FIELD_LEFT + 2;														// ÄÜ¼Ö ÁÂÇ¥
constexpr auto COMBO_SHOW_Y				= LINE_CLEAR_SHOW_Y + BLOCK_SIZE_Y;											// ÄÜ¼Ö ÁÂÇ¥
constexpr auto LEVEL_UP_SHOW_X			= LEVEL_FIELD_LEFT + 12;													// ÄÜ¼Ö ÁÂÇ¥
constexpr auto LEVEL_UP_SHOW_Y			= LEVEL_FIELD_TOP + BLOCK_SIZE_Y;											// ÄÜ¼Ö ÁÂÇ¥
/**/

/*
SRS Rotate Offset
0: spawn - initial block rotation position
1: right - rotate right from spawn
2: twice - rotate twice any direction from spawn
3: left - rotate left from spawn

I Tetromino Wall Kick Data
		 Test 1	 Test 2	 Test 3	 Test 4	 Test 5
0>>1	( 0, 0)	(-2, 0)	( 1, 0)	(-2,-1)	( 1, 2)
0>>3	( 0, 0)	(-1, 0)	( 2, 0)	(-1, 2)	( 2,-1)
1>>2	( 0, 0)	(-1, 0)	( 2, 0)	(-1, 2)	( 2,-1)
1>>0	( 0, 0)	( 2, 0)	(-1, 0)	( 2, 1)	(-1,-2)
2>>3	( 0, 0)	( 2, 0)	(-1, 0)	( 2, 1)	(-1,-2)
2>>1	( 0, 0)	( 1, 0)	(-2, 0)	( 1,-2)	(-2, 1)
3>>0	( 0, 0)	( 1, 0)	(-2, 0)	( 1,-2)	(-2, 1)
3>>2	( 0, 0)	(-2, 0)	( 1, 0)	(-2,-1)	( 1, 2)

J, L, S, T, Z Tetromino Wall Kick Data
		 Test 1	 Test 2	 Test 3	 Test 4	 Test 5
0>>1	( 0, 0)	(-1, 0)	(-1, 1)	( 0,-2)	(-1,-2)
0>>3	( 0, 0)	( 1, 0)	( 1, 1)	( 0,-2)	( 1,-2)
1>>0	( 0, 0)	( 1, 0)	( 1,-1)	( 0, 2)	( 1, 2)
1>>2	( 0, 0)	( 1, 0)	( 1,-1)	( 0, 2)	( 1, 2)
2>>1	( 0, 0)	(-1, 0)	(-1, 1)	( 0,-2)	(-1,-2)
2>>3	( 0, 0)	( 1, 0)	( 1, 1)	( 0,-2)	( 1,-2)
3>>2	( 0, 0)	(-1, 0)	(-1,-1)	( 0, 2)	(-1, 2)
3>>0	( 0, 0)	(-1, 0)	(-1,-1)	( 0, 2)	(-1, 2)
/**/
constexpr auto SRS_TEST_COUNT = 5;
constexpr std::array<std::array<std::array<int, 2>, SRS_TEST_COUNT>, 8> BLOCK_I_SRS = {{
	{{{0, 0}, {-2, 0}, {1, 0}, {-2, -1}, {1, 2}}},
	{{{0, 0}, {-1, 0}, {2, 0}, {-1, 2}, {2, -1}}},
	{{{0, 0}, {-1, 0}, {2, 0}, {-1, 2}, {2, -1}}},
	{{{0, 0}, {2, 0}, {-1, 0}, {2, 1}, {-1, -2}}},
	{{{0, 0}, {2, 0}, {-1, 0}, {2, 1}, {-1, -2}}},
	{{{0, 0}, {1, 0}, {-2, 0}, {1, -2}, {-2, 1}}},
	{{{0, 0}, {1, 0}, {-2, 0}, {1, -2}, {-2, 1}}},
	{{{0, 0}, {-2, 0}, {1, 0}, {-2, -1}, {1, 2}}}
}};
constexpr std::array<std::array<std::array<int, 2>, SRS_TEST_COUNT>, 8> BLOCK_JLSTZ_SRS = {{
	{{{0, 0}, {-1, 0}, {-1, 1}, {0, -2}, {-1, -2}}},
	{{{0, 0}, {1, 0}, {1, 1}, {0, -2}, {1, -2}}},
	{{{0, 0}, {1, 0}, {1, -1}, {0, 2}, {1, 2}}},
	{{{0, 0}, {1, 0}, {1, -1}, {0, 2}, {1, 2}}},
	{{{0, 0}, {-1, 0}, {-1, 1}, {0, -2}, {-1, -2}}},
	{{{0, 0}, {1, 0}, {1, 1}, {0, -2}, {1, -2}}},
	{{{0, 0}, {-1, 0}, {-1, -1}, {0, 2}, {-1, 2}}},
	{{{0, 0}, {-1, 0}, {-1, -1}, {0, 2}, {-1, 2}}}
}};
/**/

std::pair<int, int> PositionToDrawPosition(std::pair<int, int> _position);
std::pair<int, int> DrawPositionToPosition(std::pair<int, int> _draw_position);

#endif