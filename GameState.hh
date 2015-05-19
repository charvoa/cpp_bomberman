//
// GameStateManager.hh for GameStateManager in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri May  8 13:02:07 2015 Antoine Garcia
// Last update Tue May 19 17:58:52 2015 Nicolas Charvoz
//

#ifndef GAMESTATEMANAGER_HH_
# define GAMESTATEMANAGER_HH_
#include <Game.hh>
#include <Clock.hh>
#include <Input.hh>
#include <BasicShader.hh>
class	Game;

class	GameState
{
protected:
  Game	*_game;
public:
  virtual ~GameState();
  virtual void draw(gdl::Clock, gdl::BasicShader) = 0;
  virtual bool update(gdl::Clock, gdl::Input) = 0;
};

#endif
