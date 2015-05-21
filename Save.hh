//
// Save.hh for BBM in /home/heitzls/rendu/cpp_bomberman
// 
// Made by Serge Heitzler
// Login   <heitzls@epitech.net>
// 
// Started on  Wed May 20 10:54:39 2015 Serge Heitzler
// Last update Thu May 21 15:58:02 2015 Serge Heitzler
//

#ifndef SAVE_HH_
# define SAVE_HH_

# include <string>
# include <iostream>
# include <fstream>
# include <vector>
# include "ACharacter.hh"

class		Save
{
public:
  Save(std::vector<std::vector<char> > map, const std::string & mapName);
  ~Save();

  void		writeMapName(std::ifstream & file, const std::string & name);
  void		writeMap(std::ifstream & file, std::vector<std::vector<char> > map);
  std::string	writeType(e_type *type, int id);
  void		writeInfo(std::ifstream & file, std::list<ACharacter*> characters);

private:
  
};

#endif
