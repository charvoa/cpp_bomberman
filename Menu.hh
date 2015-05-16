//
// Menu.hh for Menu in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri May  8 13:41:57 2015 Antoine Garcia
<<<<<<< HEAD
// Last update Sat May 16 12:42:57 2015 Nicolas Charvoz
=======
// Last update Fri May 15 23:00:53 2015 Antoine Garcia
>>>>>>> 42db8475b63892dc1337827292cc27fc35e5fe9e
//

#ifndef MENU_HH_
# define MENU_HH_

#include "./Sound/SoundManager.hh"
#include "SelectChar.hh"
#include "Game.hh"
#include "GameState.hh"
#include "Button.hh"
#include <OpenGL.hh>
#include <iostream>
#include <Texture.hh>
#include <SDL/SDL.h>

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
  void getNameOfButton(gdl::Input);

private:
  static Sound&	_sound;
  Button *_buttonGeneral;
  Button *_exitButton;
  Button *_optionsButton;
  Button *_loadButton;
  Button *_leaderboardButton;
  Button *_playButton;

};

#endif
