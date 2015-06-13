//
// Flame.hh for bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Mon Jun  1 10:58:30 2015 Nicolas Girardot
// Last update Sat Jun 13 13:41:55 2015 Audibert Louis
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
  int		_idPlayer;

public:
  Flame(Position *, World *, int);
  virtual	~Flame();
  bool	initialize(const std::string &);
  void	update(gdl::Clock const &, gdl::Input &);
  void	draw(gdl::AShader&, gdl::Clock const &);
  Position &getPos() const;
  bool	getStatus();
  void	onDrop();
  void	onDestroy();
  int	getIdPlayer() const;
};

#endif
