//
// Menu.hh for Menu in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri May  8 13:41:57 2015 Antoine Garcia
// Last update Wed May 13 06:54:40 2015 Antoine Garcia
//

#ifndef SELECTCHAR_HH_
# define SELECTCHAR_HH_

#include "./Sound/SoundManager.hh"
#include "GameState.hh"

class	SelectChar: public GameState
{

public:
  SelectChar(Game *game);
  virtual void draw(gdl::Clock, gdl::BasicShader);
  virtual bool update(gdl::Clock, gdl::Input);
  ~SelectChar();
  void drawBackground();
  void drawButtons();

private:
  static Sound&	_sound;
};

#endif
