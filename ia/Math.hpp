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

};

#endif