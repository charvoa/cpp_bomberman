//
// IACharacter.hh for IACharacter.hh in /home/audibe_l/rendu/cpp_bomberman
//
// Made by Audibert Louis
// Login   <audibe_l@epitech.net>
//
// Started on  Wed May 27 14:28:02 2015 Audibert Louis
// Last update Thu May 28 15:08:41 2015 Audibert Louis
//

#ifndef IACHARACTER_HH_
# define IACHARACTER_HH_

# include "ACharacter.hh"
# include "TextureManager.hh"
# include "ModelLoad.hh"

class World;

class IACharacter : public ACharacter {

public:

  IACharacter(int, World *);
  virtual ~IACharacter();
  bool	getAlive() const;
  void dropBomb();
  void takeObject(AObject *);
  void die();
  void draw(gdl::AShader &, gdl::Clock const &);
  void update();

  Position &getPos() const;
  int getRange() const;
  int getOrientation() const;
  int getId() const;

  void setPos(Position &pos);
  void setRange(int range);
  void setOrientation(int orientation);

  void initColor();
  std::map<char, int> &getColor() const;
  void setColor(int r, int g, int b);

  int	getType() const;
  ACharacter &getCharacter();

  void move(e_orientation ori);

private:

  static TextureManager& _texManag;
};

#endif /* IACHARACTER_HH_ */
