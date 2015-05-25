//
// LoadGame.cpp for BBM in /home/heitzls/rendu/cpp_bomberman
//
// Made by Serge Heitzler
// Login   <heitzls@epitech.net>
//
// Started on  Thu May 21 16:14:04 2015 Serge Heitzler
// Last update Mon May 25 19:54:31 2015 Serge Heitzler
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
  this->_initialMap(filename + ".map");
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

std::list<ACharacter *>	LoadGame::getPlayers(std::ofstream &file)
{
  std::string	tmp;
  std::string	startMap;

  startMap = determineStartMap();
  while (getline(file, tmp) != startMap)
    {
      while (tmp != "*----------*" && tmp != startMap)
	{
	  getline(file, tmp);
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
  std::string::iterator		       	x;
  int					i;
  int					j;

  j = 0;
  while (x != map.str().end())
    {
      i = 0;
      while (map.str()[i] != '\n')
	{
	  this->_map[j][i] = map.str()[(j * (_width + 1)) + i];
	  i++;
	  x++;
	}
      x++;
      j++;
    }
}

LoadGame::~LoadGame()
{

}
