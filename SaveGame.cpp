//
// Save.cpp for BBM in /home/heitzls/rendu/cpp_bomberman
//
// Made by Serge Heitzler
// Login   <heitzls@epitech.net>
//
// Started on  Wed May 20 10:56:14 2015 Serge Heitzler
// Last update Fri Jun  5 08:16:34 2015 Nicolas Charvoz
//

#include "SaveGame.hh"

SaveGame::SaveGame(World &world, const std::string & mapName)
{
  _map = world->getWorld();
  std::ifstream file(mapName, std::ios::in | std::ios::trunc | std::ios:app);

  this->writeMapName(file, mapName);
  this->writeInfo();
  this->writeMap(file);
}

void		SaveGame::writeMapName(std::ifstream & file, const std::string & mapName)
{
  file << "MAP NAME " << mapName << "\n";
}

void		SaveGame::writeMap(std::ifstream & file)
{
  int		x;
  int		y;

  y = 0;
  while (y < _map.size())
    {
      x = 0;
      while (x < _map.at(y).size())
	{
	  file << _map.at(y).at(x);
	  x++;
	}
      file << "\n";
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
  int		i;

  i = 0;
  file << "*----------*" << std::endl;
  while (i < characters.size())
    {
      file << this->writeType(file, characters.at(i)->getType(), characters.at(i)->getId()) << std::endl;
      file << "POSX " << characters.at(i)->getPosX() << " POSY " << characters.at(i)->getPosY() << std::endl;
      file << "HP : " << characters.at(i)->getHp() << std::endl;
      file << "RANGE : " << characters.at(i)->getRange() << std::endl;
      file << "*----------*" << std::endl;
    }
}

SaveGame::~SaveGame()
{

}
