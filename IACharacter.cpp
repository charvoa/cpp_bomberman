//
// IACharacter.cpp for IACharacter.cpp in /home/audibe_l/rendu/cpp_bomberman
//
// Made by Audibert Louis
// Login   <audibe_l@epitech.net>
//
// Started on  Wed May 27 14:32:52 2015 Audibert Louis
// Last update Fri May 29 14:56:36 2015 Audibert Louis
//

#include "IACharacter.hh"
#include "World.hh"

TextureManager &IACharacter::_texManag = TextureManager::getInstance();

IACharacter::IACharacter(int id, World *world)
{
  (void) world;
  this->_IAid = id;
  this->_alive = true;
  _model.load("./images/marvin.fbx");
  _orientation = DOWN;
  _type = IA;
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

float	IACharacter::getAngle(e_orientation before, e_orientation after)
{
  if ((before == UP && after == RIGHT)
      || (before == RIGHT && after == DOWN)
      || (before == DOWN && after == LEFT)
      || (before == LEFT && after == UP))
    return (90.0f);
  else if ((before == UP && after == DOWN)
	   || (before == RIGHT && after == LEFT)
	   || (before == DOWN && after == UP)
	   || (before == LEFT && after == RIGHT))
    return (180.0f);
  else if ((before == UP && after == LEFT)
	   || (before == RIGHT && after == UP)
	   || (before == DOWN && after == RIGHT)
	   || (before == LEFT && after == DOWN))
    return (270.0f);
  return (0.0f);
}

void	IACharacter::move(e_orientation ori, gdl::Clock &clock)
{
  glm::vec3 trans(0, 1, 0);
  Position *pos;
  int x = 0;
  int y = 0;

  this->rotate(trans, getAngle(_orientation, ori));
  _orientation = ori;

  if (ori == UP)
    {
      pos = new Position(_pos._x, _pos._y - 1);
      y = -1;
    }
  else if (ori == LEFT)
    {
      pos = new Position(_pos._x + 1, _pos._y);
      x = 1;
    }
  else if (ori == DOWN)
    {
      pos = new Position(_pos._x, _pos._y + 1);
      y = +1;
    }
  else if (ori == RIGHT)
    {
      pos = new Position(_pos._x - 1, _pos._y);
      x = -1;
    }
  if (_world->setItemAtPosition(*pos, _id) == true)
    {
      _pos = *pos;
      std::cout << "OK" << std::endl;
      glm::vec3 move(x * 100, 0, y * 100);
      _model.setCurrentAnim(0, false);
      this->translate(move * static_cast<float>(clock.getElapsed() * 20));
    }
}
