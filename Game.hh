//
// Game.hh for Game in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Mon Apr 27 05:04:52 2015 Antoine Garcia
// Last update Fri Jun 12 11:27:16 2015 Audibert Louis
//

#ifndef GAME_HH_
# define GAME_HH_

#include "GameState.hh"
#include "AObject.hh"
#include "Menu.hh"
#include "Sound/SoundManager.hh"
#include "Camera.hh"
#include "Random.hh"
#include "Intro.hh"
#include <stack>
#include <Game.hh>
#include <SdlContext.hh>
#include <Clock.hh>
#include <Input.hh>
#include <BasicShader.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

class	Game: public gdl::Game
{
  std::stack<GameState*> _states;
  gdl::SdlContext	_context;
  gdl::Input		_input;
  gdl::Clock		_clock;
  gdl::BasicShader		_shader;
  static Sound&	_sound;
  std::vector<AObject *> _objects;
public:
  Game();
  ~Game();
  virtual bool update();
  virtual bool initialize();
  virtual void draw();
  void		pushState(GameState *state);
  void		popState();
  void		changeState(GameState * state);
  GameState*		peekState();
  gdl::BasicShader	getShader();
  // ~Game();
  void	run();
  Camera		*_camera;
  void		flushContext();
};

#endif
