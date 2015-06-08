#include "IAEngine.hh"

// OPT
#include "../IACharacter.hh"
#include "../HumanCharacter.hh"
#include "../World.hh"

#include <unistd.h>

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

}

void		*IAEngine::run()
{
  HumanCharacter *target;

  while (_world->getHumansPlayers().size() != 0)
  {
    this->whatIsAroundMe();
//    this->leaveThisPosition(ia, world);
    target = this->getTarget();

    this->isPossibleToJoinTarget(*target);

//    this.actLikeAMan();

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

void			IAEngine::setOperand(HumanCharacter &target)
{
  if (_ia->getPos()._x < target.getPos()._x)
  {
    _ope[0] = 1;
    _ope[1] = 0;
  }
  else if (_ia->getPos()._x == target.getPos()._x)
  {
    _ope[0] = -1;
    _ope[1] = 1;
  }
  else
  {
    _ope[0] = -1;
    _ope[1] = 0;
  }

  if (_ia->getPos()._y < target.getPos()._y)
  {
    _ope[2] = 0;
    _ope[3] = 1;
  }
  else if (_ia->getPos()._y == target.getPos()._y)
  {
    _ope[2] = -1;
    _ope[3] = 1;
  }
  else
  {
    _ope[2] = 0;
    _ope[3] = -1;
  }

}

e_orientation		IAEngine::giveOrientation()
{
  if (_pos._x > _ia->getPos()._x)
    return LEFT;
  if (_pos._y > _ia->getPos()._y)
    return UP;
  if (_pos._x < _ia->getPos()._x)
    return RIGHT;
  if (_pos._y < _ia->getPos()._y)
    return DOWN;
  return UNKNOWN;
}

void			IAEngine::leaveThisPosition()
{
  if (_aroundMe.at(0) == 'F')
    _pos._x -= 1;
  if (_aroundMe.at(1) == 'F')
    _pos._y += 1;
  if (_aroundMe.at(2) == 'F')
    _pos._x += 1;
  if (_aroundMe.at(3) == 'F')
    _pos._y -= 1;
}

bool			IAEngine::move()
{
  if (this->isBombAroundMe(_aroundMe) == true)
    {
      this->leaveThisPosition();
      return true;
    }
  else if (this->isHumanPlayerAroundMe(_aroundMe) == true)
    {
      _ia->dropBomb();
      return true;
    }
  else if (this->isBoxAroundMe(_aroundMe) == true)
    {
      _ia->dropBomb();
      return true;
    }
  else if (this->isBonusAroundMe(_aroundMe) == true)
    {
      this->leaveThisPosition();
      return true;
    }
  return false;
}

bool			IAEngine::isPossibleToJoinTarget(HumanCharacter &target)
{
  this->setOperand(target);
  _map = _world->getWorld();
  _route.clear();
  if (this->routeToTarget(_ia->getPos()._x, _ia->getPos()._y, target) == true)
      {
	if (this->move() == true)
	  ;
	else
	  {
	    _pos._x = _route.at(1).first;
	    _pos._y = _route.at(1).second;
	  }
	_ia->move(this->giveOrientation());
        return true;
      }
  this->move();
//  std::cout << "Pas trouvé de chemin vers une target" << std::endl;
  return false;
}

bool			IAEngine::routeToTarget(int x, int y, HumanCharacter &target)
{
    // Check dimension du labyrinthe == W || '-'?
    // Check si == F || X || E
    // Est-ce egale à la position du Human Player qui est target ?
    // Return true si on est à la position du Human Player sinon return false dans tous les autres cas

  int i;
  int j;
  int h;

  i = 0;
  j = 0;
  h = 0;

  while (h < 4)
    {
      // std::cout << _ope[h] << std::endl;
      h++;
    }

  while (j < _world->getHeight())
    {
      i = 0;
      while (i < _world->getWidth())
	{
	  // std::cout << _map.at(j).at(i);
	  i++;
	}
      // std::cout << std::endl;
      j++;
    }

   usleep(5000);


    if (_map.at(y).at(x) == 'W' || _map.at(y).at(x) == '-'/* || _map.at(y).at(x) == 'I'*/)
    {
      return false;
    }
    else if (_map.at(y).at(x) == 'F' || _map.at(y).at(x) == 'X' || _map.at(y).at(x) == 'E' || _map.at(y).at(x) == 'T'
            || (x == _ia->getPos()._x && y == _ia->getPos()._y))
      {
        _map.at(y).at(x) = '-';
	_route.push_back(std::make_pair(x + _ope[0], y + _ope[1]));
        if (this->routeToTarget(x + _ope[0], y + _ope[1], target) == true)
          return true;
        _route.pop_back();
	_route.push_back(std::make_pair(x + _ope[2], y + _ope[3]));
        if (this->routeToTarget(x + _ope[2], y + _ope[3], target) == true)
          return true;
        _route.pop_back();
	_route.push_back(std::make_pair(x + (_ope[0] * (-1)), y + (_ope[1] * (-1))));
        if (this->routeToTarget(x + (_ope[0] * (-1)), y + (_ope[1] * (-1)), target) == true)
          return true;
        _route.pop_back();
	_route.push_back(std::make_pair(x + (_ope[2] * (-1)), y + (_ope[3] * (-1))));
        if (this->routeToTarget(x + (_ope[2] * (-1)), y + (_ope[3] * (-1)), target) == true)
          return true;
        _route.pop_back();
      }
    else if (x == target.getPos()._x && y == target.getPos()._y)
      {
        return true;
      }
      return false;
}
