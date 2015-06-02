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
