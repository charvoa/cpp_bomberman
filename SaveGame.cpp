//
// Save.cpp for BBM in /home/heitzls/rendu/cpp_bomberman
// 
// Made by Serge Heitzler
// Login   <heitzls@epitech.net>
// 
// Started on  Wed May 20 10:56:14 2015 Serge Heitzler
// Last update Thu May 21 16:13:40 2015 Serge Heitzler
//

#include "SaveGame.hh"

SaveGame::SaveGame(std::vector<std::vector<char> > map, const std::string & mapName)
{
  std::ifstream file(mapName, std::ios::in | std::ios::trunc | std::ios:app);

  this->writeMapName(file, mapName);
  this->writeMap(file, map);
  this->writeInfo();
}

void		SaveGame::writeMapName(std::ifstream & file, const std::string & mapName)
{
  file << "MAP NAME " << mapName << std::endl;
}

void		SaveGame::writeMap(std::ifstream & file, std::vector<std::vector<char> > map)
{
  int		x;
  int		y;

  y = 0;
  while (y < map.size())
    {
      x = 0;
      while (x < map.at(y).size())
	{
	  file << map.at(y).at(x);
	  x++;
	}
      file << std::endl;
      y++;
    }
}

std::string    	SaveGame::writeType(e_type *type, int id)
{
  if (type == HUMAN)
    return ("P" + to_string(id));
  return ("I" + to_string(id));
}

void		SaveGame::writeInfo(std::ifstream & file, std::list<ACharacter*> characters)
{
  ACharacter	*tmp;
  int		i;

  i = 0;
  file << "*----------*" << std::endl;
  while (i < characters.size())
    {
      tmp = characters.at(i);
      file << this->writeType(file, tmp->getType(), tmp->getId()) << std::endl;
      file << "POSX " << tmp->getPosX() << " POSY " << tmp->getPosY() << std::endl;
      file << "HP : " << tmp->getHp() << std::endl;
      file << "BOMB : " << tmp->getBomb() << std::endl;
      file << "RANGE : " << tmp->getRange() << std::endl;
      file << "COLOR : R " << to_string(tmp->getColor()["r"]);
      file << " G " << to_string(tmp->getColor()["g"]);
      file << " B " << to_string(tmp->getColor()["b"]) << std::endl;
      file << "*----------*" << std::endl;
    }
}

SaveGame::~SaveGame()
{

}
