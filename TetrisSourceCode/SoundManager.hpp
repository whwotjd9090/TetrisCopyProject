#pragma once
#include <fmod.hpp>
#include <fmod_errors.h>
#include <cstdlib>
#include <array>
#include <windows.h>

enum SOUND
{
	SOUND_INTRO_BACKGROUND,
	SOUND_START_COUNT,
	SOUND_PLAY_BACKGROUND,
	SOUND_BLOCK_ROTATE,
	SOUND_BLOCK_LOCK,
	SOUND_HARD_DROP,
	SOUND_TSPIN_MINI,
	SOUND_TSPIN,
	SOUND_LINE_CLEAR_SINGLE,
	SOUND_LINE_CLEAR_DOUBLE,
	SOUND_LINE_CLEAR_TRIPLE,
	SOUND_LINE_CLEAR_TETRIS,
	SOUND_LINE_CLEAR_TSPIN,
	SOUND_LINE_CLEAR_TSPIN_DOUBLE,
	SOUND_LINE_CLEAR_TSPIN_TRIPLE,
	SOUND_BACK_TO_BACK,
	SOUND_GAMEOVER,
	SOUND_COUNT
};

class SoundManager
{
private:
	static SoundManager* instance;

	unsigned int version;

	FMOD::System* fSystem;
	std::array<FMOD::Sound*, SOUND_COUNT> fSound;
	std::array<FMOD::Channel*, SOUND_COUNT> fChannel;

	SoundManager();
	~SoundManager();

	static void InstanceDestroy();

public:
	static SoundManager* GetInstance();
	void SoundInit();
	void SoundLoading();
	void SoundUpdate();
	void SoundPlay(SOUND _sound);
	void SoundStop(SOUND _sound);
	void ErrorCheck(FMOD_RESULT _fmod_error);
};

