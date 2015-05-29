//
// Box.cpp for Bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri May 29 15:28:41 2015 Nicolas Girardot
// Last update Fri May 29 16:01:31 2015 Nicolas Girardot
//

#include "Box.hh"

Sound &Box::_sound = Sound::getInstance();

Box::Box(Position *pos, World *world)
{
  _world = world;
  _pos = pos;
}

Box::~Box()
{

}

bool	Box::initialize(const, std::string &tex)
{
  _box = new Cube();
  _box->initialize("./images/model/crate_text.tga");
  glm::vec3 trans(0 + (x - _world.getWidth() / 2) * 100, 0,
		  750 * (-1) + (y - _world->getHeight() / 2) * 100);
  _box->translate(trans);
  _box->scale(100, 100, 100);
  return (true);
}

void	Box::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void) clock;
  (void) input;
}

void	Box::draw(gdl::AShader& shader, gdl::Clock const &clock)
{
  _box->draw(shader, clock);
}

bool	getStatus()
{
  return (!_isDestroyed);
}

void	Box::onDestroy()
{
  _isDestroyed = true;
  //jouer son explosion.
}
