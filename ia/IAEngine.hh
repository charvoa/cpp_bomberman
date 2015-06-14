//
// IAEngine.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jun  5 13:13:41 2015 Nicolas Charvoz
// Last update Fri Jun  5 13:13:42 2015 Nicolas Charvoz
//

#ifndef IAEngine_HH_
# define IAEngine_HH_

# include <algorithm>
# include <vector>
# include <ctime>
# include <utility>
# include "../ACharacter.hh"
# include "../IACharacter.hh"
# include "../HumanCharacter.hh"
# include "Math.hpp"
# include "../IBrun.hh"

class		IAEngine : IBrun
{
public:
  IAEngine(IACharacter &ia, World &world);
  ~IAEngine();
  int			calculLength(int firstPosX, int secondPosX);
  int			calculWidth(int firstPosY, int secondPosY);
  float		        calculDistance(HumanCharacter &target);
  HumanCharacter        *findClosestHumanPlayer();
  HumanCharacter	*getTarget();
  void			whatIsAroundMe();
  void			setOperand(int opt);
  bool			isPossibleToJoinTarget(HumanCharacter &target);
  bool			isBombAroundMe(std::vector<char> &vector);
  bool			isBoxAroundMe(std::vector<char> &vector);
  bool			isHumanPlayerAroundMe(std::vector<char> &vector);
  bool			isBonusAroundMe(std::vector<char> &vector);
  bool			routeToTarget(int x, int y, HumanCharacter &target);
  void			leaveThisPosition();
  int			move();

  e_orientation		giveOrientation();
  virtual void *backRun(void *Class);
private:
  int			_w;
  int			_l;
  int			_xIA;
  int			_yIA;
  int			_xTarget;
  int			_yTarget;
  float   	        _h1;
  float    		_h2;
  Math			_math;
  std::vector<char>	_aroundMe;
  Position		_pos;
  int			_ope[4];
  World			*_world;
  IACharacter		*_ia;
  std::vector<std::pair<int,int>> _route;
  std::vector<std::pair<std::vector<std::pair<int,int>>, int>> _routes;
  std::vector<std::vector<char> >_map;
  Thread			*_thread;
  void				*run();
};

#endif
