//
// ACharacter.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue May 19 11:10:12 2015 Nicolas Charvoz
// Last update Wed May 27 15:22:54 2015 Audibert Louis
//

#ifndef ACHARACTER_HH_
# define ACHARACTER_HH_

# include "AObject.hh"
# include "ModelLoad.hh"
# include "Position.hpp"
# include <Model.hh>
# include <BasicShader.hh>
# include <Clock.hh>

typedef enum e_orientation
  {
    UP,
    DOWN,
    LEFT,
    RIGHT
  }	e_orientation;

class ACharacter {

public:

  virtual ~ACharacter() {}
  virtual bool getAlive() const = 0;
  virtual void dropBomb() = 0;
  virtual void takeObject(AObject *) = 0;
  virtual void die() = 0;
  virtual void draw(gdl::Clock, gdl::BasicShader) = 0;
  virtual void update() = 0;

  virtual Position &getPos() const = 0;
  virtual int getRange() const = 0;
  virtual int getOrientation() const = 0;

  virtual void setPos(Position &pos) = 0;
  virtual void setRange(int range) = 0;
  virtual void setOrientation(int orientation) = 0;

  virtual void initColor() = 0;
  virtual std::map<char, int> &getColor() const = 0;
  virtual void setColor(int r, int g, int b) = 0;

  virtual int getType() const = 0;
  virtual ACharacter &getCharacter() = 0;

private:

  typedef enum e_type
    {
      HUMAN,
      IA
    }	e_type;

protected:

  std::string		_name;
  char			_id;
  int			_IAid;
  bool			_alive;
  std::list<AObject*>	_listObject;
  ModelLoad*		_model;
  Position		_pos;
  int			_range;
  e_orientation		_orientation;
  std::map<char, int>	_color;
  e_type		_type;
};

#endif
