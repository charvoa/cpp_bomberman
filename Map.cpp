//
// Map.cpp for Map.hh in /home/heitzl_s/rendu/tmp
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.net>
//
// Started on  Mon May 25 18:56:25 2015 Serge Heitzler
// Last update Mon Jun  1 16:48:26 2015 Nicolas Charvoz
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
  while (i < 2)
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
	  std::cout << map.str()[(j * (_width)) + i];
	  i++;
	}
      std::cout << std::endl;
      _map.push_back(tmp);
      tmp.clear();
      j++;
    }
}

int					Map::getWidth() const
{
  return (this->_width);
}

int					Map::getHeight() const
{
  return (this->_height);
}

std::vector<std::vector<char> >&		Map::getMap()
{
  return (this->_map);
}

void					Map::setHeight(std::string &line)
{
  this->_height = stoi(line.substr(9, line.size() - line.find("X")));
}

void					Map::setWidth(std::string &line)
{
  this->_width = stoi(line.substr((line.find("X") + 1)));
}

char					Map::getItemAtPosition(int x, int y) const
{
  return (this->_map.at(y).at(x));
}

void					Map::setItemAtPosition(int x, int y, char c)
{
  this->_map.at(y).at(x) = c;
}


int	Map::getNumberOfFreeSpace() const
{
  int nbr = 0;

  for (int y = 0; y <= this->getWidth(); ++y)
    {
      for (int x = 0; x <= this->getHeight() ; ++x)
	{
	  if (this->getItemAtPosition(x, y) == 'F')
	    {
	      nbr++;
	    }
	}
    }
  return nbr;
}

void	Map::mapGenerator(int width, int height, int human, int ia)
{
  int					i;
  int					j;
  Math				        math;

  (void)human;
  (void)ia;
  math = Math();
  math.initSRand(math.initTime(NULL));
  j = 0;
  while (j < height)
    {
      i = 0;
      while (i < width)
	{
	  if (i == 0 || i == width - 1 || j == 0 || j == height - 1)
	    _randomMap.at(j).at(i) = 'W';
	  else
	    _randomMap.at(j).at(i) = 'F';
	  std::cout << _randomMap.at(j).at(i);
	  i++;
	}
      std::cout << std::endl;
      j++;
    }
}
