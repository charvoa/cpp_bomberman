#include "IAEngine.hh"

// OPT
#include "../IACharacter.hh"
#include "../HumanCharacter.hh"
#include "../World.hh"

IAEngine::IAEngine(IACharacter &ia, World &world)
{
  _math = Math();
  _pos = Position(1, 1);
  _math.initSRand(_math.initTime(NULL));
  _thread = new Thread(this);
}

IAEngine::~IAEngine()
{

}

void	*run()
{
  HumanCharacter *target;
  while (world.getHumansPlayers().size() != 0)
  {
    this->whatIsAroundMe(ia, world);
//    this->leaveThisPosition(ia, world);
    target = this->getTarget(ia, world);

    this->isPossibleToJoinTarget(ia, world, *target);

//    this.actLikeAMan();

  }
}

void *backRun(void *Class)
{
  return (IAEngine *)Class)->run();
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

void			IAEngine::whatIsAroundMe(IACharacter &ia, World &world)
{
  _aroundMe.clear();
  _xIA = ia.getPos()._x;
  _yIA = ia.getPos()._y;
  _aroundMe.push_back(world.getItemAtPosition(_xIA, _yIA - 1));
  _aroundMe.push_back(world.getItemAtPosition(_xIA + 1, _yIA));
  _aroundMe.push_back(world.getItemAtPosition(_xIA, _yIA + 1));
  _aroundMe.push_back(world.getItemAtPosition(_xIA - 1, _yIA));
}

void			IAEngine::leaveThisPosition(IACharacter &ia, World &world)
{
  (void)ia;
  (void)world;
}

int			IAEngine::calculLength(int firstPosX, int secondPosX)
{
    return (_math.absolute(firstPosX - secondPosX));
}

int			IAEngine::calculWidth(int firstPosY, int secondPosY)
{
     return (_math.absolute(firstPosY - secondPosY));
}

float			IAEngine::calculDistance(IACharacter &ia, HumanCharacter &human)
{
  _xIA = ia.getPos()._x;
  _yIA = ia.getPos()._y;
  _xHuman = human.getPos()._x;
  _yHuman = human.getPos()._y;
  _l = this->calculLength(_xIA, _xHuman);
  _w = this->calculWidth(_yIA, _yHuman);
  return (_math.squareRoot((_w * _w) + (_l * _l)));
}

HumanCharacter		*IAEngine::findClosestHumanPlayer(IACharacter &ia, World &world)
{
  _h1 = this->calculDistance(ia, *world.getHumansPlayers().at(0));
  _h2 = this->calculDistance(ia, *world.getHumansPlayers().at(1));
  if (_h1 < _h2)
    return (world.getHumansPlayers().at(0));
  else if (_h1 == _h2)
    return (world.getHumansPlayers().at(_math.useRand() % 2));
  return (world.getHumansPlayers().at(1));
}

HumanCharacter		*IAEngine::getTarget(IACharacter &ia, World &world)
{
  if (world.getHumansPlayers().size() == 0)
    return NULL;
  else if (world.getHumansPlayers().size() == 1)
    return (world.getHumansPlayers().at(0));
  return (this->findClosestHumanPlayer(ia, world));
}

void			IAEngine::setOperand(IACharacter &ia, HumanCharacter &target)
{
  if (ia.getPos()._x < target.getPos()._x)
  {
    _ope[0] = 1;
    _ope[1] = 0;
  }
  else if (ia.getPos()._x == target.getPos()._x)
  {
    _ope[0] = 0;
    _ope[1] = 0;
  }
  else
  {
    _ope[0] = -1;
    _ope[1] = 0;
  }

  if (ia.getPos()._y < target.getPos()._y)
  {
    _ope[2] = 0;
    _ope[3] = 1;
  }
  else if (ia.getPos()._y == target.getPos()._y)
  {
    _ope[2] = 0;
    _ope[3] = 0;
  }
  else
  {
    _ope[2] = 0;
    _ope[3] = -1;
  }
}

bool			IAEngine::isPossibleToJoinTarget(IACharacter &ia, World &world, HumanCharacter &target)
{
  // Mettre ces variables dans la classe

  this->setOperand(ia, target);
  _map = world.getWorld();
  _route.clear();
  if (this->routeToTarget(ia.getPos()._x, ia.getPos()._y, ia, target) == true)
      {
        _pos._x = _route.at(1).first;
        _pos._y = _route.at(1).second;
        world.setItemAtPosition(_pos, 'I');
        return true;
      }
//  std::cout << "Pas trouvé de chemin vers une target" << std::endl;
  world.setItemAtPosition(_pos, 'I');
  return false;
}

bool			IAEngine::routeToTarget(int x, int y, IACharacter &ia, HumanCharacter &target)
{
    // Check dimension du labyrinthe == W || '-'?
    // Check si == F || X || E
    // Est-ce egale à la position du Human Player qui est target ?
    // Return true si on est à la position du Human Player sinon return false dans tous les autres cas

    if (_map.at(y).at(x) == 'W' || _map.at(y).at(x) == '-' || _map.at(y).at(x) == 'I')
    {
      return false;
    }
    else if (_map.at(y).at(x) == 'F' || _map.at(y).at(x) == 'X' || _map.at(y).at(x) == 'E' || _map.at(y).at(x) == 'T'
            || (x == ia.getPos()._x && y == ia.getPos()._y))
      {
        _map.at(y).at(x) = '-';
	_route.push_back(std::make_pair(x + _ope[0], y + _ope[1]));
        if (this->routeToTarget(x + _ope[0], y + _ope[1], ia, target) == true)
          return true;
        _route.pop_back();
	_route.push_back(std::make_pair(x + _ope[2], y + _ope[3]));
        if (this->routeToTarget(x + _ope[2], y + _ope[3], ia, target) == true)
          return true;
        _route.pop_back();
	_route.push_back(std::make_pair(x + (_ope[0] * (-1)), y + (_ope[1] * (-1))));
        if (this->routeToTarget(x + (_ope[0] * (-1)), y + (_ope[1] * (-1)), ia, target) == true)
          return true;
        _route.pop_back();
	_route.push_back(std::make_pair(x + (_ope[2] * (-1)), y + (_ope[3] * (-1))));
        if (this->routeToTarget(x + (_ope[2] * (-1)), y + (_ope[3] * (-1)), ia, target) == true)
          return true;
        _route.pop_back();
      }
    else if (x == target.getPos()._x && y == target.getPos()._y)
      {
        return true;
      }
      return false;
}
