#include "GeoUtils.h"

using namespace geometry;

int main()
{
	Vector<int, DIM2> a(3, 13);
	Vector<int, DIM2> b(10, 3);
	Vector<int, DIM2> c(5, 5);


	int result = geometry::orientation2D<int>(a, b, c);
	if ((int)RELATIVE_POS::LEFT == result)
		std::cout << (result ? "true" : "false") << "\n";

	//bool isleft = geometry::isLeft(a, b, c);
	//std::cout << (isleft ? "true" : "false") << "\n";
	
	return 0;
}