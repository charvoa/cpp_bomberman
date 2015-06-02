//
// World.cpp for World in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Sat May 23 18:46:16 2015 Antoine Garcia
// Last update Tue Jun  2 16:15:59 2015 Nicolas Girardot
//

# include <iostream>
# include "World.hh"
# include "GameBackground.hh"
# include "Flame.hh"

TextureManager &World::_texManag = TextureManager::getInstance();

World::World(Game *game, Map &map, int nb_players, int nb_ia)
{
  (void)nb_ia;
  _inputManager = new InputManager();
  _game = game;
  _nbPlayers = nb_players;
  _nbIa = nb_ia;
  _fileMap = &map;
  _height = _fileMap->getHeight();
  _width = _fileMap->getWidth();
  _game->_camera->move(glm::vec3(0, 900, 0), glm::vec3(0, 0, -750));
  gdl::BasicShader shader = _game->getShader();
  shader.bind();
  shader.setUniform("view", _game->_camera->getTransformation());
  shader.setUniform("projection", _game->_camera->getProjection());
  _map = _fileMap->getMap();
  _texManag.registerTexture("backgroundInGame", "backIG");
  this->loadBackground();
  findWall();
  _command = new Command(game, this);
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
		  wall->initialize("./images/wall.tga");
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
		  wall = new Box(new Position(x, y), this);
		  wall->initialize("hello");
		  _objects.push_back(wall);
		}
	    }
	  if (_fileMap->getItemAtPosition(x, y) == 'F' || (_fileMap->getItemAtPosition(x, y) == '1' || _fileMap->getItemAtPosition(x, y) == '2'))
	    {
	      if (x == 14 && y == 10);
	      else
		{
		  wall = new Cube();
		  wall->initialize("./images/floor1.tga");
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
  if (getHeight() >= 15);
  else
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
   return NULL;
}
bool	World::update(gdl::Clock& clock, gdl::Input& input)
{
  _command->exec(_inputManager->getTouche(input), clock);
  // if (input.getKey(SDLK_UP))
  //   getPlayerById(1)->move(UP);
  // else if (input.getKey(SDLK_RIGHT))
  //   getPlayerById(1)->move(RIGHT);
  // else if (input.getKey(SDLK_DOWN))
  //   getPlayerById(1)->move(DOWN);
  // else if (input.getKey(SDLK_LEFT))
  //   getPlayerById(1)->move(LEFT);
  for (std::vector<AObject*>::iterator it = _objects.begin(); it != _objects.end(); ++it)
    {
      (*it)->update(clock, input);
      if ((*it)->getStatus() == false)
	{
	  delete (*it);
	  _objects.erase(it);
	  return true;
	}
   }
  clock = clock;
  return true;
}

void	World::dropBomb(Position *pos)
{
  Bomb	*bomb;
  bomb = new Bomb(pos, this);
  bomb->initialize("hello");
  _objects.push_back(bomb);
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
	  Position oldPos = getPlayerById(c - '0')->getPos();
	  _map.at(oldPos._y).at(oldPos._x) = 'F';
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

  if (x > _width || x < 0 ||
      y > _height || y < 0)
    {
      std::cout << "Height " << _fileMap->getHeight() << "Width:" << _fileMap->getWidth() << std::endl;
      return false;
    }
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
  return _width;
}

int	World::getHeight() const
{
  return _height;
}

const std::vector<std::vector<char> >&	World::getWorld() const
{
  return	_map;
}


const std::vector<ACharacter *>& World::getPlayers() const
{
  return _players;
}

const std::vector<HumanCharacter*>	World::getHumansPlayers()
{
  std::vector<HumanCharacter*> players;
  HumanCharacter *player;

  player = static_cast<HumanCharacter*>(getPlayerById(1));
  if (player != NULL)
    players.push_back(player);
  player = static_cast<HumanCharacter*>(getPlayerById(2));
  if (player != NULL)
    players.push_back(player);
  return players;
}

void		World::checkDamages(std::list<Flame*>& flames)
{
  std::list<Flame*>::iterator it;

  for (it = flames.begin() ; it != flames.end() ; ++it)
    {
      checkPlayersDeath(**it);
    }
}

void			World::checkPlayersDeath(Flame& flame)
{
  std::vector<ACharacter*>::iterator it;
  for (it = _players.begin() ; it != _players.end() ; ++it)
    {
      if ((*it)->getPos() == flame.getPos())
  	{
	  delete *it;
	  it = _players.erase(it);
	  if (it == _players.end())
	    break;
  	}
    }
}

void		World::checkDestroyBoxes(Flame& flame)
{
  (void) flame;
}
