//
// HumanCharacter.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue May 19 11:50:38 2015 Nicolas Charvoz
// Last update Mon May 25 15:47:26 2015 Serge Heitzler
//

#ifndef HUMANCHARACTER_HH_
# define HUMANCHARACTER_HH_

# include "ACharacter.hh"
# include "TextureManager.hh"

class HumanCharacter : public ACharacter {

public:

  HumanCharacter(int);
  virtual ~HumanCharacter();
  int getHp() const;
  void dropBomb();
  void takeObject(AObject *);
  void die();
  void draw(gdl::Clock, gdl::BasicShader);
  void update();

  int getPosX() const;
  int getPosY() const;
  int getRange() const;
  int getOrientation() const;

  void setPosX(int posX);
  void setPosY(int posY);
  void setRange(int range);
  void setOrientation(int orientation);

  void initColor();
  std::map<char, int> &getColor() const;
  void setColor(int r, int g, int b);

  int	getType() const;

private:

  static TextureManager& _texManag;
};

#endif
