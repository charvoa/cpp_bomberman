//
// Box.cpp for Bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri May 29 15:28:41 2015 Nicolas Girardot
// Last update Mon Jun  8 17:22:57 2015 Nicolas Girardot
//

#include "Box.hh"

Sound &Box::_sound = Sound::getInstance();

Box::Box(Position *pos, World *world)
{
  _world = world;
  _pos = pos;
  _sound.registerSound("./resources/sounds/crush.mp3", "crush");
}

Box::~Box()
{

}

bool	Box::initialize(const std::string &tex)
{
  (void) tex;
  _box = new Cube();
  _box->initialize("./images/model/crate_tex.tga");
  glm::vec3 trans(0 + (_pos->_x - _world->getWidth() / 2) * 100, 0,
		  750 * (-1) + (_pos->_y - _world->getHeight() / 2) * 100);
  _box->translate(trans);
  _box->scale(glm::vec3(100, 100, 100));
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

bool	Box::getStatus()
{
  return (!_isDestroyed);
}

void	Box::onDestroy()
{
  Random *m = new Random(33);
  if (m->getRandom())
    {
      _world->setBonus(*_pos);
    }
  _isDestroyed = true;
  _sound.playMusic("crush");
}

Position&	Box::getPosition() const
{
  return (*_pos);
}
