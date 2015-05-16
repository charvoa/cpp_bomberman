//
// Options.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:17:24 2015 Nicolas Charvoz
// Last update Sat May 16 15:23:46 2015 Nicolas Charvoz
//

#ifndef LEADERBOARD_HH_
# define LEADERBOARD_HH_

#include "./Sound/SoundManager.hh"
#include "Game.hh"
#include "GameState.hh"

class Leaderboard : public GameState {

public:
  Leaderboard(Game *game);
  virtual void draw(gdl::Clock, gdl::BasicShader);
  virtual bool update(gdl::Clock, gdl::Input);
  ~Leaderboard();
  void drawBackground();
  void drawButtons();

private:
  static Sound& _sound;

};

#endif
