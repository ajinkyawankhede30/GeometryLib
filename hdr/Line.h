#pragma once
#include "VectorClass.h"

namespace geometry
{
	template <typename T, size_t dim = DIM3>
	class Line
	{
	public:
		Line() {}

		Line(const Vector<T, dim>& p1, const Vector<T, dim>& p2)
		{
			point = p1;
			dir = p2 - p1;
		}

		Vector<T, dim> getPoint();
		Vector<T, dim> getDir();

	private:
		Vector<T, dim> point;
		Vector<T, dim> dir;
	};

	template<typename T, size_t dim>
	inline Vector<T, dim> Line<T, dim>::getPoint()
	{
		return point;
	}

	template<typename T, size_t dim>
	inline Vector<T, dim> Line<T, dim>::getDir()
	{
		return dir;
	}

}