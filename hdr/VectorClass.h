#pragma once
#include <iostream>
#include <array>
#include <type_traits>

#include "Core.h"

namespace geometry
{

#define DIM3 3
#define DIM2 2

#define X	0
#define Y	1
#define Z	2


	template<typename T, size_t dimension = DIM3>
	class Vector
	{

		static_assert(std::is_arithmetic<T>::value, "Vector class can only store Integral or Floating point values\n");
		static_assert(dimension >= DIM2, "Vector dimension atleast should be 2 dimensional\n");

	public:

		Vector();

		Vector(const std::array<T, dimension>& _coords);

		Vector(T _x, T _y, T _z);

		Vector(T _x, T _y);

		//~Vector();

		//addition +
		Vector<T, dimension> operator+(const Vector<T, dimension>& other) const;

		//substraction -
		Vector<T, dimension> operator-(const Vector<T, dimension>& other) const;

		//Equality check ==
		bool operator==(const Vector<T, dimension>& other) const;

		//Not Equals !=
		bool operator!=(const Vector<T, dimension>& other);

		//indexing operator []
		T operator[](unsigned int index) const;

		//Greater than >
		bool operator>(const Vector<T, dimension>& other);

		//Less than <
		bool operator<(const Vector<T, dimension>& other);
		
		//assign
		void assign(int dim, T value);

		//dot product
		friend float dotproduct(const Vector<T, dimension>& vec1, const Vector<T, dimension>& vec2);

		//magnitude
		double magnitude() const;

		//normalize
		void normalize();

		friend float scalartripleProduct(const Vector<int, DIM3>& v1, const Vector<int, DIM3>& v2, const Vector<int, DIM3>& v3);


	private:
		std::array<T, dimension> coords;

	};

	template <typename T, size_t dimension>
	Vector<T, dimension>::Vector()
	{

	}

	template <typename T, size_t dimension>
	Vector<T, dimension>::Vector(const std::array<T, dimension>& _coords)
		:coords(_coords)
	{

	}

	template <typename T, size_t dimension>
	Vector<T, dimension>::Vector(T _x, T _y, T _z)
		:coords({ _x, _y, _z })
	{

	}

	template <typename T, size_t dimension>
	Vector<T, dimension>::Vector(T _x, T _y)
		:coords({ _x, _y })
	{

	}

	template<typename T, size_t dimension>
	Vector<T, dimension> geometry::Vector<T, dimension>::operator+(const Vector<T, dimension>& other) const
	{
		std::array<T, dimension> temp;
		for (size_t i = 0; i < dimension; i++)
		{
			temp[i] = coords[i] + other.coords[i];
		}
		return Vector<T, dimension>(temp);
	}

	template<typename T, size_t dimension>
	Vector<T, dimension> geometry::Vector<T, dimension>::operator-(const Vector<T, dimension>& other) const
	{
		std::array<T, dimension> temp;
		for (size_t i = 0; i < dimension; i++)
		{
			temp[i] = coords[i] - other.coords[i];
		}
		return Vector<T, dimension>(temp);
	}

	template<typename T, size_t dimension>
	bool geometry::Vector<T, dimension>::operator==(const Vector<T, dimension>& other) const
	{
		for (size_t i = 0; i < dimension; i++)
		{
			if (!isEqual(coords[i], other.coords[i]))
				return false;
		}
		return true;
	}

	template<typename T, size_t dimension>
	bool geometry::Vector<T, dimension>::operator!=(const Vector<T, dimension>& other)
	{
		for (size_t i = 0; i < dimension; i++)
		{
			if (!isEqual(coords[i], other.coords[i]))
				return true;
		}
		return false;
	}

	template<typename T, size_t dimension>
	T geometry::Vector<T, dimension>::operator[](unsigned int index) const
	{
		if (index >= coords.size())
		{
			throw std::out_of_range("Index out of bound\n");
		}
		return this->coords[index];
	}

	template<typename T, size_t dimension>
	bool geometry::Vector<T, dimension>::operator>(const Vector<T, dimension>& other)
	{
		for (size_t i = 0; i < dimension; i++)
		{
			if (this->coords[i] > other.coords[i])
				return true;
			else if (this->coords[i] < other.coords[i])
				return false;
		}
		return false;
	}

	template<typename T, size_t dimension>
	bool geometry::Vector<T, dimension>::operator<(const Vector<T, dimension>& other)
	{
		for (size_t i = 0; i < dimension; i++)
		{
			if (this->coords[i] < other.coords[i])
				return true;
			else if (this->coords[i] > other.coords[i])
				return false;
		}
		return false;
	}

	template<typename T, size_t dimension>
	void geometry::Vector<T, dimension>::assign(int dim, T value)
	{
		if (dim >= dimension)
		{
			throw std::out_of_range("Index out of bound\n");
		}
		this->coords[dim] = value;
	}

	template<typename T, size_t dimension>
	float dotproduct(const Vector<T, dimension>& vec1, const Vector<T, dimension>& vec2)
	{
		if (vec1.coords.size() != vec2.coords.size())
			return FLT_MIN;

		float product{};
		for (size_t i = 0; i < dimension; i++)
		{
			product += vec1.coords[i] * vec2.coords[i];
		}
		return product;
	}

	template <typename T, size_t dimension>
	double Vector<T, dimension>::magnitude() const
	{
		double temp{};
		for (size_t i = 0; i < dimension; i++)
		{
			temp += pow(coords[i], 2.0);
		}

		return sqrt(temp);
	}

	template <typename T, size_t dimension>
	void Vector<T, dimension>::normalize()
	{
		auto mag = magnitude();

		for (size_t i = 0; i < dimension; i++)
		{
			assign(i, coords[i] / mag);
		}
	}
	//typedef Vector<float, DIM2> Vector2f;
	//typedef Vector<float, DIM3> Vector3f;

	//typedef Vector<int, DIM2> Vector2i;
	//typedef Vector<int, DIM3> Vector3i;

	//typedef Vector<double, DIM2> Vector2d;
	//typedef Vector<double, DIM3> Vector3d;

	//typedef Vector<int, DIM2> Point2D;
	//typedef Vector<int, DIM3> Point3D;

	//template <typename T>
	int crossProduct2D( Vector<int, DIM2>& v1, Vector<int, DIM2>& v2);

	//template <typename T>
	Vector<int, DIM3> crossProduct3D(const Vector<int, DIM3>& v1, const Vector<int, DIM3>& v2);

	//float scalartripleProduct(const Vector<int, DIM3>& v1, const Vector<int, DIM3>& v2, const Vector<int, DIM3>& v3);

	template<typename T, size_t dimension>
	float scalartripleProduct(const Vector<int, DIM3>& v1, const Vector<int, DIM3>& v2, const Vector<int, DIM3>& v3)
	{
		Vector<int, DIM3> cross = geometry::crossProduct3D(v2, v3);
		float tripleProd = dotproduct(v1, cross);
		return tripleProd;
	}
}
