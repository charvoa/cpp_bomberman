//
// Bomb.cpp for bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed May 27 15:01:37 2015 Nicolas Girardot
// Last update Thu May 28 13:56:00 2015 Nicolas Girardot
//

#include "Bomb.hh"

Sound&	Bomb::_sound = Sound::getInstance();

Bomb::Bomb(Position& pos, World *world)
{
  _world = world;
  _pos = pos;
  _isPosed = false;
  this->initialize("hello");
  this->onDrop();
}

Bomb::~Bomb()
{

}

bool	Bomb::initialize(const std::string &tex)
{
  (void) tex;
  _bomb = new ModelLoad();
  _bomb->initialize("LibBomberman_linux_x64/assets/bomb.fbx");
  glm::vec3 trans(0 + (_pos._x - _world->getWidth() / 2) * 100, 0, 750 * (-1) + (_pos._y - _world->getHeight() / 2 * 100));
  _bomb->translate(trans);
  return (true);
}

void	Bomb::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void) input;
  if (_isPosed == true)
    _timer += clock.getElapsed();
  if (_timer >= 3)
    this->onDestroy();
}

void	Bomb::draw(gdl::Clock const  &clock, gdl::BasicShader& shader)
{
  _bomb->draw(shader, clock);
}

void	Bomb::onDrop()
{
  _timer = 0;
  _isPosed = true;
}

bool	Bomb::getStatus()
{
   return (!_isDestroyed);
}

void	Bomb::onDestroy()
{
  _isDestroyed = true;
}
