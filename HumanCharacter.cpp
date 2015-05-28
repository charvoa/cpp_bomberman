//
// HumanCharacter.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue May 19 11:55:01 2015 Nicolas Charvoz
// Last update Thu May 28 13:05:54 2015 Antoine Garcia
//

#include "HumanCharacter.hh"
#include "World.hh"

TextureManager &HumanCharacter::_texManag = TextureManager::getInstance();

HumanCharacter::HumanCharacter(char id, World *world, Position& pos)
{
  _world = world;
  std::cout << "id = " << id << std::endl;
  this->_id = id;
  this->_alive = true;
  _pos = pos;
  _model.load("./images/marvin.fbx");
  glm::vec3 trans(0 + (_pos._x - _world->getWidth() / 2) * 100, 0,  750 * (-1) + (_pos._y - _world->getHeight() / 2) * 100);
  this->translate(trans);
  this->scale(glm::vec3(0.3, 0.3, 0.3));
}

HumanCharacter::~HumanCharacter()
{
}

bool HumanCharacter::getAlive() const
{
  return _alive;
}

void HumanCharacter::dropBomb()
{
  std::cout << "I droped a bomb hahah" << std::endl;
  //new Bomb(Position &, World &);
}

void HumanCharacter::takeObject(AObject *object)
{
  this->_listObject.push_back(object);
}

void HumanCharacter::die()
{
  std::cout << "I died" << std::cout;
}

void HumanCharacter::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  // _model->setCurrentAnim(1, true);
  // if (!shader.load("./LibBomberman_linux_x64/shaders//basic.fp", GL_FRAGMENT_SHADER)
  //     ||!shader.load("./LibBomberman_linux_x64/shaders/basic.vp", GL_VERTEX_SHADER)
  //     ||!shader.build())
  //   return false;
  _model.draw(shader, AObject::getTransformation(), 1);
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
