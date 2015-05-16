//
// Exit.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:17:24 2015 Nicolas Charvoz
// Last update Sat May 16 15:49:03 2015 Nicolas Charvoz
//

#ifndef EXIT_HH_
# define EXIT_HH_

#include "./Sound/SoundManager.hh"
#include "Game.hh"
#include "GameState.hh"
#include <unistd.h>

class Exit : public GameState {

public:
  Exit(Game *game);
  virtual void draw(gdl::Clock, gdl::BasicShader);
  virtual bool update(gdl::Clock, gdl::Input);
  ~Exit();
  void drawBackground();
  void drawButtons();

private:
  static Sound& _sound;

};

#endif