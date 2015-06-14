//
// SaveGame.hh for BBM in /home/heitzls/rendu/cpp_bomberman
//
// Made by Serge Heitzler
// Login   <heitzls@epitech.net>
//
// Started on  Wed May 20 10:54:39 2015 Serge Heitzler
// Last update Fri Jun  5 08:16:52 2015 Nicolas Charvoz
//

#ifndef SAVEGAME_HH_
# define SAVEGAME_HH_

# include <string>
# include <iostream>
# include <fstream>
# include <vector>
# include <list>
# include "ACharacter.hh"
# include "World.hh"

class		SaveGame
{
public:
  SaveGame(World &world, const std::string mapName);
  ~SaveGame();

  void		writeMapName(std::ofstream & file, const std::string & mapName);
  void		writeMap(std::ofstream & file);
  std::string	writeType(int type, int id);
  void		writeInfo(std::ofstream & file, std::vector<ACharacter*> characters);

private:
  std::vector<std::vector<char> > _map;
  World				  *_world;
};

#endif
