#include "IAEngine.hh"

IAEngine::IAEngine(IACharacter *character, World *world)
{
  ACharacter *target;

  target = this->getTarget(world);
}

IAEngine::~IAEngine()
{
  
}

bool		IAEngine::isHumanPlayerAlive(std::vector<ACharacter *> vector)
{
  int		i;

  i = 0;
  while (i < vector.size())
    {
      if (vector.at(i).getType == HUMAN)
	return true;
      i++;
    }
  return false;
}

ACharacter	*IAEngine::getTarget(World *world)
{
  this->isHumanPlayerAlive(world->getPlayers())
}

std::vector<std::map[int:int]>	getPathToTarget(ACharacter *)
{

}
