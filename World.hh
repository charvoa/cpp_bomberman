//
// World.hh for World in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri May 22 10:10:43 2015 Antoine Garcia
// Last update Mon May 25 18:17:53 2015 Nicolas Girardot
//

#ifndef WORLD_HH__
# define WORLD_HH__

#include <list>
#include "Map.hh"
#include "Camera.hh"
#include "AObject.hh"
#include "GameState.hh"
#include "ACharacter.hh"
#include "TextureManager.hh"
#include "Game.hh"
#include "HumanCharacter.hh"

class	World : public GameState
{
private:
  std::list<ACharacter *> _ia;
  std::vector<std::vector<char> >	_map;
  int			_nbPlayers;
  int			_nbIa;
  Map			*_fileMap;
  HumanCharacter	*_player1;
  HumanCharacter	*_player2;
  //Graphical Attributes
  static TextureManager &_texManag;
  AObject		*_background;
  bool checkPlayerCanMove(int x, int y, char c);
public:
  World(Map &map, int nb_players, int nb_ia);
  ~World(){};
  virtual void draw(gdl::Clock&, gdl::BasicShader&);
  virtual bool update(gdl::Clock&, gdl::Input&); //get InputKeys and update.
  bool		setItemAtPosition(int x, int y, char c);
  char		getItemAtPosition(int x, int y);
  void		drawBackground(gdl::Clock&, gdl::BasicShader &);
  void		loadBackground();
};

#endif
