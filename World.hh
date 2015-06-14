//
// World.hh for World in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri May 22 10:10:43 2015 Antoine Garcia
// Last update Sun Jun 14 17:58:49 2015 Antoine Garcia
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
#include "IACharacter.hh"
#include "ia/IAEngine.hh"
#include "Cube.hh"
#include "Box.hh"
#include "Bomb.hh"
#include "Bonus.hh"
#include "Scoring.hh"
class	Bonus;
class	Flame;
class	Command;
class	World : public GameState
{
private:
  std::vector<ACharacter *> _players;
  std::vector<std::vector<char> >	_map;
  std::vector<AObject*>			_objects;
  int			_nbPlayers;
  int			_nbIa;
  int			_height;
  int			_width;
  std::string		_name;
  //Graphical Attributes
  static TextureManager &_texManag;
  AObject		*_background;
  InputManager		*_inputManager;
  Command		*_command;
  void			checkPlayersDeath(Flame&);
  void			checkDestroyBoxes(Flame&);
  void			createHumanPlayer(char id, Position & pos);
  void			createIaPlayer();
  void			gameOver();
  void			checkBonus(Bonus &bonus);
public:
  World(Game *game, Map &map, int nb_players, int nb_ia);
  World(Game *game, Map &map, int nb_players);
  ~World(){};
  virtual void draw(gdl::Clock&, gdl::BasicShader&);
  virtual bool update(gdl::Clock&, gdl::Input&); //get InputKeys and update.
  const std::vector<std::vector<char> >&	getWorld() const;
  const std::vector<ACharacter *>& getPlayers() const;
  bool		setItemAtPosition(Position&, char c);
  char		getItemAtPosition(int x, int y);
  void		drawBackground(gdl::Clock&, gdl::BasicShader &);
  void		loadBackground();
  void		findWall();
  Game		*_game;
  int		getWidth() const;
  int		getHeight() const;
  const std::string&	getMapName() const;
  void		setBonus(Position &);
  bool checkPlayerCanMove(int x, int y);
  ACharacter*		getPlayerById(int id);
  void	dropBomb(Position &, int);
  Map			*_fileMap;
  const std::vector<HumanCharacter*> getHumansPlayers();
  void					checkDamages(std::list<Flame*>&);
};

#endif
