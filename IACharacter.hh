//
// IACharacter.hh for IACharacter.hh in /home/audibe_l/rendu/cpp_bomberman
// 
// Made by Audibert Louis
// Login   <audibe_l@epitech.net>
// 
// Started on  Wed May 27 14:28:02 2015 Audibert Louis
// Last update Wed May 27 14:32:14 2015 Audibert Louis
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
  int	getHp() const;
  void dropBomb();
  void takeObject(AObject *);
  void die();
  void draw(gdl::Clock, gdl::BasicShader);
  void update();

  Position &getPos() const;
  int getRange() const;
  int getOrientation() const;

  void setPos(Position &pos);
  void setRange(int range);
  void setOrientation(int orientation);

  void initColor();
  std::map<char, int> &getColor() const;
  void setColor(int r, int g, int b);

  int	getType() const;
  ACharacter &getCharacter();

private:

  static TextureManager& _texManag;
};

#endif /* IACHARACTER_HH_ */
