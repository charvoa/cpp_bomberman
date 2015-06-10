//
// HumanCharacter.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue May 19 11:55:01 2015 Nicolas Charvoz
// Last update Wed Jun 10 14:11:33 2015 Audibert Louis
//

#include <iostream>
#include "HumanCharacter.hh"
#include "World.hh"
#include "Bomb.hh"

TextureManager&	HumanCharacter::_texManag = TextureManager::getInstance();
Sound&	ACharacter::_sound = Sound::getInstance();

HumanCharacter::HumanCharacter(char id, World *world, Position& pos)
{
  int save = (id - '0') % 2;
  _world = world;
  initColor();
  std::cout << "id = " << id << std::endl;
  this->_id = id;
  this->_alive = true;
  _pos = pos;
  if (save == 1)
    _model.load("./images/model/marvin.fbx");
  else
    _model.load("./images/model/GuardSoldier.FBX");
  // if (save == 1)
  //   _model.load("./images/model/thug.obj");
  // else
  //   _model.load("./images/model/thug2.obj");
  // _model.load("/home/audibe_l/Downloads/marvin/War_Machine_Iron_Patriot.obj");
  // _model.load("/home/audibe_l/Downloads/Blender/GuardSoldier.FBX");
  // _model.load("/home/audibe_l/Downloads/marvin/joker/thug2.obj");
  _orientation = DOWN;
  _type = HUMAN;
  _timer = 0;
  _canLaunchBomb = true;
  _isAnime = false;
  _range = 1;
  _sound.registerSound("./resources/sounds/USAbomb.mp3", "USAbomb");
  glm::vec3 trans(0 + (_pos._x - _world->getWidth() / 2) * 100, -50,  750 * (-1) + (_pos._y - _world->getHeight() / 2) * 100);
  // glm::vec3 trans(0 + (_pos._x - _world->getWidth() / 2) * 100, -0,  750 * (-1) + (_pos._y - _world->getHeight() / 2) * 100);
  this->translate(trans);
  if (save == 1)
    this->scale(glm::vec3(0.3, 0.3, 0.3));
  else
    this->scale(glm::vec3(2.7, 2.7, 2.7));
  // if (save == 1)
  //   this->scale(glm::vec3(7, 7, 7));
  // else
  //   this->scale(glm::vec3(1, 1, 1));
  // this->scale(glm::vec3(1, 1, 1));
}

#include <unistd.h>

HumanCharacter::~HumanCharacter()
{
  std::cout << "Human is dead..." << std::endl;
  sleep(5);
}

bool HumanCharacter::getAlive() const
{
  return _alive;
}

void HumanCharacter::dropBomb()
{
  // _model.setCurrentAnim(4, false);
  if (_canLaunchBomb == true)
    {
      std::cout << "I droped a bomb hahah" << std::endl;
      _canLaunchBomb = false;
      _world->dropBomb(_pos, (_id - '0'));
      _sound.playMusic("USAbomb");
      _world->setItemAtPosition(_pos, 'T');
    }
}

void HumanCharacter::takeObject(AObject *object)
{
  this->_listObject.push_back(object);
}

void HumanCharacter::die()
{
  std::cout << "I died" << std::cout;
}

void HumanCharacter::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _model.draw(shader, AObject::getTransformation(), 1);
}

void HumanCharacter::update()
{
  // _model.update();
}

Position	&HumanCharacter::getPos() const
{
  return (Position &) _pos;
}

int	HumanCharacter::getRange() const
{
  return _range;
}

int	HumanCharacter::getOrientation() const
{
  return _orientation;
}

int	HumanCharacter::getId() const
{
  return (_id - '0');
}

void	HumanCharacter::setPos(Position &pos)
{
  _pos = pos;
}

void	HumanCharacter::setRange(int range)
{
  _range = range;
}

void	HumanCharacter::setOrientation(int orientation)
{
  _orientation = (e_orientation)orientation;
}

void	HumanCharacter::initColor()
{
  srand(time(NULL));
  _color.insert(std::pair<char,int>('r', rand() % 256));
  _color.insert(std::pair<char,int>('g', rand() % 256));
  _color.insert(std::pair<char,int>('b', rand() % 256));
}

std::map<char, int> &HumanCharacter::getColor() const
{
  return (std::map<char, int> &) _color;
}

void	HumanCharacter::setColor(int r, int g, int b)
{
  _color.insert(std::pair<char,int>('r', r));
  _color.insert(std::pair<char,int>('g', g));
  _color.insert(std::pair<char,int>('b', b));
}

int	HumanCharacter::getType() const
{
  return _type;
}

ACharacter	&HumanCharacter::getCharacter()
{
  return *this;
}

float	HumanCharacter::getAngle(e_orientation before, e_orientation after)
{
  if ((before == UP && after == RIGHT)
      || (before == RIGHT && after == DOWN)
      || (before == DOWN && after == LEFT)
      || (before == LEFT && after == UP))
    return (90.0f);
  else if ((before == UP && after == DOWN)
	   || (before == RIGHT && after == LEFT)
	   || (before == DOWN && after == UP)
	   || (before == LEFT && after == RIGHT))
    return (180.0f);
  else if ((before == UP && after == LEFT)
	   || (before == RIGHT && after == UP)
	   || (before == DOWN && after == RIGHT)
	   || (before == LEFT && after == DOWN))
    return (270.0f);
  return (0.0f);
}

bool	HumanCharacter::move(e_orientation ori, gdl::Clock &clock)
{
  glm::vec3 trans(0, 1, 0);
  Position *pos;
  int x = 0;
  int y = 0;

  this->rotate(trans, getAngle(_orientation, ori));
  _orientation = ori;
  if (ori == UP)
    {
      pos = new Position(_pos._x, _pos._y - 1);
      y = -1;
    }
  else if (ori == LEFT)
    {
      pos = new Position(_pos._x + 1, _pos._y);
      x = 1;
    }
  else if (ori == DOWN)
    {
      pos = new Position(_pos._x, _pos._y + 1);
      y = +1;
    }
  else if (ori == RIGHT)
    {
      pos = new Position(_pos._x - 1, _pos._y);
      x = -1;
    }
  if (_world->checkPlayerCanMove(pos->_x, pos->_y) == true)
    {
      if (_isAnime == false)
	{
	  _model.setCurrentAnim(0, false);
	  // _isAnime = true;
	}
      std::cout << "OK" << std::endl;
      glm::vec3 move(x * 100, 0, y * 100);
      std::cout << "clock.getElapsed() = " << clock.getElapsed() << std::endl;
      _timer += 1.0f;
      std::cout << "x = " << _pos._x << "; y = " << _pos._y << std::endl;
      std::cout << "timer = " << _timer << std::endl;
      if (_timer >= 2.0f)
      	{
	  this->translate(move);
	  _world->setItemAtPosition(*pos, _id);
	  _pos = *pos;
      	  _timer = 0;
      	}
      return true;
    }
  return false;
}

bool	HumanCharacter::getCanLaunchBomb() const
{
  return _canLaunchBomb;
}

void	HumanCharacter::setCanLaunchBomb(bool launch)
{
  std::cout << "_canLaunchBomb at " << launch << std::endl;
  _canLaunchBomb = launch;
}
