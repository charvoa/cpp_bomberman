//
// SaveGame.hh for BBM in /home/heitzls/rendu/cpp_bomberman
//
// Made by Serge Heitzler
// Login   <heitzls@epitech.net>
//
// Started on  Wed May 20 10:54:39 2015 Serge Heitzler
// Last update Mon May 25 15:46:02 2015 Serge Heitzler
//

#ifndef SAVEGAME_HH_
# define SAVEGAME_HH_

# include <string>
# include <iostream>
# include <fstream>
# include <vector>
# include "ACharacter.hh"

class		SaveGame
{
public:
  SaveGame(std::vector<std::vector<char> > map, const std::string & mapName);
  ~SaveGame();

  void		writeMapName(std::ifstream & file, const std::string & name);
  void		writeMap(std::ifstream & file, std::vector<std::vector<char> > map);
  std::string	writeType(e_type *type, int id);
  void		writeInfo(std::ifstream & file, std::list<ACharacter*> characters);

private:

};

#endif
