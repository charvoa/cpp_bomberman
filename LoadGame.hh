//
// LoadGame.hh for BBM in /home/heitzls/rendu/cpp_bomberman
//
// Made by Serge Heitzler
// Login   <heitzls@epitech.net>
//
// Started on  Thu May 21 16:14:32 2015 Serge Heitzler
// Last update Mon May 25 15:46:00 2015 Serge Heitzler
//

#ifndef LOADGAME_HH_
# define LOADGAME_HH_

#include <iostream>
#include <fstream>
#include <vector>
#include "map.hh"

class		LoadGame
{
public:
  LoadGame();
  ~LoadGame();

private:
  Map					*_initialMap;
  std::vector<std::vector<char> >	savedMap;

};

#endif
