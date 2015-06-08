//
// Box.hh for Bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri May 29 15:01:23 2015 Nicolas Girardot
// Last update Mon Jun  8 15:51:04 2015 Nicolas Girardot
//

#ifndef BOX_HH_
# define BOX_HH_

#include "AObject.hh"
#include "World.hh"
#include "Position.hpp"

class Box : public AObject
{
private:
  static Sound	&_sound;
  AObject	*_box;
  bool		_isDestroyed = false;
  World		*_world;
  Position	*_pos;
public:
  Box(Position *, World *);
  virtual ~Box();
  bool	initialize(const std::string &);
  void	update(gdl::Clock const &, gdl::Input &);
  void	draw(gdl::AShader &, gdl::Clock const &);
  bool	getStatus();
  Position &getPosition() const;
  void	onDestroy();
};

#endif
