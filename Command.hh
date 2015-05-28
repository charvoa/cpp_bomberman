//
// Command.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed May 27 15:34:46 2015 Nicolas Charvoz
// Last update Thu May 28 12:11:57 2015 Nicolas Charvoz
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

class Command
{

public:

  static Sound& _sound;
  typedef void(Command::*funcs)();
  funcs _ptr;
  typedef std::map<InputManager::touche, funcs>map_funcs;
  map_funcs     _functions;
  bool _mute;

public:

private:

public:
  Command(Game*);
  ~Command();
  void exec(InputManager::touche);
  void no();
  void pause();
  void mute();
  void unmute();
  void back();
  void up();
  void left();
  void right();
  void down();

  Game *_game;
};

#endif
