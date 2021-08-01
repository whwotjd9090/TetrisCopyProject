#include "SoundManager.hpp"

SoundManager* SoundManager::instance = nullptr;

SoundManager::SoundManager(){}
SoundManager::~SoundManager(){}

void SoundManager::InstanceDestroy()
{
	for(int i = 0; i < SOUND_COUNT; i++)
	{
		if(instance->fSound.at(i))
			instance->fSound.at(i)->release();
	}

	if(instance->fSystem)
	{
		instance->fSystem->release();
		instance->fSystem->close();
	}
	delete instance;
}

SoundManager* SoundManager::GetInstance()
{
	if(instance == nullptr)
	{
		instance = new SoundManager();
		atexit(InstanceDestroy);
	}

	return instance;
}

void SoundManager::SoundInit()
{
	ErrorCheck(FMOD::System_Create(&fSystem));
	ErrorCheck(fSystem->getVersion(&version));

	if(version >= FMOD_VERSION)
		ErrorCheck(fSystem->init(SOUND_COUNT, FMOD_INIT_NORMAL, nullptr));
}

void SoundManager::SoundLoading()
{
	ErrorCheck(fSystem->createSound("sounds/intro_background.mp3", FMOD_LOOP_NORMAL, nullptr, &fSound.at(SOUND_INTRO_BACKGROUND)));
	ErrorCheck(fSystem->createSound("sounds/start_count.mp3", FMOD_LOOP_OFF, nullptr, &fSound.at(SOUND_START_COUNT)));
	ErrorCheck(fSystem->createSound("sounds/play_background.mp3", FMOD_LOOP_NORMAL, nullptr, &fSound.at(SOUND_PLAY_BACKGROUND)));
}

void SoundManager::SoundUpdate()
{
	ErrorCheck(fSystem->update());
}

void SoundManager::SoundPlay(SOUND _sound)
{
	ErrorCheck(fSystem->playSound(fSound.at(_sound), nullptr, false, &fChannel.at(_sound)));
}

void SoundManager::SoundStop(SOUND _sound)
{
	fChannel.at(_sound)->stop();
}

void SoundManager::ErrorCheck(FMOD_RESULT _fmod_result)
{
	if(_fmod_result != FMOD_OK)
	{
		TCHAR szStr[256] = {};
		MultiByteToWideChar(CP_ACP, NULL, FMOD_ErrorString(_fmod_result), -1, szStr, 256);
		MessageBox(NULL, szStr, L"Sound Error", MB_OK);
	}
}