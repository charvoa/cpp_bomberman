//
// Command.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed May 27 15:36:27 2015 Nicolas Charvoz
// Last update Fri May 29 16:43:34 2015 Nicolas Charvoz
//

#include "Command.hh"

Sound&  Command::_sound = Sound::getInstance();

Command::Command(Game *game, World *world)
{
  _game = game;
  _world = world;
  _functions[InputManager::NO] = &Command::no;
  _functions[InputManager::LSHIFT] = &Command::lshift;
  _functions[InputManager::SPACE] = &Command::space;
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

void Command::no(gdl::Clock& clock)
{
  (void) clock;
}

void Command::space(gdl::Clock& clock)
{
  (void) clock;
  std::cout << "SPACE" << std::endl;
  _world->getPlayerById(2)->dropBomb();
}

void Command::lshift(gdl::Clock& clock)
{
  (void) clock;
  std::cout << "LSHIFT" << std::endl;
  _world->getPlayerById(1)->dropBomb();
}

void Command::pause(gdl::Clock& clock)
{
  (void) clock;
  _game->pushState(new Pause(_game));
  std::cout << "PAUSE" << std::endl;
}

void Command::mute(gdl::Clock& clock)
{
  (void) clock;

  if (_mute == false)
    {
      _sound.Pause("main");
      _mute = true;
    }
}

void Command::unmute(gdl::Clock& clock)
{
  (void) clock;

  if (_mute == true)
    {
      _sound.playSound("main");
      _mute = false;
    }
}

void Command::back(gdl::Clock& clock)
{
  (void) clock;

  if (!_world)
    _game->popState();
}

void Command::up(gdl::Clock& clock)
{
  _world->getPlayerById(2)->move(UP, clock);
}

void Command::left(gdl::Clock& clock)
{
  _world->getPlayerById(2)->move(RIGHT, clock);
}

void Command::right(gdl::Clock& clock)
{
  _world->getPlayerById(2)->move(LEFT, clock);
}

void Command::down(gdl::Clock& clock)
{
  _world->getPlayerById(2)->move(DOWN, clock);
}

void Command::up2(gdl::Clock& clock)
{
  _world->getPlayerById(1)->move(UP, clock);
}

void Command::left2(gdl::Clock& clock)
{
  _world->getPlayerById(1)->move(RIGHT, clock);
}

void Command::right2(gdl::Clock& clock)
{
  _world->getPlayerById(1)->move(LEFT, clock);
}

void Command::down2(gdl::Clock& clock)
{
  _world->getPlayerById(1)->move(DOWN, clock);
}

void Command::exec(InputManager::touche touche, gdl::Clock& clock)
{
  (*this.*_functions[touche])(clock);
}
