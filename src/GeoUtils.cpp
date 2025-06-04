#include "GeoUtils.h"

//template <typename T>
int geometry::areaofTriangle2D(const Vector<int, DIM2>& a, const   Vector<int, DIM2>& b, const   Vector<int, DIM2>& c)
{
	auto AB = b - a;
	auto AC = c - a;
	auto areaofParallelogram = crossProduct2D(AB, AC);
	//auto areaofParallelogram = AB[X] * AC[Y] - AC[X] * AB[Y];;
	return areaofParallelogram /2;
}

//template <typename T>
double geometry::areaofTriangle3D(const Vector<int, DIM3>& a, const   Vector<int, DIM3>& b, const   Vector<int, DIM3>& c)
{
	auto AB = b - a;
	auto AC = c - a;
	auto areaofParallelogram = crossProduct3D(AB, AC).magnitude();
	auto areaofTri = areaofParallelogram / 2.0;
	return areaofTri;
}

//template <typename T>
int geometry::orientation2D(const Vector<int, DIM2>& a, const   Vector<int, DIM2>& b, const   Vector<int, DIM2>& c)
{
	auto area = areaofTriangle2D(a, b, c);

	if (area > 0 && area < TOLERANCE)
		area = 0;

	if (area < 0 && area > TOLERANCE)
		area = 0;

	if (area < 0)
		return (int)RELATIVE_POS::RIGHT;

	if (area > 0)
		return (int)RELATIVE_POS::LEFT;

	auto ab = b - a;
	auto ac = c - a;

	if (ab[X] * ac[X] < 0 || ab[Y] * ac[Y] < 0)
		return (int)RELATIVE_POS::BEHIND;

	if (ab.magnitude() < ac.magnitude())
		return (int)RELATIVE_POS::BEYOND;

	if (a == c)
		return (int)RELATIVE_POS::ORIGIN;

	if (b == c)
		return (int)RELATIVE_POS::DESTINATION;

	return (int)RELATIVE_POS::BETWEEN;
}

//template <typename T>
int geometry::orientation3D(const Vector<int, DIM3>& a, const   Vector<int, DIM3>& b, const   Vector<int, DIM3>& c)
{
	auto area = areaofTriangle3D(a, b, c);

	if (area > 0 && area < TOLERANCE)
		area = 0;

	if (area < 0 && area > TOLERANCE)
		area = 0;

	if (area < 0)
		return (int)RELATIVE_POS::RIGHT;

	if (area > 0)
		return (int)RELATIVE_POS::LEFT;

	auto ab = b - a;
	auto ac = c - a;

	if (ab[X] * ac[X] < 0 || ab[Y] * ac[Y] < 0 || ab[Z] * ac[Z] < 0)
		return (int)RELATIVE_POS::BEHIND;

	if (ab.magnitude() < ac.magnitude())
		return (int)RELATIVE_POS::BEYOND;

	if (a == c)
		return (int)RELATIVE_POS::ORIGIN;

	if (b == c)
		return (int)RELATIVE_POS::DESTINATION;

	return (int)RELATIVE_POS::BETWEEN;
	return 0;
}
/*
bool geometry::isLeft(const Point2D& a, const Point2D& b, const Point2D& c)
{
	return orientation2D(a, b, c) == (int)RELATIVE_POS::LEFT;
}

bool geometry::isLeft(const Point3D& a, const Point3D& b, const Point3D& c)
{
	return orientation3D(a, b, c) == (int)RELATIVE_POS::LEFT;
}

bool geometry::isRight(const Point2D& a, const Point2D& b, const Point2D& c)
{
	return orientation2D(a, b, c) == (int)RELATIVE_POS::RIGHT;
}

bool geometry::isRight(const Point3D& a, const Point3D& b, const Point3D& c)
{
	return orientation3D(a, b, c) == (int)RELATIVE_POS::RIGHT;
}

bool geometry::isLeftorBeyond(const Point2D& a, const Point2D& b, const Point2D& c)
{
	int result = orientation2D(a, b, c);
	return (result == (int)RELATIVE_POS::LEFT || result == (int)RELATIVE_POS::BEYOND);
}

bool geometry::isLeftorBeyond(const Point3D& a, const Point3D& b, const Point3D& c)
{
	int result = orientation3D(a, b, c);

	return (result == (int)RELATIVE_POS::LEFT || result == (int)RELATIVE_POS::BEYOND);
}
*/
