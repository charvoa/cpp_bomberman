//
// World.hh for World in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri May 22 10:10:43 2015 Antoine Garcia
// Last update Thu May 28 15:18:17 2015 Antoine Garcia
//

#ifndef WORLD_HH__
# define WORLD_HH__

#include <list>
#include <map>
#include "InputManager.hh"
#include "Map.hh"
#include "Camera.hh"
#include "AObject.hh"
#include "GameState.hh"
#include "ACharacter.hh"
#include "TextureManager.hh"
#include "Game.hh"
#include "Position.hpp"
#include "HumanCharacter.hh"
#include "Cube.hh"

class	Command;
class	World : public GameState
{
private:
  std::vector<ACharacter *> _players;
  std::vector<std::vector<char> >	_map;
  std::vector<AObject*>			_objects;
  int			_nbPlayers;
  int			_nbIa;
  Map			*_fileMap;
  HumanCharacter	*_player1;
  HumanCharacter	*_player2;
  //Graphical Attributes
  static TextureManager &_texManag;
  AObject		*_background;
  InputManager		*_inputManager;
  Command		*_command;
  ACharacter*		getPlayerById(int id);
public:
  World(Game *game, Map &map, int nb_players, int nb_ia);
  ~World(){};
  virtual void draw(gdl::Clock&, gdl::BasicShader&);
  virtual bool update(gdl::Clock&, gdl::Input&); //get InputKeys and update.
  bool		setItemAtPosition(Position&, char c);
  char		getItemAtPosition(int x, int y);
  void		drawBackground(gdl::Clock&, gdl::BasicShader &);
  void		loadBackground();
  void		findWall();
  Game		*_game;
  int		getWidth() const;
  int		getHeight() const;
  bool checkPlayerCanMove(int x, int y);
};

#endif
