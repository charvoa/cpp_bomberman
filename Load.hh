//
// Options.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:17:24 2015 Nicolas Charvoz
// Last update Sat May 16 15:26:52 2015 Nicolas Charvoz
//

#ifndef LOAD_HH_
# define LOAD_HH_

#include "./Sound/SoundManager.hh"
#include "Game.hh"
#include "GameState.hh"

class Load : public GameState {

public:
  Load(Game *game);
  virtual void draw(gdl::Clock, gdl::BasicShader);
  virtual bool update(gdl::Clock, gdl::Input);
  ~Load();
  void drawBackground();
  void drawButtons();

private:
  static Sound& _sound;

};

#endif
