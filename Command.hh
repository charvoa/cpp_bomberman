//
// Command.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed May 27 15:34:46 2015 Nicolas Charvoz
// Last update Thu May 28 20:57:12 2015 Nicolas Charvoz
//

#ifndef COMMAND_HH_
# define COMMAND_HH_

# include <fstream>
# include <sstream>
# include <iostream>
# include <vector>
# include <map>
# include "InputManager.hh"
# include "Game.hh"
# include "World.hh"

class Command
{

public:

  static Sound& _sound;
  typedef void(Command::*funcs)(gdl::Clock&);
  funcs _ptr;
  typedef std::map<InputManager::touche, funcs>map_funcs;
  map_funcs     _functions;
  bool _mute;

public:

private:

public:
  Command(Game*, World *world = NULL);
  ~Command();
  void exec(InputManager::touche, gdl::Clock&);
  void no(gdl::Clock&);
  void space(gdl::Clock&);
  void lshift(gdl::Clock&);
  void pause(gdl::Clock&);
  void mute(gdl::Clock&);
  void unmute(gdl::Clock&);
  void back(gdl::Clock&);
  void up(gdl::Clock&);
  void left(gdl::Clock&);
  void right(gdl::Clock&);
  void down(gdl::Clock&);
  void up2(gdl::Clock&);
  void left2(gdl::Clock&);
  void right2(gdl::Clock&);
  void down2(gdl::Clock&);

  Game *_game;
  World *_world;
};

#endif
