//
// World.cpp for World in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Sat May 23 18:46:16 2015 Antoine Garcia
// Last update Thu May 28 17:02:50 2015 Antoine Garcia
//

# include <iostream>
#include "World.hh"
#include "GameBackground.hh"

TextureManager &World::_texManag = TextureManager::getInstance();

World::World(Game *game, Map &map, int nb_players, int nb_ia)
{
  (void)nb_ia;
  _inputManager = new InputManager();
  _command = new Command(game, this);
  _game = game;
  _nbPlayers = nb_players;
  _nbIa = nb_ia;
  _fileMap = &map;
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
	      ACharacter *charac;
	      if (x == 14 && y == 10);
	      else
		{
		  if (_fileMap->getItemAtPosition(x,y) == '1')
		    charac = new HumanCharacter('1', this, pos);
		  else
		    charac = new HumanCharacter('2', this, pos);
		  _players.push_back(charac);
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
  for (std::vector<ACharacter*>::iterator it = _players.begin(); it != _players.end(); ++it)
    {
      (*it)->draw(shader, clock);
    }
}

ACharacter*	World::getPlayerById(int id)
{
   for (std::vector<ACharacter*>::iterator it = _players.begin(); it != _players.end(); ++it)
     {
       if ((*it)->getId() == id)
	 return *it;
     }
}
bool	World::update(gdl::Clock& clock, gdl::Input& input)
{
  _command->exec(_inputManager->getTouche(input));
  // if (input.getKey(SDLK_UP))
  //   getPlayerById(1)->move(UP);
  // else if (input.getKey(SDLK_RIGHT))
  //   getPlayerById(1)->move(RIGHT);
  // else if (input.getKey(SDLK_DOWN))
  //   getPlayerById(1)->move(DOWN);
  // else if (input.getKey(SDLK_LEFT))
  //   getPlayerById(1)->move(LEFT);
  clock = clock;
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
    {
      std::cout << pos._x <<"et" << pos._y << std::endl;
      if(this->checkPlayerCanMove(pos._x, pos._y))
	{
	  _map.at(pos._y).at(pos._x) = c;
	  return true;
	}
      return false;
    }
  return false;
}

char	World::getItemAtPosition(int x, int y)
{
  return (_map.at(y).at(x));
}

bool	World::checkPlayerCanMove(int x, int y)
{
  char	test;

  std::cout << "AAAA" << std::endl;
  // if (x > _fileMap->getWidth() || x < 0 ||
  //     y > _fileMap->getHeight() || y < 0)
  //   {
  //     std::cout << "Height " << _fileMap->getHeight() << "Width:" << _fileMap->getWidth() << std::endl;
  //     return false;
  //   }
  std::cout << "BBBB" << std::endl;
  test = getItemAtPosition(x, y);
  if (test == 'F')
    {
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
