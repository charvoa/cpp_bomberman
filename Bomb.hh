//
// Bomb.hh for bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed May 27 14:15:33 2015 Nicolas Girardot
// Last update Mon Jun  8 15:22:42 2015 Nicolas Girardot
//

#ifndef BOMB_HH_
# define BOMB_HH_

#include "AObject.hh"
#include "World.hh"
#include "Position.hpp"
#include "Flame.hh"
#include "Bonus.hh"

class Flame;

class Bomb : public AObject
{
private:
  static Sound &_sound;
  int		_id;
  AObject	*_bomb;
  bool		_isPosed;
  bool		_isDestroyed = false;
  World		*_world;
  int		_range = 1;
  Position	_pos;
  double	_timer;
  bool		_isPlayed = 0;
  double	_otimer;
  std::list<Flame*>	_flames;
  bool		_isPoped = true;
public:
  Bomb(Position &, World *, int );
  virtual ~Bomb();
  bool		initialize(const std::string &);
  void		update(gdl::Clock const &, gdl::Input &);
  void		draw(gdl::AShader&, gdl::Clock const &);
  bool		getStatus();
  void		setRange(int);
  void		onDrop();
  void		onDestroy();
};

#endif
