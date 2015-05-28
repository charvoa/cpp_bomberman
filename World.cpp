//
// World.cpp for World in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Sat May 23 18:46:16 2015 Antoine Garcia
// Last update Thu May 28 13:05:37 2015 Antoine Garcia
// Last update Wed May 27 10:50:44 2015 Nicolas Girardot
//

#include "World.hh"
#include "GameBackground.hh"

TextureManager &World::_texManag = TextureManager::getInstance();

World::World(Game *game, Map &map, int nb_players, int nb_ia)
{
  (void)nb_ia;
  _game = game;
  _nbPlayers = nb_players;
  _nbIa = nb_ia;
  _fileMap = &map;
  _game->_camera->move(glm::vec3(0, 900, 0), glm::vec3(0, 0, - 750));
  _game->_camera->move(glm::vec3(0, 900, 0), glm::vec3(0, 0, -750));
  gdl::BasicShader shader = _game->getShader();
  shader.bind();
  shader.setUniform("view", _game->_camera->getTransformation());
  shader.setUniform("projection", _game->_camera->getProjection());
  _map = _fileMap->getMap();
  _texManag.registerTexture("backgroundInGame", "backIG");
  this->loadBackground();
  findWall();
}

void	World::findWall()
{
  AObject *wall;
  int	y = 0;
  int	x;
  while(y < _fileMap->getHeight())
    {
      x = 0;
      while(x < _fileMap->getWidth())
	{
	  if (_fileMap->getItemAtPosition(x, y) == 'W')
	    {
	      if (x == 14 && y == 10);
	      else
		{
		  wall = new Cube();
		  wall->initialize("./images/model/crate_tex3.tga");
		  glm::vec3 trans(0 + (x - _fileMap->getWidth() / 2) * 100, 0,  750 * (-1) + (y - _fileMap->getHeight() / 2) * 100);
		  wall->translate(trans);
		  wall->scale(glm::vec3(100, 100, 100));
		  _objects.push_back(wall);
		}
	    }
	  if (_fileMap->getItemAtPosition(x, y) == '1' || _fileMap->getItemAtPosition(x, y) == '2')
	    {
	      Position pos(x, y);
	      if (x == 14 && y == 10);
	      else
		{
		  if (_fileMap->getItemAtPosition(x,y) == '1')
		    wall = new HumanCharacter('1', this, pos);
		  else
		    wall = new HumanCharacter('2', this, pos);
		  _objects.push_back(wall);
		}
	    }
	  if (_fileMap->getItemAtPosition(x, y) == 'B')
	    {
	      if (x == 14 && y == 10);
	      else
		{
		  wall = new Cube();
		  wall->initialize("./images/model/crate_tex.tga");
		  glm::vec3 trans(0 + (x - _fileMap->getWidth() / 2) * 100, 0,  750 * (-1) + (y - _fileMap->getHeight() / 2) * 100);
		  wall->translate(trans);
		  wall->scale(glm::vec3(100, 100, 100));
		  _objects.push_back(wall);
		}
	    }
	  if (_fileMap->getItemAtPosition(x, y) == 'F' || (_fileMap->getItemAtPosition(x, y) == '1' || _fileMap->getItemAtPosition(x, y) == '2'))
	    {
	      if (x == 14 && y == 10);
	      else
		{
		  wall = new Cube();
		  wall->initialize("./images/model/crate_tex4.tga");
		  glm::vec3 trans(0 + (x - _fileMap->getWidth() / 2) * 100, -100,  750 * (-1) + (y - _fileMap->getHeight() / 2) * 100);
		  wall->translate(trans);
		  wall->scale(glm::vec3(100, 100, 100));
		  _objects.push_back(wall);
		}
	    }

	  x++;
	}
      y++;
    }
}

void	World::draw(gdl::Clock& clock, gdl::BasicShader& shader)
{
  this->drawBackground(clock, shader);
  for (std::vector<AObject*>::iterator it = _objects.begin(); it != _objects.end(); ++it)
    {
      (*it)->draw(shader, clock);
    }
}

bool	World::update(gdl::Clock& clock, gdl::Input& shader)
{
  clock = clock;
  shader = shader;
  return true;
}

void	World::loadBackground()
{
  AObject *background = new GameBackground();

  background->initialize(_texManag.getTexture("backIG"));
  _background = background;
}

void	World::drawBackground(gdl::Clock& clock, gdl::BasicShader &shader)
{

  _background->draw(shader, clock);
}

bool	World::setItemAtPosition(Position& pos, char c)
{
  if (c == '1' || c == '2')
    return (this->checkPlayerCanMove(pos._x, pos._y, c));
  return true;
}

char	World::getItemAtPosition(int x, int y)
{
  return (_map.at(y).at(x));
}

bool	World::checkPlayerCanMove(int x, int y, char c)
{
  char	test;

  test = getItemAtPosition(x, y);
  if (test == 'F')
    {
      _map.at(y).at(x) = c;
      return true;
    }
  return false;
}

int	World::getWidth() const
{
  return _fileMap->getWidth();
}

int	World::getHeight() const
{
  return _fileMap->getHeight();
}
