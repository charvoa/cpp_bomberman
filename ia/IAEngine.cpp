#include "IAEngine.hh"

// OPT
#include "../IACharacter.hh"
#include "../HumanCharacter.hh"
#include "../World.hh"

IAEngine::IAEngine(IACharacter &ia, World &world)
{
  ACharacter *target;

  _math = Math();
  _pos(1, 1);
  _math.initSRand(_math.initTime(NULL));
  while (world->getHumanPlayers().size() != 0)
  {
    _aroundMe = this.whatIsAroundMe(ia, world);
//    this->leaveThisPosition(ia, world);
    target = this.getTarget(ia, world);

    this.isPossibleToJoinTarget(ia, world, *target);

//    this.actLikeAMan();

  }
}

IAEngine::~IAEngine()
{
  
}

bool                isHumanPlayerAroundMe(std::vector<char> &vector)
{
  int               i;

  i = 0;
  while (i < vector.size())
    {
      if (vector.at(i) == '1' || vector.at(i) == '2')
        return true;
      i++;
    }
  return false;
}

bool                isBoxAroundMe(std::vector<char> &vector)
{
  int               i;

  i = 0;
  while (i < vector.size())
    {
      if (vector.at(i) == 'B')
        return true;
      i++;
    }
  return false;
}

bool                isBombAroundMe(std::vector<char> &vector)
{
  int               i;

  i = 0;
  while (i < vector.size())
    {
      if (vector.at(i) == 'E')
        return true;
      i++;
    }
  return false;
}

bool                isBonusAroundMe(std::vector<char> &vector)
{
  int               i;

  i = 0;
  while (i < vector.size())
    {
      if (vector.at(i) == 'X')
        return true;
      i++;
    }
  return false;
}



std::vector<char>  IAEngine::whatIsAroundMe(IACharacter &ia, World &world)
{
  _aroundMe.erase();
  _xIA = ia.getPos().getX();
  _yIA = ia.getPos().getY();
  _aroundMe.push_back(world.getItemAtPosition(_xIA, yIA - 1));
  _aroundMe.push_back(world.getItemAtPosition(_xIA + 1, yIA));
  _aroundMe.push_back(world.getItemAtPosition(_xIA, yIA + 1));
  _aroundMe.push_back(world.getItemAtPosition(_xIA - 1, yIA));
}


void   IAEngine::leaveThisPosition(IACharacter &ia, World &world)
{

}


int    IAEngine::calculLength(int firstPosX, int secondPosX)
{
    return (_math.absolute(firstPosX - secondPosX));
}                                                                                                    |

int    IAEngine::calculWidth(int firstPosY, int secondPosY)
{
     return (_math.absolute(firstPosY - secondPosY));
}                                                                                                    |

float           IAEngine::calculDistance(IACharacter &ia, HumanCharacter &human)
{
  _xIA = ia.getPos()._x;
  _yIA = ia.getPos()._y;
  _xHuman = human.getPos()._x;
  _yHuman = human.getPos()._y;
  _l = this.calculLength(xIA, xHuman);
  _w = this.calculWidth(yIA, yHuman);
  return (_math.squareRoot((_w * _w) + (_l * _l)));
}

HumanCharacter  *IAEngine::findClosestHumanPlayer(IACharacter &ia, World &world)
{
  _h1 = this.calculDistance(ia, world.getHumanPlayers().at(0));
  _h2 = this.calculDistance(ia, world.getHumanPlayers().at(1));
  if (_h1 < _h2)
    return (world.getHumanPlayers().at(0));
  else if (_h1 == _h2)
    return (world.getHumanPlayers().at(_math.useRand() % 2))
  return (world.getHumanPlayers().at(1));
}

HumanCharacter	*IAEngine::getTarget(IACharacter &ia, World &world)
{
  if (world.getHumanPlayers().size() == 0)
    return NULL;
  else if (world.getHumanPlayers().size() == 1)
    return world.getHumanPlayers().at(0);
  else
    return this.findClosestHumanPlayer(ia, world);
}

int          *IAEngine::setOperand(IACharacter &ia, HumanCharacter &target)
{
  int         ope[4];

  if (ia.getPos()._x < target.getPos()._x)
  {
    ope[0] = 1;
    ope[1] = 0;
  }
  else if (ia.getPos()._x == target.getPos()._x)
  {
    ope[0] = 0;
    ope[1] = 0;    
  }
  else
  {
    ope[0] = -1;
    ope[1] = 0;
  }


  if (ia.getPos()._y < target.getPos()._y)
  {
    ope[2] = 0;
    ope[3] = 1;
  }
  else if (ia.getPos()._y == target.getPos()._y)
  {
    ope[2] = 0;
    ope[3] = 0;
  }
  else
  {
    ope[2] = 0;
    ope[3] = -1;
  }
  return (ope);
}

bool	       IAEngine::isPossibleToJoinTarget(IACharacter &ia, World &world, HumanCharacter &target)
{
  int         ope[4];

  // Mettre ces variables dans la classe
  std::vector<std::map<int:int>> route;
  std::vector<std::vector<char >> map;

  ope = this.setOperand(ia, target);
  map = world.getWorld();
  if (this.routeToTarget(ia.getPos()._x, ia.getPos()._y, map, route) == true)
      {
        _pos._x = route.at(1).at(0);
        _pos._y = route.at(1).at(1);
        world.setItemAtPosition(_pos, 'I');
        return true;
      }
//  std::cout << "Pas trouvé de chemin vers une target" << std::endl;
  world.setItemAtPosition(_pos, 'I');
  return false;
}

bool      IAEngine::routeToTarget(int x, int y, std::vector<std::vector<char >> &map, std::vector<std::map<int:int>> &route, IACharacter &ia, HumanCharacter &target)
{
    // Check dimension du labyrinthe == W || '-'?
    // Check si == F || X || E
    // Est-ce egale à la position du Human Player qui est target ?
    // Return true si on est à la position du Human Player sinon return false dans tous les autres cas

    if (map.at(y).at(x) == 'W' || map.at(y).at(x) == '-' || map.at(y).at(x) == 'I')
    {
      return false;
    }
    else if (map.at(y).at(x) == 'F' || map.at(y).at(x) == 'X' || map.at(y).at(x) == 'E' || map.at(y).at(x) == 'T'
            || (x == ia.getPos()._x && y == ia.getPos()._y))
      {
        map.at(y).at(x) = '-';
        route.insert(x + ope[0], y + ope[1]);
        if (this.routeToTarget(x + ope[0], y + ope[1], map, route, ia, target) == true)
          return true;
        route.pop_back();
        route.insert(x + ope[2], y + ope[3]);
        if (this.routeToTarget(x + ope[2], y + ope[3], map, route, ia, target) == true)
          return true;
        route.pop_back();
        route.insert(x + (ope[0] * (-1)), y + (ope[1] * (-1)));
        if (this.routeToTarget(x + (ope[0] * (-1)), y + (ope[1] * (-1)), map, route, ia, target) == true)
          return true;
        route.pop_back();
        route.insert(x + (ope[2] * (-1)), y + (ope[3] * (-1)));
        if (this.routeToTarget(x + (ope[2] * (-1)), y + (ope[3] * (-1)), map, route, ia, target) == true)
          return true;
        route.pop_back();
      }
    else if (x == target.getPos()._x && y == target.getPos()._y)
      {
        return true;
      }
      return false;
}



