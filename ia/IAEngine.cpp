#include "IAEngine.hh"

IAEngine::IAEngine(IACharacter &ia, World &world)
{
  ACharacter *target;

  _math = Math();
  std::srand(std::time(0));
  while (world->getHumanPlayers().size() != 0)
  {
    _aroundMe = this.whatIsAroundMe(ia, world);
//    this->leaveThisPosition(ia, world);
    target = this.getTarget(ia, world);

    this.findPathToTarget();

    this.actLikeAMan();
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



std::vector<char>  IAEngine::whatIsAroundMe(IACharacter &ia, world &world)
{
  _aroundMe.erase();
  _xIA = ia.getPos().getX();
  _yIA = ia.getPos().getY();
  _aroundMe.push_back(world.getItemAtPosition(_xIA, yIA - 1));
  _aroundMe.push_back(world.getItemAtPosition(_xIA + 1, yIA));
  _aroundMe.push_back(world.getItemAtPosition(_xIA, yIA + 1));
  _aroundMe.push_back(world.getItemAtPosition(_xIA - 1, yIA));
}





void   IAEngine::leaveThisPosition(IACharacter &ia, world &world)
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

float           IAEngine::calculDistance(IACharacter *ia, HumanCharacter *human)
{
  _xIA = ia->getPos()->getX();
  _yIA = ia->getPos()->getY();
  _xHuman = human->getPos()->getX();
  _yHuman = human->getPos()->getY();
  _l = this->calculLength(xIA, xHuman);
  _w = this->calculWidth(yIA, yHuman);
  return (_math.squareRoot((_w * _w) + (_l * _l)));
}

HumanCharacter  *IAEngine::findClosestHumanPlayer(IACharacter &ia, World &world)
{
  _h1 = this.calculDistance(ia, world.getHumanPlayers().at(0));
  _h2 = this.calculDistance(ia, world.getHumanPlayers().at(1));
  if (_h1 < _h2)
    return (world.getHumanPlayers().at(0));
  else if (_h1 == _h2)
    return (world.getHumanPlayers().at(std::rand() % 2))
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

bool	       IAEngine::isPossibleToJoinTarget(HumanCharacter *target)
{
  std::vector<std::map<int:int>> route;

  this.routeToTarget(route);
}

void      IAEngine::routeToTarget(std::vector &route)
{

}



