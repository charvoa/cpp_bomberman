//
// Bomb.hh for bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed May 27 14:15:33 2015 Nicolas Girardot
// Last update Thu May 28 13:55:30 2015 Nicolas Girardot
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
  Position	_pos;
  double	_timer;
public:
  Bomb(Position &, World *);
  ~Bomb();
  virtual bool	initialize(const std::string &);
  virtual void	update(gdl::Clock const &, gdl::Input &);
  virtual void	draw(gdl::Clock const &, gdl::BasicShader&);
  virtual bool	getStatus();
  void		onDrop();
  void		onDestroy();
};

#endif
