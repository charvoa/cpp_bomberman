//
// Math.hpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jun  5 13:13:50 2015 Nicolas Charvoz
// Last update Fri Jun  5 13:13:51 2015 Nicolas Charvoz
//

#ifndef MATH_HPP_
# define MATH_HPP_

#include <cmath>

class Math
{
public:
  Math(){}
  ~Math(){}

  float	squareRoot(float request)
  {
    return (sqrt(request));
  }

  int	absolute(int request)
  {
    return (abs(request));
  }

  void	initSRand(time_t time)
  {
    srand(time);
  }

  time_t	initTime(time_t* timer)
  {
    return (time(timer));
  }

  int 	useRand()
  {
    return (rand());
  }

};

#endif
