#pragma once
#include <iostream>


namespace geometry
{

	#define TOLERANCE 0.0000001

	enum class RELATIVE_POS
	{
		LEFT, RIGHT, BEHIND, BEYOND, ORIGIN, DESTINATION, BETWEEN
	};
	
	template <typename T>
	static bool isEqual(T a, T b)
	{
		return fabs(a - b) < TOLERANCE;
	}

	static bool _xor(bool x, bool y)
	{
		return x ^ y;
	}
}