//
// LoadGame.cpp for BBM in /home/heitzls/rendu/cpp_bomberman
//
// Made by Serge Heitzler
// Login   <heitzls@epitech.net>
//
// Started on  Thu May 21 16:14:04 2015 Serge Heitzler
// Last update Tue May 26 12:05:38 2015 Serge Heitzler
//

#include "LoadGame.hh"

LoadGame::LoadGame(Game *game, std::string &filename)
{
  std::ifstream	file;

  file.open(filename);
  this->setInitialMap(file);
  this->setPlayersInfo(file);
  this->setSavedMap(this->getBufferForMap(file));
  file.close();
}

void		LoadGame::setInitialMap(std::ifstream &file)
{
  std::string	filename;
  std::string	tmp;

  getline(file, tmp);
  filename = tmp.substr((tmp.find("MAP NAME ")));
  tmp.clear();
  tmp = "./maps/";
  filename += (".map");
  tmp += filename;
  _initialMap = new Map(tmp);
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
    _type = HUMAN;
  else
    _type = IA;
  _id = stoi(line.substr(1));
}

void	LoadGame::getPlayerPosition(std::string &line)
{
  _pos = Position(stoi(line.substr(line.find("POSX "), line.find("POSY") - 5)), line.find("POSY "));
}

void	LoadGame::getPlayerHP(std::string &line)
{
  _hp = stoi(line.substr(line.find("HP : ")));
}

void	LoadGame::getPlayerRange(std::string &line)
{
  _range = stoi(line.substr(line.find("RANGE : ")));
}

std::vector<ACharacter *>	LoadGame::getPlayers(std::ifstream &file)
{
  std::string			tmp;
  std::string			startMap;
  std::vector<ACharacter *>	vector;
  ACharacter *obj;

  this->determineStartMap();
  while (getline(file, tmp) != _startMap.c_str())
    {
      while (tmp != "*----------*" && tmp != startMap.c_str())
	{
	  getline(file, tmp);
	  this->getPlayerType(tmp);
	  getline(file, tmp);
	  this->getPlayerPosition(tmp);
	  getline(file, tmp);
	  this->getPlayerHP(tmp);
	  getline(file, tmp);
	  this->getPlayerRange(tmp);

	  if (_type == HUMAN)
	    obj = new HumanCharacter((char)_id, , _pos);
	  else
	    obj = new IACharacter(_id, , _pos);
	  vector.push_back(obj);
	}
    }
  return (vector);
}

std::stringstream&			LoadGame::getBufferForMap(std::ifstream &file)
{
  int					i;
  std::string				tmp;

  i = 0;
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
