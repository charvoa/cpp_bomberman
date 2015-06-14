//
// ACharacter.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue May 19 11:10:12 2015 Nicolas Charvoz
// Last update Sat Jun 13 13:53:17 2015 Audibert Louis
//

#ifndef ACHARACTER_HH_
# define ACHARACTER_HH_

# include "AObject.hh"
# include "ModelLoad.hh"
# include "Position.hpp"
# include "./Sound/SoundManager.hh"
# include <Model.hh>
# include <BasicShader.hh>
# include <Clock.hh>

class	World;

typedef enum e_orientation
  {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    UNKNOWN
  }	e_orientation;

typedef enum e_type
  {
    HUMAN,
    IA
  }	e_type;

class ACharacter : public AObject {

public:

  virtual ~ACharacter() {}
  virtual bool getAlive() const = 0;
  virtual void dropBomb() = 0;
  virtual void takeObject(AObject *) = 0;
  virtual void die() = 0;
  virtual void draw(gdl::AShader &, gdl::Clock const &) = 0;
  virtual void update() = 0;

  virtual Position &getPos() const = 0;
  virtual int getRange() const = 0;
  virtual int getOrientation() const = 0;
  virtual int getId() const = 0;
  virtual bool getCanLaunchBomb() const = 0;

  virtual void setPos(Position &pos) = 0;
  virtual void setRange(int range) = 0;
  virtual void setOrientation(int orientation) = 0;
  virtual void setCanLaunchBomb(bool launch) = 0;

  virtual int getType() const = 0;
  virtual ACharacter &getCharacter() = 0;

  virtual bool move(e_orientation ori, gdl::Clock &clock) = 0;

  virtual void setBonus(int bonus) = 0;
  virtual int getScore() const = 0;
  virtual void setScore(int score) = 0;

protected:

  std::string		_name;
  char			_id;
  int			_IAid;
  bool			_alive;
  std::list<AObject*>	_listObject;
  gdl::Model		_model;
  Position		_pos;
  int			_range;
  e_orientation		_orientation;
  e_type		_type;
  World			*_world;
  float			_timer;
  bool			_canLaunchBomb;
  static Sound		&_sound;
  bool			_isAnime;
  int			_score;
};

#endif
