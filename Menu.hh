//
// Menu.hh for Menu in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri May  8 13:41:57 2015 Antoine Garcia
// Last update Tue May 12 12:02:55 2015 Nicolas Charvoz
//

#ifndef MENU_HH_
# define MENU_HH_

#include "GameState.hh"
#include "sdlglutils.h"

class	Menu: public GameState
{

public:
  Menu(Game *game);
  virtual void draw(gdl::Clock, gdl::BasicShader);
  virtual bool update(gdl::Clock, gdl::Input);
  ~Menu();
};

#endif
