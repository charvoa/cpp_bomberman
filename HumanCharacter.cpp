//
// HumanCharacter.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue May 19 11:55:01 2015 Nicolas Charvoz
// Last update Tue May 26 12:10:46 2015 Audibert Louis
//

#include "HumanCharacter.hh"

TextureManager &HumanCharacter::_texManag = TextureManager::getInstance();

HumanCharacter::HumanCharacter(char id, World *world)
{
  (void) world;
  this->_id = id;
  this->_hp = 100;
}

HumanCharacter::~HumanCharacter()
{
}

int HumanCharacter::getHp() const
{
  return _hp;
}

void HumanCharacter::dropBomb()
{
  std::cout << "I droped a bomb hahah" << std::endl;
}

void HumanCharacter::takeObject(AObject *object)
{
  this->_listObject.push_back(object);
}

void HumanCharacter::die()
{
  std::cout << "I died" << std::cout;
}

glm::mat4	getTransformation()
{
  glm::mat4	transform(1);
  // transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  // transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  // transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
  // transform = glm::translate(transform, _position);
  // transform = glm::scale(transform, _scale);
  return(transform);
}

void HumanCharacter::draw(gdl::Clock clock, gdl::BasicShader shader)
{
  (void)clock;
  // setCurrentAnim(0, true);
  // _model.draw(shader, getTransformation(), Input::getElpasedTime());
  _model.draw(shader, getTransformation(), 0);
}

void HumanCharacter::update() {}


Position	&HumanCharacter::getPos() const
{
  return (Position &) _pos;
}

int	HumanCharacter::getRange() const
{
  return _range;
}

int	HumanCharacter::getOrientation() const
{
  return _orientation;
}

void	HumanCharacter::setPos(Position &pos)
{
  _pos = pos;
}

void	HumanCharacter::setRange(int range)
{
  _range = range;
}

void	HumanCharacter::setOrientation(int orientation)
{
  _orientation = (e_orientation)orientation;
}

void	HumanCharacter::initColor()
{
  srand(time(NULL));
  _color.insert(std::pair<char,int>('r', rand() % 256));
  _color.insert(std::pair<char,int>('g', rand() % 256));
  _color.insert(std::pair<char,int>('b', rand() % 256));
}

std::map<char, int> &HumanCharacter::getColor() const
{
  return (std::map<char, int> &) _color;
}

void	HumanCharacter::setColor(int r, int g, int b)
{
  _color.insert(std::pair<char,int>('r', r));
  _color.insert(std::pair<char,int>('g', g));
  _color.insert(std::pair<char,int>('b', b));
}

int	HumanCharacter::getType() const
{
  return _type;
}
