//
// SoundManager.cpp for SoundManager in /home/antgar/rendu/cpp_bomberman/Sound
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Wed May 13 03:57:20 2015 Antoine Garcia
// Last update Wed May 27 15:37:02 2015 Antoine Garcia
//

#include <iostream>
#include "SoundManager.hh"
#include "./inc/fmod.h"

Sound&	Sound::getInstance()
{
  static Sound instance;
  return instance;
}

void	Sound::initialize()
{
  FMOD_System_Create(&_system);
  FMOD_System_Init(_system, 32,FMOD_INIT_NORMAL, NULL);
}

void	Sound::registerSound(const std::string &filename, const std::string&title)
{
  _sounds[title] = filename;
}

void	Sound::playMusic(const std::string &title, int repeat)
{
  FMOD_SOUND	*play;
  FMOD_RESULT	result;
  FMOD_CHANNEL	*chan;

  std::cout << _sounds[title].c_str() << std::endl;
  result = FMOD_System_CreateSound(_system, _sounds[title].c_str(), FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &play);
  if (result != FMOD_OK)
    {
      std::cout << "Musique cannot be played !" << std::endl;
    }
  else
    {
      FMOD_System_PlaySound(_system, FMOD_CHANNEL_FREE , play, 0, &chan);
      _plays[title] = chan;
      if (repeat == 1)
	{
	  FMOD_Channel_SetMode(chan, FMOD_LOOP_NORMAL);
	}
    }
}

void	Sound::Pause(const std::string &title)
{
  FMOD_Channel_SetPaused(_plays[title], 1);
}

void	Sound::playSound(const std::string &title)
{
  FMOD_SOUND	*play;
  FMOD_RESULT	result;

  result = FMOD_System_CreateSound(_system, _sounds[title].c_str(), FMOD_HARDWARE | FMOD_2D,  0, &play);
  if (result != FMOD_OK)
    {
      std::cout << "Musique cannot be played !" << std::endl;
    }
  else
    {
      FMOD_System_PlaySound(_system, FMOD_CHANNEL_FREE, play, 0, NULL);
    }
}
