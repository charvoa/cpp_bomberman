//
// Map.cpp for BBM in /home/heitzls/rendu/cpp_bomberman
//
// Made by Serge Heitzler
// Login   <heitzls@epitech.net>
//
// Last update Fri May 22 10:12:22 2015 Antoine Garcia
// Last update Tue May 19 18:02:56 2015 Nicolas Charvoz
//

#include "Map.hh"

Map::Map(const std::string &filename)
{
  std::ifstream file(filename, std::ios::in);
  std::string tmp;

  if(file)
    {
      getline(file, tmp);
      this->setWidth(tmp);
      this->setHeight(tmp);
      this->setMap(this->getBufferForMap(file));
      file.close();
    }
  else
    std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
}

Map::~Map()
{

}

std::stringstream&			Map::getBufferForMap(std::ifstream
							     &file)
{
  int					i;
  std::string				tmp;

  i = 0;
  while (i < 3)
    {
      getline(file, tmp);
      i++;
    }
  while (getline(file, tmp))
    _bufferGetBufferForMap << tmp;
  return (_bufferGetBufferForMap);
}

void					Map::setMap(std::stringstream &map)
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

int					Map::getWidth()
{
  return (this->_width);
}

int					Map::getHeight()
{
  return (this->_height);
}

std::vector<std::vector<char> >&		Map::getMap()
{
  return (this->_map);
}

void					Map::setWidth(std::string &line)
{
  this->_width = stoi(line.substr(10, line.size() - line.find("X")));
}

void					Map::setHeight(std::string &line)
{
  this->_height = stoi(line.substr((line.find("X") + 1)));
}

char					Map::getItemAtPosition(int x, int y)
{
  return (this->_map.at(y).at(x));
}

void					Map::setItemAtPosition(int x, int y, char c)
{
  this->_map.at(y).at(x) = c;
}
