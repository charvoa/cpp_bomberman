//
// Bomb.cpp for bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed May 27 15:01:37 2015 Nicolas Girardot
// Last update Sun Jun 14 20:00:31 2015 Nicolas Girardot
//

#include "Bomb.hh"

Sound&	Bomb::_sound = Sound::getInstance();

Bomb::Bomb(Position &pos, World *world, int id)
{
  _id = id;
  _world = world;
  _pos = pos;
  _isPosed = false;
  _sound.registerSound("./resources/sounds/explosion.wav", "boum");
}

Bomb::~Bomb()
{

}

bool	Bomb::initialize(const std::string &tex)
{
  Flame *fire;
  int	my_range;
  (void) tex;
  _bomb = new ModelLoad();
  _bomb->initialize("LibBomberman_linux_x64/assets/bomb.fbx");
  glm::vec3 trans(0 + (_pos._x * 100 - _world->getWidth() / 2 * 100), 0, 750 * (-1) + (_pos._y  - _world->getHeight() / 2) * 100);
  if (_world->getPlayerById(_id))
    my_range = _world->getPlayerById(_id)->getRange();
  _bomb->translate(trans);
  _bomb->scale(glm::vec3(0.3, 0.3, 0.3));
  _isPosed = true;
  for (int i = 1; i <= my_range; i++)
    {
      if (_world->getItemAtPosition(_pos._x + i, _pos._y) == 'W')
	break;
      fire = new Flame(new Position(_pos._x + i, _pos._y), _world, _id);
      fire->initialize("hello");
      _flames.push_back(fire);
    }
  for (int i = 1; i <= my_range; i++)
    {
      if (_world->getItemAtPosition(_pos._x, _pos._y - i) == 'W')
	break;
      fire = new Flame(new Position(_pos._x, _pos._y - i), _world, _id);
      fire->initialize("hello");
      _flames.push_back(fire);
    }
  for (int i = 1; i <= my_range; i++)
    {
      if (_world->getItemAtPosition(_pos._x, _pos._y + i) == 'W')
	break;
      fire = new Flame(new Position(_pos._x, _pos._y + i), _world, _id);
      fire->initialize("hello");
      _flames.push_back(fire);
    }
  for (int i = 1; i <= my_range; i++)
    {
      if (_world->getItemAtPosition(_pos._x - i, _pos._y) == 'W')
	break;
      fire = new Flame(new Position(_pos._x - i, _pos._y), _world, _id);
      fire->initialize("hello");
      _flames.push_back(fire);
    }
  fire = new Flame(new Position(_pos._x, _pos._y), _world, _id);
  fire->initialize("hello");
  _flames.push_back(fire);
  return (true);
}

void	Bomb::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void) input;

  if (_isPosed == true)
    {
      _timer += clock.getElapsed();
      // std::cout << _timer << std::endl;
    }
  if (_timer >= 3)
    {
      if (_isPlayed == 0)
	{
	  _sound.playMusic("boum");
	  _isPlayed = 1;
	}
    }
  for (std::list<Flame*>::iterator it = _flames.begin(); it != _flames.end(); ++it)
    {
      (*it)->update(clock, input);
    }
  if (_timer >= 4)
    {
      this->onDestroy();
    }
}

void	Bomb::draw(gdl::AShader& shader ,gdl::Clock const  &clock)
{
  if (_timer <= 3)
    _bomb->draw(shader, clock);
  else
    {
      if (_isPoped == true)
	{
	  _world->checkDamages(_flames);
	  if (_world->getPlayerById(_id) != NULL)
	    _world->getPlayerById(_id)->setCanLaunchBomb(true);
	  _isPoped = false;
	}
      for (std::list<Flame*>::iterator it = _flames.begin(); it != _flames.end(); ++it)
	{
	  (*it)->draw(shader, clock);
	}
    }
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

void	Bomb::setRange(int a)
{
  _range = a;
}

void	Bomb::onDestroy()
{
  _world->setItemAtPosition(_pos, 'F');
  _isDestroyed = true;
}
