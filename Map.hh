//
// Map.hh for BBM in /home/heitzls/rendu/cpp_bomberman
//
// Made by Serge Heitzler
// Login   <heitzls@epitech.net>
//
// Started on  Sat May 16 10:19:32 2015 Serge Heitzler
// Last update Sat May 23 19:32:15 2015 Antoine Garcia
//

#ifndef MAP_HH_
# define MAP_HH_

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class		Map
{

public:

  Map(const std::string &filename);
  ~Map();
  std::stringstream&			getBufferForMap(std::ifstream &file);
  void					setMap(std::stringstream &map);
  int					getWidth();
  int					getHeight();
  std::vector<std::vector<char> >&	getMap();
  void					setWidth(std::string &line);
  void					setHeight(std::string &line);
  char					getItemAtPosition(int x, int y);
  void					setItemAtPosition(int x, int y, char c);

  private:

  int					_width;
  int					_height;
  std::vector<std::vector<char> >	_map;
  std::stringstream _bufferGetBufferForMap;
};

#endif
