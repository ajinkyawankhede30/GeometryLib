#include "Intersection.h"

using namespace geometry;

bool geometry::intersection(const Vector<int, DIM2>& a, const Vector<int, DIM2>& b, const Vector<int, DIM2>& c, const Vector<int, DIM2>& d)
{
	RELATIVE_POS ab_c = (RELATIVE_POS)orientation2D(a, b, c);
	RELATIVE_POS ab_d = (RELATIVE_POS)orientation2D(a, b, c);
	RELATIVE_POS cd_a = (RELATIVE_POS)orientation2D(a, b, c);
	RELATIVE_POS cd_b = (RELATIVE_POS)orientation2D(a, b, c);

	if (ab_c == RELATIVE_POS::BETWEEN || ab_c == RELATIVE_POS::ORIGIN || ab_c == RELATIVE_POS::DESTINATION ||
		ab_d == RELATIVE_POS::BETWEEN || ab_d == RELATIVE_POS::ORIGIN || ab_d == RELATIVE_POS::DESTINATION ||
		cd_a == RELATIVE_POS::BETWEEN || cd_a == RELATIVE_POS::ORIGIN || cd_a == RELATIVE_POS::DESTINATION ||
		cd_b == RELATIVE_POS::BETWEEN || cd_b == RELATIVE_POS::ORIGIN || cd_b == RELATIVE_POS::DESTINATION)
	{
		return true;
	}

	//_xor() returns true if both bool inputs are different
	return _xor(ab_c == RELATIVE_POS::LEFT, ab_d == RELATIVE_POS::LEFT) && _xor(cd_a == RELATIVE_POS::LEFT, cd_b == RELATIVE_POS::LEFT);
}
