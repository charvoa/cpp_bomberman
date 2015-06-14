//
// Save.cpp for BBM in /home/heitzls/rendu/cpp_bomberman
//
// Made by Serge Heitzler
// Login   <heitzls@epitech.net>
//
// Started on  Wed May 20 10:56:14 2015 Serge Heitzler
// Last update Fri Jun  5 14:06:45 2015 Nicolas Charvoz
//

#include "SaveGame.hh"

SaveGame::SaveGame(World &world, const std::string mapName)
{
  std::string	root;
  std::ofstream file;

  root = "./saves/lastgame.save";
  _world = &world;
  _map = _world->getWorld();
  file.open(root);

  this->writeMapName(file, mapName);
  //  this->writeInfo(file, world.getPlayers());
  this->writeMap(file);
  file.close();
  std::cout << "SaveGame << " << std::endl;
}

void		SaveGame::writeMapName(std::ofstream & file, const std::string & mapName)
{
  file << "MAPNAME:" << mapName << "\n";
}

void		SaveGame::writeMap(std::ofstream & file)
{
  unsigned int		x;
  unsigned int		y;

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

std::string    	SaveGame::writeType(int type, int id)
{
  if (type == 0)
    return ("P" + std::to_string(id));
  return ("I" + std::to_string(id));
}

void			SaveGame::writeInfo(std::ofstream & file, std::vector<ACharacter*> characters)
{
  unsigned int		i;
  std::string		separator;

  i = 0;
  separator = "*----------*";
  file << separator << std::endl;
  while (i < characters.size())
    {
      file << this->writeType(characters.at(i)->getType(), characters.at(i)->getId()) << std::endl;
      file << "POSX " << characters.at(i)->getPos()._x << " POSY " << characters.at(i)->getPos()._y << std::endl;
      file << "HP : 1" << std::endl;
      file << "RANGE : " << characters.at(i)->getRange() << std::endl;
      file << separator << std::endl;
      i++;
    }
}

SaveGame::~SaveGame()
{

}
