//
// HumanCharacter.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue May 19 11:50:38 2015 Nicolas Charvoz
// Last update Tue May 19 12:12:30 2015 Nicolas Charvoz
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

private:

  static TextureManager& _texManag;
};

#endif
