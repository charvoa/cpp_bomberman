//
// Command.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed May 27 15:36:27 2015 Nicolas Charvoz
// Last update Wed May 27 17:00:13 2015 Nicolas Charvoz
//

#include "Command.hh"

Sound&  Command::_sound = Sound::getInstance();

Command::Command(Game *game)
{
  _game = game;
  _functions[InputManager::NO] = &Command::no;
  _functions[InputManager::PAUSE] = &Command::pause;
  _functions[InputManager::MUTE] = &Command::mute;
  _functions[InputManager::UNMUTE] = &Command::unmute;
  _functions[InputManager::BACK] = &Command::back;
  _functions[InputManager::UP] = &Command::up;
  _functions[InputManager::LEFT] = &Command::left;
  _functions[InputManager::RIGHT] = &Command::right;
  _functions[InputManager::DOWN] = &Command::down;
  _mute = false;
}

Command::~Command(){}

void Command::no()
{
}

void Command::pause()
{
  std::cout << "PAUSE" << std::endl;
}

void Command::mute()
{
  _sound.Pause("main");
  _mute = true;
}

void Command::unmute()
{
  if (_mute == true)
    {
      _sound.playSound("main");
      _mute = false;
    }
}

void Command::back()
{
  _game->popState();
}

void Command::up()
{
  std::cout << "UP" << std::endl;
}

void Command::left()
{
 std::cout << "LEFT" << std::endl;
}

void Command::right()
{
 std::cout << "right" << std::endl;
}

void Command::down()
{
 std::cout << "down" << std::endl;
}

void Command::exec(InputManager::touche touche)
{
  (*this.*_functions[touche])();
}
