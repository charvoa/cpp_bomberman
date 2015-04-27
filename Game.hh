//
// Game.hh for Game in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Mon Apr 27 05:04:52 2015 Antoine Garcia
// Last update Mon Apr 27 06:05:32 2015 Antoine Garcia
//

#include <SdlContext.hh>
#include <Game.hh>
#include <Clock.hh>
#include <Input.hh>
#include <BasicShader.hh>

class	Game: public gdl::Game
{
  gdl::SdlContext	_context;
  gdl::Input		_input;
  gdl::BasicShader		_shader;
  gdl::Clock		_clock;
public:
  Game();
  virtual bool update();
  virtual bool initialize();
  virtual void draw();
  // ~Game();
  void	run();
};
