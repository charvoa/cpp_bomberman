//
// ACharacter.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue May 19 11:10:12 2015 Nicolas Charvoz
// Last update Tue May 19 12:16:04 2015 Nicolas Charvoz
//

#ifndef ACHARACTER_HH_
# define ACHARACTER_HH_

# include "AObject.hh"
# include <Model.hh>

class ACharacter {

public:

  virtual ~ACharacter() {}
  virtual int getHp() const = 0;
  virtual void dropBomb() = 0;
  virtual void takeObject(AObject *) = 0;
  virtual void die() = 0;

protected:

  std::string _name;
  int _id;
  int _hp;
  std::list<AObject*> _listObject;
  gdl::Model _model;
};

#endif
