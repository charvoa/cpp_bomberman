//
// Save.cpp for BBM in /home/heitzls/rendu/cpp_bomberman
//
// Made by Serge Heitzler
// Login   <heitzls@epitech.net>
//
// Started on  Wed May 20 10:56:14 2015 Serge Heitzler
// Last update Fri Jun  5 12:11:22 2015 Nicolas Charvoz
//

#include "SaveGame.hh"

SaveGame::SaveGame(World &world, const std::string mapName)
{
  std::string	root;

  std::string strCopy(mapName);

  size_t pos = strCopy.find("./maps/");
  if (pos != std::string::npos)
    {
      strCopy.replace(pos, 7, "");
    }

  std::cout << "MapName = " << strCopy << std::endl;
  std::cout << "SaveGame >> " << std::endl;
  root = "./saves/";
  root += strCopy;
  root += ".save";
  _world = &world;
  _map = _world->getWorld();
  std::ofstream file;//(root, std::ios::in | std::ios::trunc | std::ios::app);

  // raplced mapName by strCopy
  file.open(root, std::ios::in | std::ios::trunc | std::ios::app);
  this->writeMapName(file, strCopy);
  this->writeInfo(file, world.getPlayers());
  this->writeMap(file);
  std::cout << "SaveGame << " << std::endl;
}

void		SaveGame::writeMapName(std::ofstream & file, const std::string & mapName)
{
  file << "MAP NAME " << mapName << "\n";
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
  file.close();
}

SaveGame::~SaveGame()
{

}
