//
// LoadGame.hh for BBM in /home/heitzls/rendu/cpp_bomberman
//
// Made by Serge Heitzler
// Login   <heitzls@epitech.net>
//
// Started on  Thu May 21 16:14:32 2015 Serge Heitzler
// Last update Fri Jun  5 13:05:54 2015 Nicolas Charvoz
//

#ifndef LOADGAME_HH_
# define LOADGAME_HH_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Map.hh"
#include "Game.hh"
#include "ACharacter.hh"
#include "HumanCharacter.hh"
#include "IACharacter.hh"

class		LoadGame
{
public:

  LoadGame(Game *game);
  ~LoadGame();
  void				setInitialMap(std::ifstream &file);
  void				setPlayersInfo(std::ifstream &file);
  void				determineStartMap();
  std::vector<ACharacter *>	getPlayers(std::ifstream &file);
  std::stringstream&		getBufferForMap(std::ifstream &file);
  void				setSavedMap(std::stringstream &map);
  void				getPlayerType(std::string &line);
  void				getPlayerPosition(std::string &line);
  void				getPlayerHP(std::string &line);
  void				getPlayerRange(std::string &line);
  Map				&getInitialMap();
  int				getNbHumanPlayers();

private:
  Game					*_game;
  Map					*_initialMap;
  World					*_world;
  std::vector<std::vector<char> >	_savedMap;
  std::string				_startMap;
  std::stringstream			_bufferGetBufferForMap;
  e_type				_type;
  int					_id;
  Position				_pos;
  int					_hp;
  int					_range;
  int					_nbHumanPlayers;
};

#endif
