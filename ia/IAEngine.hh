#ifndef IAEngine_HH_
# define IAEngine_HH_

#include <algorithm>
#include <vector>
#include <ctime>
#include <utility>
#include "../ACharacter.hh"
#include "../IACharacter.hh"
#include "../HumanCharacter.hh"
#include "Math.hpp"
#include "../IBrun.hh"

class		IAEngine : IBrun
{
public:
  IAEngine(IACharacter &ia, World &world);
  ~IAEngine();
  int			calculLength(int firstPosX, int secondPosX);
  int			calculWidth(int firstPosY, int secondPosY);
  float		        calculDistance(IACharacter &ia, HumanCharacter &human);
  HumanCharacter        *findClosestHumanPlayer(IACharacter &ia, World &world);
  HumanCharacter	*getTarget(IACharacter &ia, World &world);
  void			whatIsAroundMe(IACharacter &ia, World &world);
  void			setOperand(IACharacter &ia, HumanCharacter &target);
  bool			isPossibleToJoinTarget(IACharacter &ia, World &world, HumanCharacter &target);
  void			leaveThisPosition(IACharacter &ia, World &world);
  bool			isBombAroundMe(std::vector<char> &vector);
  bool			isBoxAroundMe(std::vector<char> &vector);
  bool			isHumanPlayerAroundMe(std::vector<char> &vector);
  bool			isBonusAroundMe(std::vector<char> &vector);
  bool			routeToTarget(int x, int y, IACharacter &ia, HumanCharacter &target);
  virtual void *backRun(void *Class);
private:
  int			_w;
  int			_l;
  int			_xIA;
  int			_yIA;
  int			_xHuman;
  int			_yHuman;
  float   	        _h1;
  float    		_h2;
  Math			_math;
  std::vector<char>	_aroundMe;
  Position		_pos;
  int			_ope[4];
  std::vector<std::pair<int,int>> _route;
  std::vector<std::vector<char>> _map;
  Thread			*_thread;
  void				*run();
};

#endif
