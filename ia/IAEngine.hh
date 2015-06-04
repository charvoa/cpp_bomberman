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
  int			          calculLength(int firstPosX, int secondPosX);
  int			          calculWidth(int firstPosY, int secondPosY);
  float			        calculDistance(IACharacter &ia, HumanCharacter &human);
  HumanCharacter	  *findClosestHumanPlayer(IACharacter &ia, World &world);
  HumanCharacter	  *getTarget(IACharacter &ia, World &world);
  std::vector<char> whatIsAroundMe(IACharacter &ia, World &world);
  int               setOperand(IACharacter &ia, HumanCharacter &target);
  void              leaveThisPosition(IACharacter &ia, World &world);
  bool              isBombAroundMe(std::vector<char> &vector);
  bool              isBoxAroundMe(std::vector<char> &vector);
  bool              isHumanPlayerAroundMe(std::vector<char> &vector);
  bool              isBonusAroundMe(std::vector<char> &vector);
  bool              routeToTarget(int x, int y, std::vector<std::vector<char >> &map, std::vector<std::map<int:int>> &route, IACharacter &ia, HumanCharacter &target)
private:
  int                _w;
  int                _l;
  int                _xIA;
  int                _yIA;
  int                _xHuman;
  int                _yHuman;
  float   		       _h1;
  float    		       _h2;
  Math			         _math;
  std::vector<char>  _aroundMe;
  Position            pos;

};

#endif
