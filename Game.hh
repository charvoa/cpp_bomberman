//
// Game.hh for Game in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Mon Apr 27 05:04:52 2015 Antoine Garcia
// Last update Fri May  8 14:04:28 2015 Antoine Garcia
//

#ifndef GAME_HH_
# define GAME_HH_


#include <stack>
#include <SdlContext.hh>
#include <Game.hh>
#include <Clock.hh>
#include <Input.hh>
#include <BasicShader.hh>
#include "GameState.hh"
#include "Menu.hh"

class	Game: public gdl::Game
{
  std::stack<GameState*> _states;
  gdl::SdlContext	_context;
  gdl::Input		_input;
  gdl::BasicShader		_shader;
  gdl::Clock		_clock;
public:
  Game();
  virtual bool update();
  virtual bool initialize();
  virtual void draw();
  void		pushState(GameState *state);
  void		popState();
  void		changeState(GameState * state);
  GameState*		peekState();
  // ~Game();
  void	run();
};

#endif
