//
// SoundManager.hh for SoundManager in /home/antgar/rendu/cpp_bomberman/Sound
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Wed May 13 03:58:34 2015 Antoine Garcia
// Last update Wed May 13 05:09:51 2015 Antoine Garcia
//

#include <map>
#include <string>
#include "./inc/fmod.h"

class	Sound
{
  std::map<std::string, std::string> _sounds;
  Sound(){};
  ~Sound(){};
  Sound(Sound const&);
  Sound&	operator=(Sound&);
  FMOD_SYSTEM	*_system;
public:
  static Sound&	getInstance();
  void		initialize();
  void		registerSound(const std::string &filename, const std::string &title);
  void		playMusic(const std::string &title);
};
