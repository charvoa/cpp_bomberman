//
// Menu.hh for Menu in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri May  8 13:41:57 2015 Antoine Garcia
// Last update Fri May 22 17:38:45 2015 Nicolas Charvoz
//

#ifndef MENU_HH_
# define MENU_HH_

#include "./Sound/SoundManager.hh"
#include "SelectChar.hh"
#include "TextureManager.hh"
#include "Game.hh"
#include "GameState.hh"
#include "Button.hh"
#include "Options.hh"
#include "Leaderboard.hh"
#include "Load.hh"
#include "Exit.hh"
#include <OpenGL.hh>
#include <iostream>
#include <Texture.hh>
#include <vector>
#include "MenuBackground.hh"
#include "LittleButton.hh"
#include "BigButton.hh"

class	Menu: public GameState
{

public:
  Menu(Game *game);
  virtual void draw(gdl::Clock&, gdl::BasicShader&);
  virtual bool update(gdl::Clock&, gdl::Input&);
  virtual ~Menu();
  void drawBackground();
  void drawButtons();
  void drawOneButton(std::string, int, int);
  void getNameOfButton(gdl::Input&);

private:
  static Sound&	_sound;
  static TextureManager& _texManag;
  std::vector<AObject*> _objects;

};

#endif
