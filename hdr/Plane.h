#pragma once
#include "VectorClass.h"

namespace geometry
{
	template <typename T>
	class Plane
	{
	public:
		Plane();

		Plane(const Vector<T, DIM3>& _normal, const Vector<T, DIM3>& _d)
			:normal(_normal), d_const(_d)
		{
			
		}

		Plane(const Vector<T, DIM3>& p1, const Vector<T, DIM3>& p2, const Vector<T, DIM3>& p3);

		~Plane();

	private:
		//equation of plane: ax + by + cz = d;
		Vector<T, DIM3> normal;
		Vector<T, DIM3> d_const;
	};

	template <typename T>
	Plane<T>::Plane()
	{

	}

	template<typename T>
	inline Plane<T>::Plane(const Vector<T, DIM3>& p1, const Vector<T, DIM3>& p2, const Vector<T, DIM3>& p3)
	{
		Vector<T, DIM3> P12 = p2 - p1;
		Vector<T, DIM3> P13 = p3 - p1;

		normal = crossProduct3D(P12, P13);
		d = dotproduct(normal, p1);
	}

	template <typename T>
	Plane<T>::~Plane()
	{

	}
}