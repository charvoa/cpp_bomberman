//
// World.cpp for World in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Sat May 23 18:46:16 2015 Antoine Garcia
// Last update Tue Jun  9 14:59:15 2015 Antoine Garcia
//

# include <iostream>
# include "World.hh"
# include "GameBackground.hh"
# include "Flame.hh"
# include "GameOver.hh"
# include <unistd.h>
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
  createIaPlayer();
  _command = new Command(game, this);
}

void	World::findWall()
{
  AObject *wall;
  int	y = 0;
  int	x;
  Position p = Position(1, 1);
  wall = new Bomb(p, this, 5);
  wall->initialize("hh");
  wall = new Flame(new Position(1, 1), this);
  wall->initialize("hh");
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
	      if (x == 14 && y == 10);
	      else
		{
		  if (_fileMap->getItemAtPosition(x,y) == '1')
		    this->createHumanPlayer('1', pos);
		  else
		    {
		      if (_nbPlayers == 2)
			this->createHumanPlayer('2', pos);
		      else
			_map.at(y).at(x) = 'F';
		    }
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
	  wall = new Cube();
	  wall->initialize("./images/floor1.tga");
	  glm::vec3 trans(0 + (x - _fileMap->getWidth() / 2) * 100, -100,  750 * (-1) + (y - _fileMap->getHeight() / 2) * 100);
	  wall->translate(trans);
	  wall->scale(glm::vec3(100, 100, 100));
	  _objects.push_back(wall);
	  x++;
	}
      y++;
    }
}

void	World::createIaPlayer()
{
  // IACharacter *charac;
  // Position p = Position(3, 3);

  // std::cout << getItemAtPosition(p._x, p._y) << std::endl;
  // charac = new IACharacter(3, this, p);;

  // IAEngine *engine = new IAEngine(*charac, *this);
  // _players.push_back(charac);
  // (void)engine;

  // //IAEngine *engine = new IAEngine(*charac, *this);
  // _players.push_back(charac);
  // //(void)engine;
}

void	World::createHumanPlayer(char id, Position &pos)
{
  ACharacter *charac;

  charac = new HumanCharacter(id, this, pos);
  _players.push_back(charac);
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

void	World::gameOver()
{
  std::vector<HumanCharacter *> players;

  players = getHumansPlayers();
  if (_players.size() == 0)
    std::cout << "GAME OVER" << std::endl;
  else if (players.size() == 1 && _players.size() == 1)
    {
      sleep(1);
      _game->pushState(new GameOver(_game, players[0]->getId()));
    }
  else if (players.size() == 0 && _players.size() >= 1)
    {
      sleep(1);
      _game->pushState(new GameOver(_game, 0));
    }
}

bool	World::update(gdl::Clock& clock, gdl::Input& input)
{
  _command->exec(_inputManager->getTouche(input), clock);
  for (std::vector<AObject*>::iterator it = _objects.begin(); it != _objects.end(); ++it)
    {
      (*it)->update(clock, input);
      if ((*it)->getStatus() == false)
	{
	  delete (*it);
	  _objects.erase(it);
	  break;
	  // return true;
	}
    }
  gameOver();
  clock = clock;
  return true;
}

void	World::dropBomb(Position &pos, int id)
{
  Bomb	*bomb;
  std::cout << "ID IN DROP BOMB WORLD " << id << std::endl;
  bomb = new Bomb(pos, this, id);
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
      if(this->checkPlayerCanMove(pos._x, pos._y))
	{
	  Position oldPos = getPlayerById(c - '0')->getPos();
	  if (getItemAtPosition(oldPos._x, oldPos._y) == 'T')
	    _map.at(oldPos._y).at(oldPos._x) = 'E';
	  else
	    _map.at(oldPos._y).at(oldPos._x) = 'F';
	  _map.at(pos._y).at(pos._x) = c;
	  return true;
	}
      return false;
    }
  else
    {
      _map.at(pos._y).at(pos._x) = c;
      return false;
    }
}

void	World::setBonus(Position &pos)
{
  AObject *bonus;
  bonus = new Bonus(pos, this);
  bonus->initialize("hh");
  _objects.push_back(bonus);
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
      checkDestroyBoxes(**it);
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
	  _map.at(flame.getPos()._y).at(flame.getPos()._x) = 'F';
	  if (it == _players.end())
	    break;
  	}
    }
}

void		World::checkDestroyBoxes(Flame& flame)
{
  std::vector<AObject*>::iterator it;
  Box	*box;

  for (it = _objects.begin(); it != _objects.end() ; ++it)
    {
      if ((box = dynamic_cast<Box *>(*it)))
	{
	  if (box->getPosition() == flame.getPos())
	    {
	      box->onDestroy();
	      _map.at(flame.getPos()._y).at(flame.getPos()._x) = 'F';
	    }
	}
    }
}
