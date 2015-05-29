//
// testWorld.cpp for testWorld in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Sat May 23 22:59:18 2015 Antoine Garcia
// Last update Wed May 27 15:44:23 2015 Audibert Louis
//

#include "World.hh"

int	main()
{
  std::cout << "ok" << std::endl;
  Game *game();
  Map	map("maps/x.map");
  // World	test(&game, Map, 2, 2);
  HumanCharacter player1('1', new World(game, map, 2, 10));
}
