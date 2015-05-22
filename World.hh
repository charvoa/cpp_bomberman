//
// World.hh for World in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri May 22 10:10:43 2015 Antoine Garcia
// Last update Fri May 22 10:52:43 2015 Antoine Garcia
//

#ifndef WORLD_HH__
# define WORLD_HH__

#include <list>
#include "GameState.hh"
#include "ACharacter.hh"
#include "HumanCharacter.hh"

class	World : public GameState
{
private:
  std::list<ACharacter *> _ia;
  int			_nbPlayers;
  int			_nbIa;
  Map			_map;
  HumanCharacter	*player1;
  HumanCharacter	*_player2;
public:
  World(Map &map, int nb_players, int nb_ia);
};

#endif
