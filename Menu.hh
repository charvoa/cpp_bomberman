//
// Menu.hh for Menu in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri May  8 13:41:57 2015 Antoine Garcia
// Last update Fri May 15 16:10:01 2015 Nicolas Charvoz
//

#ifndef MENU_HH_
# define MENU_HH_

#include "./Sound/SoundManager.hh"
#include "GameState.hh"
#include "Button.hh"
#include <OpenGL.hh>
#include <iostream>
#include <Texture.hh>

class	Menu: public GameState
{

public:
  Menu(Game *game);
  virtual void draw(gdl::Clock, gdl::BasicShader);
  virtual bool update(gdl::Clock, gdl::Input);
  ~Menu();
  void drawBackground();
  void drawButtons();
  void drawOneButton(std::string, int, int);

private:
  static Sound&	_sound;
};

#endif
