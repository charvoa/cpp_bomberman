//
// IAEngine.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jun  5 13:13:29 2015 Nicolas Charvoz
// Last update Fri Jun  5 13:13:30 2015 Nicolas Charvoz
//

#include <unistd.h>
#include "IAEngine.hh"
#include "../IACharacter.hh"
#include "../HumanCharacter.hh"
#include "../World.hh"

IAEngine::IAEngine(IACharacter &ia, World &world)
{
  _ia = &ia;
  _world = &world;
  _math = Math();
  _pos = Position(1, 1);
  _math.initSRand(_math.initTime(NULL));
  _thread = new Thread(this);
}

IAEngine::~IAEngine()
{
  _ia->setAlive(false);
}

void		*IAEngine::run()
{
  HumanCharacter *target;

  while (_world->getHumansPlayers().size() != 0 && _ia->getAlive() == true)
  {
    this->whatIsAroundMe();
    target = this->getTarget();
    this->isPossibleToJoinTarget(*target);
  }
  return 0;
}

void		*IAEngine::backRun(void *Class)
{
  return (((IAEngine *)Class)->run());
}

bool                IAEngine::isHumanPlayerAroundMe(std::vector<char> &vector)
{
  unsigned int               i;

  i = 0;
  while (i < vector.size())
    {
      if (vector.at(i) == '1' || vector.at(i) == '2')
        return true;
      i++;
    }
  return false;
}

bool                IAEngine::isBoxAroundMe(std::vector<char> &vector)
{
  unsigned int               i;

  i = 0;
  while (i < vector.size())
    {
      if (vector.at(i) == 'B')
        return true;
      i++;
    }
  return false;
}

bool                IAEngine::isBombAroundMe(std::vector<char> &vector)
{
  unsigned int               i;

  i = 0;
  while (i < vector.size())
    {
      if (vector.at(i) == 'E')
        return true;
      i++;
    }
  return false;
}

bool			IAEngine::isBonusAroundMe(std::vector<char> &vector)
{
  unsigned int               i;

  i = 0;
  while (i < vector.size())
    {
      if (vector.at(i) == 'X')
        return true;
      i++;
    }
  return false;
}

void			IAEngine::whatIsAroundMe()
{
  _aroundMe.clear();
  _xIA = _ia->getPos()._x;
  _yIA = _ia->getPos()._y;
  _aroundMe.push_back(_world->getItemAtPosition(_xIA, _yIA - 1));
  _aroundMe.push_back(_world->getItemAtPosition(_xIA + 1, _yIA));
  _aroundMe.push_back(_world->getItemAtPosition(_xIA, _yIA + 1));
  _aroundMe.push_back(_world->getItemAtPosition(_xIA - 1, _yIA));
}

int			IAEngine::calculLength(int firstPosX, int secondPosX)
{
    return (_math.absolute(firstPosX - secondPosX));
}

int			IAEngine::calculWidth(int firstPosY, int secondPosY)
{
     return (_math.absolute(firstPosY - secondPosY));
}

float			IAEngine::calculDistance(HumanCharacter &target)
{
  _xIA = _ia->getPos()._x;
  _yIA = _ia->getPos()._y;
  _xTarget = target.getPos()._x;
  _yTarget = target.getPos()._y;
  _l = this->calculLength(_xIA, _xTarget);
  _w = this->calculWidth(_yIA, _yTarget);
  return (_math.squareRoot((_w * _w) + (_l * _l)));
}

HumanCharacter		*IAEngine::findClosestHumanPlayer()
{
  _h1 = this->calculDistance(*_world->getHumansPlayers().at(0));
  _h2 = this->calculDistance(*_world->getHumansPlayers().at(1));
  if (_h1 < _h2)
    return (_world->getHumansPlayers().at(0));
  else if (_h1 == _h2)
    return (_world->getHumansPlayers().at(_math.useRand() % 2));
  return (_world->getHumansPlayers().at(1));
}

HumanCharacter		*IAEngine::getTarget()
{
  if (_world->getHumansPlayers().size() == 0)
    return NULL;
  else if (_world->getHumansPlayers().size() == 1)
    return (_world->getHumansPlayers().at(0));
  return (this->findClosestHumanPlayer());
}

void			IAEngine::setOperand(int opt)
{
  if (opt == 0)
  {
    _ope[0] = 1;
    _ope[1] = 0;
    _ope[2] = 0;
    _ope[3] = 1;
  }
  else if (opt == 1)
  {
    _ope[0] = 0;
    _ope[1] = 1;
    _ope[2] = 1;
    _ope[3] = 0;
  }
  else if (opt == 2)
  {
    _ope[0] = -1;
    _ope[1] = 0;
    _ope[2] = 0;
    _ope[3] = -1;
  }
  else if (opt == 3)
  {
    _ope[0] = 0;
    _ope[1] = -1;
    _ope[2] = -1;
    _ope[3] = 0;
  }
}

e_orientation		IAEngine::giveOrientation()
{
  if (_pos._x > _ia->getPos()._x)
    return LEFT;
  if (_pos._y > _ia->getPos()._y)
    return DOWN;
  if (_pos._x < _ia->getPos()._x)
    return RIGHT;
  if (_pos._y < _ia->getPos()._y)
    return UP;
  return UNKNOWN;
}

void			IAEngine::leaveThisPosition()
{
  std::cout << "Je me décale une bombe est proche de moi" << std::endl;
  sleep(1);
  if (_aroundMe.at(0) == 'F')
    _pos._y -= 1;
  if (_aroundMe.at(1) == 'F')
    _pos._x += 1;
  if (_aroundMe.at(2) == 'F')
    _pos._y += 1;
  if (_aroundMe.at(3) == 'F')
    _pos._x -= 1;
}

int			IAEngine::move()
{
  if (this->isBombAroundMe(_aroundMe) == true)
    {
      this->leaveThisPosition();
      return 0;
    }
  else if (this->isHumanPlayerAroundMe(_aroundMe) == true)
    {
      std::cout << "Je suis juste a coté d'un humain" << std::endl;
      sleep(3);
      _ia->dropBomb();
      this->leaveThisPosition();
      return 1;
    }
  else if (this->isBoxAroundMe(_aroundMe) == true)
    {
      _ia->dropBomb();
      return 2;
    }
  else if (this->isBonusAroundMe(_aroundMe) == true)
    {
      return 3;
    }
  return -1;
}

bool			IAEngine::isPossibleToJoinTarget(HumanCharacter &target)
{
  unsigned int r;
  unsigned int o;
  unsigned int index;

  r = 0;
  index = -1;
  _map = _world->getWorld();
  this->setOperand(0);
  if (this->routeToTarget(_ia->getPos()._x, _ia->getPos()._y, target) == true)
    _routes.push_back(std::make_pair(_route, _route.size()));
  _route.clear();
  _map = _world->getWorld();
  this->setOperand(1);
  if (this->routeToTarget(_ia->getPos()._x, _ia->getPos()._y, target) == true)
    _routes.push_back(std::make_pair(_route, _route.size()));
  _map = _world->getWorld();
  _route.clear();
  this->setOperand(2);
  if (this->routeToTarget(_ia->getPos()._x, _ia->getPos()._y, target) == true)
    _routes.push_back(std::make_pair(_route, _route.size()));
  _map = _world->getWorld();
  _route.clear();
  this->setOperand(3);
  if (this->routeToTarget(_ia->getPos()._x, _ia->getPos()._y, target) == true)
    _routes.push_back(std::make_pair(_route, _route.size()));
  _route.clear();

  while (r < _routes.size() - 1)
    {
      if (_routes.size() == 1)
        index = 0;
      else if (_routes.size() > 1 && (std::min(_routes.at(r).second, _routes.at(r + 1).second) == _routes.at(r).second))
	index = r;
      else
	index = r + 1;
      r++;
    }

  if (_routes.size() >= 1)
    {
      _pos._x = _routes.at(index).first.at(1).first;
      _pos._y = _routes.at(index).first.at(1).second;
      o = 2;
      while (o < _routes.at(index).first.size() && _ia->move(this->giveOrientation()) == true)
	{
	  if (this->move() == 0)
	    ;
	  else if (this->move() == 1 && o >= 1)
	    {
	      _pos._x = _routes.at(index).first.at(o - 1).first;
	      _pos._y = _routes.at(index).first.at(o - 1).second;
	    }
	  else
	    {
	      _pos._x = _routes.at(index).first.at(o).first;
	      _pos._y = _routes.at(index).first.at(o).second;
	      o++;
	    }
	  // USLEEP
	}
      o--;
      if (this->move() == 0)
	;
      else if (this->move() == 1 && o >= 1)
	{
	  this->leaveThisPosition();
	  _ia->move(this->giveOrientation());
	}
      else
	{
	  _pos._x = _routes.at(index).first.at(o).first;
	  _pos._y = _routes.at(index).first.at(o).second;
	  _ia->move(this->giveOrientation());
	}
    }
  _routes.clear();
  return false;
}

bool			IAEngine::routeToTarget(int x, int y, HumanCharacter &target)
{
  if (_map.at(y).at(x) == 'W' || _map.at(y).at(x) == '-')
    {
      return false;
    }
  else if (_map.at(y).at(x) == 'F' || _map.at(y).at(x) == 'X' || _map.at(y).at(x) == 'E' || _map.at(y).at(x) == 'T'
	   || (x == _ia->getPos()._x && y == _ia->getPos()._y))
    {
      _map.at(y).at(x) = '-';
      _route.push_back(std::make_pair(x, y));
      if (this->routeToTarget(x + _ope[0], y + _ope[1], target) == true)
	return true;
      if (this->routeToTarget(x + _ope[2], y + _ope[3], target) == true)
	return true;
      if (this->routeToTarget(x + (_ope[0] * (-1)), y + (_ope[1] * (-1)), target) == true)
	return true;
      if (this->routeToTarget(x + (_ope[2] * (-1)), y + (_ope[3] * (-1)), target) == true)
	return true;
      _route.pop_back();
    }
  else if (x == target.getPos()._x && y == target.getPos()._y)
    {
      _route.push_back(std::make_pair(x, y));
      return true;
    }
  return false;
}
