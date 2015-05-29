//
// Bomb.hh for bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed May 27 14:15:33 2015 Nicolas Girardot
// Last update Thu May 28 15:09:56 2015 Nicolas Girardot
//

#ifndef BOMB_HH_
# define BOMB_HH_

#include "AObject.hh"
#include "World.hh"
#include "Position.hpp"

class Bomb : public AObject
{
private:
  static Sound &_sound;
  AObject	*_bomb;
  bool		_isPosed;
  bool		_isDestroyed = false;
  World		*_world;
  int		_range;
  Position	*_pos;
  double	_timer;
  double	_otimer;
public:
  Bomb(Position *, World *);
  virtual ~Bomb();
  bool		initialize(const std::string &);
  void		update(gdl::Clock const &, gdl::Input &);
  void		draw(gdl::AShader&, gdl::Clock const &);
  bool		getStatus();
  void		onDrop();
  void		onDestroy();
};

#endif
