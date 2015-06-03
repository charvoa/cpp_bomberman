//
// main.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon May 25 17:58:36 2015 Nicolas Charvoz
// Last update Wed Jun  3 16:53:07 2015 Nicolas Girardot
//

#include "Game.hh"

int		main()
{
  Game origin;
  Random *m = new Random(33);

  m->ssrand();
  origin.run();
  return (0);
}
