//
// Map.hh for BBM in /home/heitzls/rendu/cpp_bomberman
//
// Made by Serge Heitzler
// Login   <heitzls@epitech.net>
//
// Started on  Sat May 16 10:19:32 2015 Serge Heitzler
// Last update Fri Jun  5 13:32:39 2015 Nicolas Charvoz
//

#ifndef MAP_HH_
# define MAP_HH_

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "./ia/Math.hpp"

class		Map
{

public:

  Map(const std::string &filename);
  ~Map();
  std::stringstream&			getBufferForMap(std::ifstream &file);
  void					setMap(std::stringstream &map);
  int					getWidth() const;
  int					getHeight() const;
  std::vector<std::vector<char> >&	getMap();
  void					setWidth(std::string &line);
  void					setHeight(std::string &line);
  char					getItemAtPosition(int x, int y) const;
  void					setItemAtPosition(int x, int y,
							  char c);
  int					getNumberOfFreeSpace() const;
  const Map				&mapGenerator(int width, int height, int human, int ia);
  const std::string &  			getMapName();

  private:

  int					_width;
  int					_height;
  std::vector<std::vector<char> >	_map;
  std::stringstream _bufferGetBufferForMap;
  std::vector<std::vector<char>>	_randomMap;
  std::string		       	_mapName;
};

#endif
