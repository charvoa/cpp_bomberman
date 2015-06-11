//
// LoadGame.cpp for BBM in /home/heitzls/rendu/cpp_bomberman
//
// Made by Serge Heitzler
// Login   <heitzls@epitech.net>
//
// Started on  Thu May 21 16:14:04 2015 Serge Heitzler
// Last update Thu Jun  4 19:09:16 2015 Nicolas Charvoz
//

#include "LoadGame.hh"

LoadGame::LoadGame(std::string &filename)
{
  ofstream	file;
  file.open(filename);
  this->setInitialMap(file);
  this->setPlayersInfo(file);
  this->setSavedMap(this->getBufferForMap(file));
  file.close();
}

void		LoadGame::setInitialMap(std::ofstream &file)
{
  std::string	filename;
  std::string	tmp;

  getline(file, tmp);
  filename = tmp.substr((tmp.find("MAP NAME ")));
  this->_initialMap("./maps/" + filename + ".map");
}

void		LoadGame::setPlayersInfo(std::ofstream &file)
{

}

std::string&	LoadGame::determineStartMap()
{
  int		i;
  std::string	tmp;

  i = 0;
  while (i < this->_initialMap->getWidth())
    {
      tmp << "W";
      i++;
    }
  tmp << std::endl;
  return (tmp);
}

e_type	LoadGame::getPlayerType(std::string &line)
{}

void	LoadGame::getPlayerPosition(ACharacter *character, std::string &line)
{
}

void	LoadGame::getPlayerHP(ACharacter *character, std::string &line)
{}
void	LoadGame::getPlayerBomb(ACharacter *character, std::string &line)
{}
void	LoadGame::getPlayerRange(ACharacter *character, std::string &line)
{}
void	LoadGame::getPlayerColor(ACharacter *character, std::string &line)
{}


std::list<ACharacter *>	LoadGame::getPlayers(std::ofstream &file)
{
  e_type	type;
  std::string	tmp;
  std::string	startMap;
  std::list<ACharacter *>	list;

  startMap = determineStartMap();
  while (getline(file, tmp) != startMap)
    {
      while (tmp != "*----------*" && tmp != startMap)
	{
	  getline(file, tmp);

	  type = this->getPlayerType(tmp);
	  if (type == HUMAN)
	    HumanCharacter *tmp = new HumanCharacter();
	  else
	    IACharacter *tmp = new IACharacter();


	  getline(file, tmp);
	  this->getPlayerPosition(tmp);
	  getline(file, tmp);
	  this->getPlayerHP(tmp);
	  getline(file, tmp);
	  this->getPlayerBomb(tmp);
	  getline(file, tmp);
	  this->getPlayerRange(tmp);
	  getline(file, tmp);
	  this->getPlayerColor(tmp);
	}
    }
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
  while (((i) * (j)) < (_width * _height))
    {
      i = 0;
      while (i < _width)
	{
	  tmp.push_back(map.str()[(j * (_width)) + i]);
	  i++;
	}
      _map.push_back(tmp);
      tmp.clear();
      j++;
    }
}

LoadGame::~LoadGame()
{

}
