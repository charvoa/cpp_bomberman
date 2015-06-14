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

class		SaveGame
{
public:
  SaveGame(World &world, const std::string & mapName);
  ~SaveGame();

  void		writeMapName(std::ifstream & file, const std::string & mapName);
  void		writeMap(std::ifstream & file);
  std::string	writeType(e_type *type, int id);
  void		writeInfo(std::ifstream & file, std::list<ACharacter*> characters);

private:

};

#endif
