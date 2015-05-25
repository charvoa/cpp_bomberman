//
// World.cpp for World in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Sat May 23 18:46:16 2015 Antoine Garcia
// Last update Mon May 25 14:58:43 2015 Nicolas Girardot
//

#include "World.hh"

World::World(Map &map, int nb_players, int nb_ia)
{
  (void)nb_ia;
  _map = map.getMap();
  _player1 = new HumanCharacter(1);
  if (nb_players == 2)
    _player2 = new HumanCharacter(2);
}

void	World::draw(gdl::Clock&, gdl::BasicShader&)
{

}

bool	World::update(gdl::Clock&, gdl::Input&)
{
  return true;
}

bool	World::setItemAtPosition(int x, int y, char c)
{
  if (c == '1' || c == '2')
    return (this->checkPlayerCanMove(x, y, c));
  return true;
}

char	World::getItemAtPosition(int x, int y)
{
  return (_map.at(y).at(x));
}

bool	World::checkPlayerCanMove(int x, int y, char c)
{
  char	test;

  test = getItemAtPosition(x, y);
  if (test == 'F')
    {
      _map.at(y).at(x) = c;
      return true;
    }
  return false;
}
