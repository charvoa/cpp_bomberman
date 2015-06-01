//
// Bomb.cpp for bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed May 27 15:01:37 2015 Nicolas Girardot
// Last update Mon Jun  1 12:04:12 2015 Audibert Louis
//

#include "Bomb.hh"

Sound&	Bomb::_sound = Sound::getInstance();

Bomb::Bomb(Position* pos, World *world)
{
  _world = world;
  _pos = pos;
  _isPosed = false;
  _sound.registerSound("./resources/sounds/allahu_akbar_and_explosion.wav", "allahu");
  std::cout << "Bomb Is being Droped" << std::endl;
}

Bomb::~Bomb()
{
  std::cout << "i'm being destroyed" << std::endl;
}

bool	Bomb::initialize(const std::string &tex)
{
  (void) tex;
  std::cout << _pos->_x << " " << _pos->_y << std::endl;
  _bomb = new ModelLoad();
  _bomb->initialize("LibBomberman_linux_x64/assets/bomb.fbx");
  glm::vec3 trans(0 + (_pos->_x * 100 - 710), 0, 750 * (-1) + (_pos->_y  - _world->getHeight() / 2) * 100);
  std::cout << _pos->_x * 100 - 750 << " hh " << 750 * (-1) + (_pos->_y - _world->getHeight() / 2) * 100 << std::endl;
  _bomb->translate(trans);
  _bomb->scale(glm::vec3(0.3, 0.3, 0.3));
  _isPosed = true;
  return (true);
}

void	Bomb::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void) input;

  if (_isPosed == true)
    {
      _timer += clock.getElapsed();
      std::cout << _timer << std::endl;
    }
  if (_timer >= 1.5)
    {
      if (_isPlayed == 0)
	{
	  _sound.playMusic("allahu");
	  _isPlayed = 1;
	}
    }
  if (_timer >= 3)
    this->onDestroy();
}

void	Bomb::draw(gdl::AShader& shader ,gdl::Clock const  &clock)
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
