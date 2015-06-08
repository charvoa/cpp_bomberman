//
// Bonus.hh for Bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Thu Jun  4 17:19:40 2015 Nicolas Girardot
// Last update Mon Jun  8 14:12:38 2015 Nicolas Girardot
//

#ifndef BONUS_HH_
# define BONUS_HH_

#include "AObject.hh"
#include "World.hh"
#include "Position.hpp"

class Bonus : public AObject
{
private:
  AObject	*_bonus;
  World		*_world;
  Position	_pos;
public:
  Bonus(Position &, World*);
  ~Bonus();
  bool		initialize(const std::string &);
  void		update(gdl::Clock const &, gdl::Input &);
  void		draw(gdl::AShader&, gdl::Clock const &);
};
#endif
