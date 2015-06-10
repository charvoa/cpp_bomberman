//
// IACharacter.cpp for IACharacter.cpp in /home/audibe_l/rendu/cpp_bomberman
//
// Made by Audibert Louis
// Login   <audibe_l@epitech.net>
//
// Started on  Wed May 27 14:32:52 2015 Audibert Louis
// Last update Wed Jun  3 20:10:47 2015 Nicolas Charvoz
//

#include "IACharacter.hh"
#include "World.hh"
#include "ia/IAEngine.hh"

TextureManager &IACharacter::_texManag = TextureManager::getInstance();

IACharacter::IACharacter(int id, World *world, Position& pos)
{
  _world = world;
  this->_IAid = id;
  this->_alive = true;
  _model.load("./images/marvin.fbx");
  _orientation = DOWN;
  _type = IA;
  _canLaunchBomb = true;
  _timer = 0;
  _isAnime = false;
  _pos = pos;
  _world->setItemAtPosition(_pos, 'I');
  _sound.registerSound("./resources/sounds/allahu_akbar.wav", "allahu");
  glm::vec3 trans(0 + (_pos._x - _world->getWidth() / 2) * 100, -50,  750 * (-1) + (_pos._y - _world->getHeight() / 2) * 100);
  this->translate(trans);
  this->scale(glm::vec3(0.3, 0.3, 0.3));
  _brain = new IAEngine(*this, *_world);
}

IACharacter::~IACharacter()
{
  //delete _brain;
  std::cout << "IA is dead..." << std::endl;
}

bool IACharacter::getAlive() const
{
  return _alive;
}

void IACharacter::dropBomb()
{
  if (_canLaunchBomb == true)
    {
      std::cout << "I droped a bomb hahah" << std::endl;
      _canLaunchBomb = false;
      _world->dropBomb(_pos, _IAid);
      _sound.playMusic("allahu");
      _world->setItemAtPosition(_pos, 'T');
    }
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

bool	IACharacter::move(e_orientation ori, gdl::Clock &clock)
{
  (void) ori;
  (void) clock;
  return true;
}

bool	IACharacter::move(e_orientation ori)
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
  if (_world->checkPlayerCanMove(pos->_x, pos->_y) == true)
    {
      std::cout << "OK" << std::endl;
      glm::vec3 move(x * 100, 0, y * 100);
      if (_isAnime == false)
	{
	  _model.setCurrentAnim(0, false);
	  // _isAnime = true;
	}
      _timer += 1.0f;
      std::cout << "x = " << _pos._x << "; y = " << _pos._y << std::endl;
      std::cout << "timer = " << _timer << std::endl;
      if (_timer >= 2.0f)
      	{
	  this->translate(move);
	  _world->setItemAtPosition(_pos, 'F');
	  _world->setItemAtPosition(*pos, 'I');
	  _pos = *pos;
      	  _timer = 0;
      	}
      return true;
    }
  return false;
}

bool	IACharacter::getCanLaunchBomb() const
{
  return _canLaunchBomb;
}

void	IACharacter::setCanLaunchBomb(bool launch)
{
  _canLaunchBomb = launch;
}
