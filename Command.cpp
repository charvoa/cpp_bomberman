//
// Command.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed May 27 15:36:27 2015 Nicolas Charvoz
// Last update Sun Jun 14 12:46:59 2015 Audibert Louis
//

#include "Command.hh"

Sound&  Command::_sound = Sound::getInstance();

Command::Command(Game *game, World *world, const std::string& str)
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
  _functions[InputManager::ENTER] = &Command::enter;
  _selectChar = false;
  _pause = false;
  _mute = false;
  _twoPlayers = false;
  if (str == "PAUSE")
    _pause = true;
  else if (str == "SELECTCHAR")
    _selectChar = true;
  else if (str == "GAMEOVER")
    _gameOver = true;
  if ( _world && _world->getHumansPlayers().size() > 1)
    _twoPlayers = true;
}

Command::~Command(){}

void Command::no(gdl::Clock& clock)
{
  (void) clock;
}

void Command::space(gdl::Clock& clock)
{
  (void) clock;
  if (_world)
    {
      if (_pause)
	return;
      if (_world->getPlayerById(1))
	_world->getPlayerById(1)->dropBomb();
    }
}

void Command::lshift(gdl::Clock& clock)
{
  (void) clock;
  if (_pause)
      return;
  if (_twoPlayers && _world->getPlayerById(2))
    _world->getPlayerById(2)->dropBomb();
}

void Command::pause(gdl::Clock& clock)
{
  (void) clock;
  if (_world)
    {
      _game->pushState(new Pause(_game, _world));
      _pause = true;
    }
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

  _pause = false;
  if (_gameOver)
    return;
  if (!_world)
    _game->popState();
}

void Command::up(gdl::Clock& clock)
{
  if (_world)
    {
      if (_pause)
	return;
      if (_twoPlayers && _world->getPlayerById(2))
	_world->getPlayerById(2)->move(UP, clock);
    }
}

void Command::left(gdl::Clock& clock)
{
  if (_world)
    {
      if (_pause)
	return;
      if (_twoPlayers && _world->getPlayerById(2))
	_world->getPlayerById(2)->move(RIGHT, clock);
    }
}

void Command::right(gdl::Clock& clock)
{
if (_world)
    {
      if (_pause)
	return;
      if (_twoPlayers && _world->getPlayerById(2))
	_world->getPlayerById(2)->move(LEFT, clock);
    }
}

void Command::down(gdl::Clock& clock)
{
 if (_world)
    {
      if (_pause)
	return;
      if (_twoPlayers && _world->getPlayerById(2))
	_world->getPlayerById(2)->move(DOWN, clock);
    }
}

void Command::up2(gdl::Clock& clock)
{
  if (_world)
    {
      if (_pause == true)
	return;
      if (_world->getPlayerById(1) && _pause == false)
	_world->getPlayerById(1)->move(UP, clock);
    }
}

void Command::left2(gdl::Clock& clock)
{
 if (_world)
    {
      if (_pause == true)
	return;
      if (_world->getPlayerById(1) && _pause == false)
	_world->getPlayerById(1)->move(RIGHT, clock);
    }
}

void Command::right2(gdl::Clock& clock)
{
 if (_world)
    {
      if (_pause == true)
	return;
      if (_world->getPlayerById(1) && _pause == false)
	_world->getPlayerById(1)->move(LEFT, clock);
    }
}

void Command::down2(gdl::Clock& clock)
{
  if (_world)
    {
      if (_pause == true)
	return;
      if (_world->getPlayerById(1) && _pause == false)
	_world->getPlayerById(1)->move(DOWN, clock);
    }
}

void Command::enter(gdl::Clock& clock)
{
  (void) clock;
  if (_selectChar)
    std::cout << "lol" << std::endl;
}

void Command::exec(InputManager::touche touche, gdl::Clock& clock)
{
  (*this.*_functions[touche])(clock);
}
