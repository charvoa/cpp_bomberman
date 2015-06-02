#ifndef MATH_HPP_
# define MATH_HPP_

#include <cmath>

class Math
{
public:
	Math(){}
	~Math(){}

	float	Math::squareRoot(float request)
	{
		return (sqrt(request));
	}

	int		Math::absolute(int request)
	{
		return (abs(request));
	}

	void	Math::initSRand(time_t time)
	{
		srand(time);
	}

	time_t	Math::initTime(time_t* timer);
	{
		return (time(0));
	}

	int 	Math::useRand()
	{
		return (rand());
	}

};

#endif