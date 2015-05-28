//
// IACharacter.cpp for IACharacter.cpp in /home/audibe_l/rendu/cpp_bomberman
//
// Made by Audibert Louis
// Login   <audibe_l@epitech.net>
//
// Started on  Wed May 27 14:32:52 2015 Audibert Louis
// Last update Thu May 28 15:09:21 2015 Audibert Louis
//

#include "IACharacter.hh"

TextureManager &IACharacter::_texManag = TextureManager::getInstance();

IACharacter::IACharacter(int id, World *world)
{
  (void) world;
  this->_IAid = id;
  this->_alive = true;
  _model.load("./images/marvin.fbx");
  _orientation = DOWN;
}

IACharacter::~IACharacter()
{
}

bool IACharacter::getAlive() const
{
  return _alive;
}

void IACharacter::dropBomb()
{
  std::cout << "I droped a bomb hahah" << std::endl;
}

void IACharacter::takeObject(AObject *object)
{
  this->_listObject.push_back(object);
}

void IACharacter::die()
{
  std::cout << "I died" << std::cout;
}

void IACharacter::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void) clock;
  // _model->setCurrentAnim(1, true);
  _model.draw(shader, AObject::getTransformation(), 1);
}

void IACharacter::update()
{
}

Position	&IACharacter::getPos() const
{
  return (Position &) _pos;
}

int	IACharacter::getRange() const
{
  return _range;
}

int	IACharacter::getOrientation() const
{
  return _orientation;
}

int	IACharacter::getId() const
{
  return _IAid;
}

void	IACharacter::setPos(Position &pos)
{
  _pos = pos;
}

void	IACharacter::setRange(int range)
{
  _range = range;
}

void	IACharacter::setOrientation(int orientation)
{
  _orientation = (e_orientation)orientation;
}

void	IACharacter::initColor()
{
  srand(time(NULL));
  _color.insert(std::pair<char,int>('r', rand() % 256));
  _color.insert(std::pair<char,int>('g', rand() % 256));
  _color.insert(std::pair<char,int>('b', rand() % 256));
}

std::map<char, int> &IACharacter::getColor() const
{
  return (std::map<char, int> &) _color;
}

void	IACharacter::setColor(int r, int g, int b)
{
  _color.insert(std::pair<char,int>('r', r));
  _color.insert(std::pair<char,int>('g', g));
  _color.insert(std::pair<char,int>('b', b));
}

int	IACharacter::getType() const
{
  return _type;
}

ACharacter	&IACharacter::getCharacter()
{
  return *this;
}

void	IACharacter::move(e_orientation ori)
{
  (void)ori;
}
