//
// Random.hh for bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Jun  3 15:01:20 2015 Nicolas Girardot
// Last update Wed Jun  3 16:05:15 2015 Nicolas Girardot
//

#ifndef RANDOM_HH_
# define RANDOM_HH_

#include <cstdlib>
#include <ctime>
#include <cstdio>

class Random
{
private:
  int	_pourcentage;
public:
  Random(int);
  ~Random();
  void	ssrand();
  bool getRandom();
};

#endif
