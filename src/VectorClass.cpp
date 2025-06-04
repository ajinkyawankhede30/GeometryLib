#include "VectorClass.h"


using namespace geometry;


int geometry::crossProduct2D( Vector<int, DIM2>& v1, Vector<int, DIM2>& v2)
{
	return v1[X] * v2[Y] - v2[X] * v1[Y];
}


Vector<int, DIM3> geometry::crossProduct3D(const Vector<int, DIM3>& v1, const Vector<int, DIM3>& v2)
{
	int _x, _y, _z;

	_x = v1[Y] * v2[Z] - v1[Z] * v2[Y];
	_y = -(v1[X] * v2[Z] - v1[Z] * v2[X]);
	_z = v1[X] * v2[Y] - v1[Y] * v2[X];

	return Vector<int, DIM3>(_x, _y, _z);
}
