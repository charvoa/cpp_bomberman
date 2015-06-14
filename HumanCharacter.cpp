//
// HumanCharacter.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue May 19 11:55:01 2015 Nicolas Charvoz
// Last update Sun Jun 14 15:46:53 2015 Audibert Louis
//

#include <iostream>
#include "HumanCharacter.hh"
#include "World.hh"
#include "Bomb.hh"

TextureManager&	HumanCharacter::_texManag = TextureManager::getInstance();
Sound&	ACharacter::_sound = Sound::getInstance();

HumanCharacter::HumanCharacter(char id, World *world, Position& pos)
{
  _world = world;
  std::cout << "id = " << id << std::endl;
  this->_id = id;
  this->_alive = true;
  _pos = pos;
  _orientation = DOWN;
  _type = HUMAN;
  _timer = 0;
  _canLaunchBomb = true;
  _isAnime = false;
  _range = 1;
  _score = 0;
  _sound.registerSound("./resources/sounds/USAbomb.mp3", "USAbomb");
  if ((id - '0') == 1)
    _model.load("./images/model/marvin.fbx");
  else
    _model.load("./images/model/GuardSoldier.FBX");
  glm::vec3 trans(0 + (_pos._x - _world->getWidth() / 2) * 100, -50,  750 * (-1) + (_pos._y - _world->getHeight() / 2) * 100);
  this->translate(trans);
  if ((id - '0') == 1)
    this->scale(glm::vec3(0.3, 0.3, 0.3));
  else
    this->scale(glm::vec3(2.7, 2.7, 2.7));
}

HumanCharacter::~HumanCharacter()
{
  std::cout << "Human is dead..." << std::endl;
}

bool HumanCharacter::getAlive() const
{
  return _alive;
}

void HumanCharacter::dropBomb()
{
  if (_canLaunchBomb == true)
    {
      std::cout << "I droped a bomb" << std::endl;
      _world->dropBomb(_pos, (_id - '0'));
      _sound.playMusic("USAbomb");
      _world->setItemAtPosition(_pos, 'T');
      _canLaunchBomb = false;
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
  (void)clock;
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
	_model.setCurrentAnim(0, false);
      glm::vec3 move(x * 100, 0, y * 100);
      _timer += 1.0f;
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
  _canLaunchBomb = launch;
}

void	HumanCharacter::setBonus(int bonus)
{
  std::cout << "bonus = " << bonus << std::endl;
  if (bonus == 0)
    _range += 1;
  else if (bonus == 1)
    _canLaunchBomb = true;
  else if (bonus == 2)
    _score += 50;
}

int	HumanCharacter::getScore() const
{
  return _score;
}

void	HumanCharacter::setScore(int score)
{
  _score = score;
}

