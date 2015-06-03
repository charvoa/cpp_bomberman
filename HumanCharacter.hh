//
// HumanCharacter.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue May 19 11:50:38 2015 Nicolas Charvoz
// Last update Wed Jun  3 13:56:12 2015 Audibert Louis
//

#ifndef HUMANCHARACTER_HH_
# define HUMANCHARACTER_HH_

# include "ACharacter.hh"
# include "TextureManager.hh"
# include "ModelLoad.hh"

class	World;
class	Bomb;

class HumanCharacter : public ACharacter {

public:

  HumanCharacter(char, World *, Position&);
  virtual ~HumanCharacter();
  bool getAlive() const;
  void dropBomb();
  void takeObject(AObject *);
  void die();
  void draw(gdl::AShader &shader, gdl::Clock const &clock);
  void update();

  Position &getPos() const;
  int getRange() const;
  int getOrientation() const;
  int getId() const;
  bool getCanLaunchBomb() const;

  void setPos(Position &pos);
  void setRange(int range);
  void setOrientation(int orientation);
  void setCanLaunchBomb(bool launch);

  void initColor();
  std::map<char, int> &getColor() const;
  void setColor(int r, int g, int b);

  int	getType() const;
  ACharacter &getCharacter();

  float getAngle(e_orientation before, e_orientation after);
  void move(e_orientation ori, gdl::Clock &);

private:

  static TextureManager& _texManag;
};

#endif
