//
// Command.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed May 27 15:36:27 2015 Nicolas Charvoz
// Last update Thu May 28 16:49:47 2015 Nicolas Charvoz
//

#include "Command.hh"

Sound&  Command::_sound = Sound::getInstance();

Command::Command(Game *game, World *world)
{
  _game = game;
  _world = world;
  _functions[InputManager::NO] = &Command::no;
  _functions[InputManager::PAUSE] = &Command::pause;
  _functions[InputManager::MUTE] = &Command::mute;
  _functions[InputManager::UNMUTE] = &Command::unmute;
  _functions[InputManager::BACK] = &Command::back;
  _functions[InputManager::UP] = &Command::up;
  _functions[InputManager::LEFT] = &Command::left;
  _functions[InputManager::RIGHT] = &Command::right;
  _functions[InputManager::DOWN] = &Command::down;
  _functions[InputManager::UP2] = &Command::up2;
  _functions[InputManager::LEFT2] = &Command::left2;
  _functions[InputManager::RIGHT2] = &Command::right2;
  _functions[InputManager::DOWN2] = &Command::down2;
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
  if (_mute == false)
    {
      std::cout << "mute" << std::endl;
     _sound.Pause("main");
      _mute = true;
    }
}

void Command::unmute()
{
  if (_mute == true)
    {
      std::cout << "unmute" << std::endl;
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
  _world->getPlayerById(1)->move(UP);
}

void Command::left()
{
  _world->getPlayerById(1)->move(RIGHT);
}

void Command::right()
{
 _world->getPlayerById(1)->move(LEFT);
}

void Command::down()
{
 _world->getPlayerById(1)->move(DOWN);
}

void Command::up2()
{
  _world->getPlayerById(2)->move(UP);
}

void Command::left2()
{
  _world->getPlayerById(2)->move(RIGHT);
}

void Command::right2()
{
  _world->getPlayerById(2)->move(LEFT);
}

void Command::down2()
{
  _world->getPlayerById(2)->move(DOWN);
}

void Command::exec(InputManager::touche touche)
{
  (*this.*_functions[touche])();
}
