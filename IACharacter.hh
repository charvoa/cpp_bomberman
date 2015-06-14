//
// IACharacter.hh for IACharacter.hh in /home/audibe_l/rendu/cpp_bomberman
//
// Made by Audibert Louis
// Login   <audibe_l@epitech.net>
//
// Started on  Wed May 27 14:28:02 2015 Audibert Louis
// Last update Sat Jun 13 13:49:10 2015 Audibert Louis
//

#ifndef IACHARACTER_HH_
# define IACHARACTER_HH_

# include "ACharacter.hh"
# include "TextureManager.hh"
# include "ModelLoad.hh"
# include "Thread.hpp"

class World;
class IAEngine;

class IACharacter : public ACharacter {

public:

  IACharacter(int, World *, Position&);
  virtual ~IACharacter();
  void dropBomb();
  void takeObject(AObject *);
  void die();
  void draw(gdl::AShader &, gdl::Clock const &);
  void update();

  bool	getAlive() const;
  Position &getPos() const;
  int getRange() const;
  int getOrientation() const;
  int getId() const;
  bool getCanLaunchBomb() const;

  void setAlive(bool isalive);
  void setPos(Position &pos);
  void setRange(int range);
  void setOrientation(int orientation);
  void setCanLaunchBomb(bool launch);

  int	getType() const;
  ACharacter &getCharacter();

  bool move(e_orientation ori, gdl::Clock &clock);
  bool move(e_orientation ori);
  float	getAngle(e_orientation before, e_orientation after);

  void setBonus(int bonus);
  int getScore() const;
  void setScore(int score);

private:

  static TextureManager& _texManag;
  IAEngine		*_brain;
};

#endif /* IACHARACTER_HH_ */
