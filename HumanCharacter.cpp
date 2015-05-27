//
// HumanCharacter.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue May 19 11:55:01 2015 Nicolas Charvoz
// Last update Wed May 27 14:33:00 2015 Audibert Louis
//

#include "HumanCharacter.hh"

TextureManager &HumanCharacter::_texManag = TextureManager::getInstance();

HumanCharacter::HumanCharacter(char id, World *world)
{
  (void) world;
  this->_id = id;
  this->_hp = 100;
  _model = new ModelLoad();

  _model->initialize("./images/marvin.fbx");

  // glm::vec3 trans(0, -200, 800);
  // _model->translate(trans);

  // trans = glm::vec3(0.5, 0.5, 0.5);
  // _model->scale(trans);

  // trans = glm::vec3(0, -200, 0);
  // _model->rotate(trans, 180.0f);
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
  _model->draw(shader, clock);
}

void HumanCharacter::update()
{
}

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

ACharacter	&HumanCharacter::getCharacter()
{
  return *this;
}
