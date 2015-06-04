//
// Random.cpp for bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Jun  3 15:01:26 2015 Nicolas Girardot
// Last update Wed Jun  3 16:05:07 2015 Nicolas Girardot
//

#include "Random.hh"

Random::Random(int pourcentage) : _pourcentage(pourcentage)
{

}

Random::~Random()
{

}

void	Random::ssrand()
{
  srand(time(0));
}

bool	Random::getRandom()
{
  int	i = rand() % 100 + 1;
  if (i <= _pourcentage)
    return (true);
  return (false);
}
