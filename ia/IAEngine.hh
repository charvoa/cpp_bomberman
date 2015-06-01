#ifndef IAEngine_HH_
# define IAEngine_HH_

#include <algorithm>
#include <vector>
#include <ctime>
#include "ACharacter.hh"

class		IAEngine
{
public:
  IAEngine();
  ~IAEngine();
  int			calculLength(int firstPosX, int secondPosX);
  int			calculWidth(int firstPosY, int secondPosY);
  float			calculDistance(IACharacter *ia, HumanCharacter *human);
  ACharacter	*findClosestHumanPlayer(IACharacter *ia, World *world);
  ACharacter	*getTarget(IACharacter *ia, World *world);
  bool      	isBombAroundMe(std::vector<char> &vector);
  bool      	isBoxAroundMe(std::vector<char> &vector);
  bool      	isHumanPlayerAroundMe(std::vector<char> &vector);

private:
  int           _w;
  int           _l;
  int           _xIA;
  int           _yIA;
  int           _xHuman;
  int           _yHuman;
  float   		_h1;
  float    		_h2;
  Math			_math;
  std::vector<char> _aroundMe;

};

#endif
