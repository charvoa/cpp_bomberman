//
// Flame.cpp for bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Mon Jun  1 11:09:17 2015 Nicolas Girardot
// Last update Mon Jun  1 12:51:01 2015 Nicolas Girardot
//

#include "Flame.hh"

Flame::Flame(Position* pos, World *world)
{
  _world = world;
  _pos = pos;
  _isPosed = false;
}

Flame::~Flame() {}

bool	Flame::initialize(const std::string &tex)
{
  (void) tex;
  _flame = new Cube();
  _flame->initialize("images/fire.tga");
  glm::vec3 trans((_pos->_x * 100 - 710), 0, -750 + (_pos->_y - _world->getHeight() / 2) * 100);
  _flame->translate(trans);
  _flame->scale(glm::vec3(100, 100, 100));
  _isPosed = true;
  return (true);
}

void	Flame::update(gdl::Clock const &clock, gdl::Input &input)
{
  std::cout << "timer  = " << _timer  << std::endl;
  (void) input;
  if (_isPosed == true)
    {
      _timer += clock.getElapsed();
    }
  if (_timer >= 3)
    {
      std::cout << "size " <<  100 + (3 - _timer) * 100 << std::endl;
      _flame->scale(glm::vec3(4 - _timer, 4 - _timer, 4 - _timer));
    }
  if (_timer >= 4)
    this->onDestroy();
}

void	Flame::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  _flame->draw(shader, clock);
}

bool	Flame::getStatus()
{
  return (!_isDestroyed);
}

void	Flame::onDestroy()
{
  _isDestroyed = true;
}