//
// Bonus.cpp for bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Jun  5 15:44:47 2015 Nicolas Girardot
// Last update Mon Jun  8 14:36:19 2015 Nicolas Girardot
//

#include "Bonus.hh"

Bonus::Bonus(Position& pos, World *world)
{
  _world = world;
  _pos = pos;
}

Bonus::~Bonus()
{

}

bool	Bonus::initialize(const std::string &tex)
{
  (void) tex;
  _bonus = new Cube();
  _bonus->initialize("images/bonus.tga");
  glm::vec3 trans(_pos._x * 100 - (_world->getWidth() / 2) * 100, 20, 750 * (-1) + ((_pos._y - _world->getHeight()) / 2 * 100));
  _bonus->translate(trans);
  _bonus->scale(glm::vec3(60, 60, 60));
  return (true);
}

void	Bonus::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void) clock;
  (void) input;
  static float angle = 7;
  _bonus->rotate(glm::vec3(0, 1, 1), angle);
  if (angle == 360.0)
    angle = 0;
}

void	Bonus::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  _bonus->draw(shader, clock);
}
