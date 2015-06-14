//
// LoadGame.cpp for BBM in /home/heitzls/rendu/cpp_bomberman
//
// Made by Serge Heitzler
// Login   <heitzls@epitech.net>
//
// Started on  Thu May 21 16:14:04 2015 Serge Heitzler
// Last update Sun Jun 14 20:46:23 2015 Antoine Garcia
//

#include "LoadGame.hh"

LoadGame::LoadGame(Game *game)
{
  std::ifstream	file;

  file.open("./saves/lastgame.save");
  _nbHumanPlayers = 0;
  _game = game;
  this->setInitialMap(file);
  //this->setPlayersInfo(file);
  //this->getPlayers(file);
  this->setSavedMap(this->getBufferForMap(file));
  _game->pushState(new World(_game, *_initialMap, _nbHumanPlayers));
  file.close();
}

void		LoadGame::setInitialMap(std::ifstream &file)
{
  std::string	filename;
  std::string	tmp;

  getline(file, tmp);
  filename = tmp.substr(tmp.find(":") + 1);
  _initialMap = new Map(filename);
  //_initialMap = new Map("./maps/x.map");
}

void		LoadGame::setPlayersInfo(std::ifstream &file)
{
  (void)file;
}

void		LoadGame::determineStartMap()
{
  int		i;
  std::string	tmp;

  i = 0;
  while (i < this->_initialMap->getWidth())
    {
      tmp.push_back('W');
      i++;
    }
  tmp.push_back('\n');
  _startMap = tmp;
}

void	LoadGame::getPlayerType(std::string &line)
{
  if (line[0] == 'P')
    {
      _nbHumanPlayers++;
      _type = HUMAN;
    }
  else
    _type = IA;
  _id = stoi(line.substr(1));
}

int		LoadGame::getNbHumanPlayers()
{
  return _nbHumanPlayers;
}

Map &		LoadGame::getInitialMap()
{
  return *_initialMap;
}

void	LoadGame::getPlayerPosition(std::string &line)
{
  std::string tmp;

  tmp = line;
  _pos = Position(stoi(line.substr(5, line.find("POSY"))), stoi(tmp.substr(tmp.find("POSY ") + 5)));

}

void	LoadGame::getPlayerHP(std::string &line)
{
  _hp = stoi(line.substr(line.find("HP : ")));
}

void	LoadGame::getPlayerRange(std::string &line)
{
  _range = stoi(line.substr(8));
}

std::vector<ACharacter *>	LoadGame::getPlayers(std::ifstream &file)
{
  std::string			tmp;
  std::string			startMap;
  std::vector<ACharacter *>	vector;
  //  ACharacter			*obj;

  this->determineStartMap();
  while (getline(file, tmp) != _startMap.c_str())
    {
      std::cout << "CACA" << std::endl;
      while (tmp != "*----------*" && tmp != startMap.c_str())
  	{
  	  //getline(file, tmp);
	  std::cout << "1 " <<  tmp << std::endl;
  	  this->getPlayerType(tmp);
  	  getline(file, tmp);
	  std::cout << "2 " <<  tmp << std::endl;
  	  this->getPlayerPosition(tmp);
  	  getline(file, tmp);
	  std::cout << "3 " <<  tmp << std::endl;
  	  //this->getPlayerHP(tmp);
  	  getline(file, tmp);
	  std::cout << "4 " <<  tmp << std::endl;
  	  this->getPlayerRange(tmp);
	  std::cout << "BOUDIN" << std::endl;
  	  // if (_type == HUMAN)
  	  //   obj = new HumanCharacter(to_string(_id), , _pos);
  	  // else
  	  //   obj = new IACharacter(_id, , _pos);
  	  // //	  obj->setAlive(true);
  	  // obj->setRange(_range);
  	  // vector.push_back(obj);
  	}
    }
  return (vector);
}

std::stringstream&			LoadGame::getBufferForMap(std::ifstream &file)
{
  // int					i;
  std::string				tmp;

  // i = 0;
  while (getline(file, tmp))
    _bufferGetBufferForMap << tmp;
  return (_bufferGetBufferForMap);
}

void		LoadGame::setSavedMap(std::stringstream &map)
{
  int					i;
  int					j;
  std::vector<char>			tmp;

  j = 0;
  while (((i) * (j)) < (_initialMap->getWidth() * _initialMap->getHeight()))
    {
      i = 0;
      while (i < _initialMap->getWidth())
	{
	  if (map.str()[(j * (_initialMap->getWidth())) + i] == '1'
	      || map.str()[(j * (_initialMap->getWidth())) + i] == '2')
	    _nbHumanPlayers = 2;
	  tmp.push_back(map.str()[(j * (_initialMap->getWidth())) + i]);
	  i++;
	}
      _savedMap.push_back(tmp);
      tmp.clear();
      j++;
    }
}

LoadGame::~LoadGame()
{

}
