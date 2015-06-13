#include "IAEngine.hh"
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
      //      this->leaveThisPosition();
      return 3;
    }
  return -1;
}

bool			IAEngine::isPossibleToJoinTarget(HumanCharacter &target)
{
  int i;
  int j;



  unsigned int r;
  unsigned int o;
  unsigned int index;

  r = 0;
  index = -1;
  _map = _world->getWorld();
  this->setOperand(0);
  if (this->routeToTarget(_ia->getPos()._x, _ia->getPos()._y, target) == true)
    _routes.push_back(std::make_pair(_route, _route.size()));
  std::cout << "J'ai fini le premier appel récursif" << std::endl;
  _route.clear();
  _map = _world->getWorld();
  this->setOperand(1);
  if (this->routeToTarget(_ia->getPos()._x, _ia->getPos()._y, target) == true)
    _routes.push_back(std::make_pair(_route, _route.size()));
  std::cout << "J'ai fini le deuxième appel récursif" << std::endl;
  _map = _world->getWorld();
  _route.clear();
  this->setOperand(2);
  if (this->routeToTarget(_ia->getPos()._x, _ia->getPos()._y, target) == true)
    _routes.push_back(std::make_pair(_route, _route.size()));
  std::cout << "J'ai fini le troisième appel récursif" << std::endl;
  _map = _world->getWorld();
  _route.clear();
  this->setOperand(3);
  if (this->routeToTarget(_ia->getPos()._x, _ia->getPos()._y, target) == true)
    _routes.push_back(std::make_pair(_route, _route.size()));
  std::cout << "J'ai fini le quatrième appel récursif" << std::endl;
  _route.clear();




  while (r < _routes.size() - 1)
    {
      std::cout << _routes.size() << std::endl;
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
      o = 0;
      while (o < _routes.at(index).first.size())
	{
	  std::cout << " " << _routes.at(index).first.at(o).first << "-" <<  _routes.at(index).first.at(o).second << " | ";
	  o++;
	}
      std::cout << std::endl;

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

	  // PRINT
	  j = 0;
	  while (j < _world->getHeight())
	    {
	      i = 0;
	      while (i < _world->getWidth())
		{
		  std::cout << _world->getWorld().at(j).at(i);
		  i++;
		}
	      std::cout << std::endl;
	      j++;
	    } 

	  usleep(50000);

	}

      o--;


      if (this->move() == 0)
	;
      else if (this->move() == 1 && o >= 1)
	{
	  std::cout << "ia X " << _ia->getPos()._x << "ia Y " << _ia->getPos()._y << std::endl;
	  _ia->move(this->giveOrientation());
	  std::cout << "ia X " << _ia->getPos()._x << "ia Y " << _ia->getPos()._y << std::endl;


	  //
	  j = 0;
	  while (j < _world->getHeight())
	    {
	      i = 0;
	      while (i < _world->getWidth())
		{
		  std::cout << _world->getWorld().at(j).at(i);
		  i++;
		}
	      std::cout << std::endl;
	      j++;
	    } 	  

	  this->leaveThisPosition();
	  std::cout << "ia X " << _ia->getPos()._x << "ia Y " << _ia->getPos()._y << std::endl;
	  _ia->move(this->giveOrientation());
	  std::cout << "ia X " << _ia->getPos()._x << "ia Y " << _ia->getPos()._y << std::endl;


	  //
	  j = 0;
	  while (j < _world->getHeight())
	    {
	      i = 0;
	      while (i < _world->getWidth())
		{
		  std::cout << _world->getWorld().at(j).at(i);
		  i++;
		}
	      std::cout << std::endl;
	      j++;
	    } 	  
	  //

	  sleep(3);
	}
      else
	{
	  _pos._x = _routes.at(index).first.at(o).first;
	  _pos._y = _routes.at(index).first.at(o).second;
	  _ia->move(this->giveOrientation());
	}



      // _pos._x = _routes.at(index).first.at(1).first;
      // _pos._y = _routes.at(index).first.at(1).second;
      // if (_ia->move(this->giveOrientation()) == true)
      // 	std::cout << "IA can move to ";
      // else
      // 	std::cout << "IA can't move to ";
      // std::cout << "[" << _routes.at(index).first.at(1).first << " : " << _routes.at(index).first.at(1).second << "]"  << std::endl;

    }





  _routes.clear();


  // if (this->routeToTarget(_ia->getPos()._x, _ia->getPos()._y, target) == true)
  //     {
  // 	// if (this->move() == 0)
  // 	//   ;
  // 	// else
  // 	//   {
  // 	//     _pos._x = _route.at(1).first;
  // 	//     _pos._y = _route.at(1).second;
  // 	//   }
  // 	// o = 1;


  // 	while (o < _route.size())
  // 	  {


  // 	    _pos._x = _route.at(o).first;
  // 	    _pos._y = _route.at(o).second;

  // 	    // if (this->move() == 0)
  // 	    //   ;
  // 	    // else

  // 	    // std::cout << "route size = " << _route.size() << std::endl;
  // 	    // if (_ia->move(this->giveOrientation()) == true)
  // 	    //   std::cout << "IA can move to ";
  // 	    // else
  // 	    //   std::cout << "IA can't move to ";
  // 	    // std::cout << "[" << _route.at(o).first << " : " << _route.at(o).second << "]" << " - node (" << o << ")" << std::endl;

	    
  // 	    std::cout << _route.size() << std::endl;
  // 	    j = 0;
  // 	    while (j < _world->getHeight())
  // 	      {
  // 		i = 0;
  // 		while (i < _world->getWidth())
  // 		  {
  // 		    std::cout << _world->getWorld().at(j).at(i);
  // 		    i++;
  // 		  }
  // 		std::cout << std::endl;
  // 		j++;
  // 	      }





  // 	    r = 0;
  // 	    while (r < _route.size())
  // 	      {
  // 	    	std::cout << " " << _route.at(r).first;
  // 	    	std::cout << " " << _route.at(r).second << " || ";
  // 	    	// PRINT ROUTE
  // 	    	r++;
  // 	      }
  // 	    std::cout << std::endl;






  // 	    sleep(2);
  // 	    o++;
  // 	  }
  //       return true;
  //     }
  //  this->move();
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

  (void)i;
  (void)j;
  (void)h;


  // while (h < 4)
  //   {
  //     std::cout << _ope[h] << std::endl;
  //     h++;
  //   }

  // while (j < _world->getHeight())
  //   {
  //     i = 0;
  //     while (i < _world->getWidth())
  // 	{
  // 	  std::cout << _map.at(j).at(i);
  // 	  i++;
  // 	}
  //     std::cout << std::endl;
  //     j++;
  //   }

    if (_map.at(y).at(x) == 'W' || _map.at(y).at(x) == '-'/* || _map.at(y).at(x) == 'I'*/)
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
