//
// LoadGame.hh for BBM in /home/heitzls/rendu/cpp_bomberman
//
// Made by Serge Heitzler
// Login   <heitzls@epitech.net>
//
// Started on  Thu May 21 16:14:32 2015 Serge Heitzler
// Last update Mon May 25 19:52:57 2015 Serge Heitzler
//

#ifndef LOADGAME_HH_
# define LOADGAME_HH_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Map.hh"

class		LoadGame
{
public:
  LoadGame(std::string &filename);
  ~LoadGame();
  void		setInitialMap(std::ofstram &file);
  void		setPlayersInfo(std::ofstream &file);
  std::string&	determineStartMap();
  std::list<ACharacter *>	getPlayers(std::ofstream &file);
  std::stringstream&		getBufferForMap(std::ifstream &file);
  void				setSavedMap(std::stringstream &map);

private:
  Map					*_initialMap;
  std::vector<std::vector<char> >	savedMap;

};

#endif
