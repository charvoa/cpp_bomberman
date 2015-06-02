//
// Flame.hh for bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Mon Jun  1 10:58:30 2015 Nicolas Girardot
// Last update Tue Jun  2 11:22:13 2015 Nicolas Girardot
//

#ifndef FLAME_HH_
# define FLAME_HH_

#include "AObject.hh"
#include "World.hh"
#include "Position.hpp"

class Flame : public AObject
{
private:
  AObject	*_flame;
  World		*_world;
  Position	*_pos;
  bool		_isPosed;
  double	_timer;
  bool		_isDestroyed = false;
public:
  Flame(Position *, World *);
  virtual	~Flame();
  bool	initialize(const std::string &);
  void	update(gdl::Clock const &, gdl::Input &);
  void	draw(gdl::AShader&, gdl::Clock const &);
  Position &getPos() const;
  bool	getStatus();
  void	onDrop();
  void	onDestroy();
};

#endif
