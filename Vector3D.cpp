#include "Vector3D.h"
#include <cmath>
#include <iostream>

// empty constructor sets x, y, z to 0
Vector3D::Vector3D() {
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

// regular construcotr sets x, y, z to user's specified values
Vector3D::Vector3D(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vector3D::getX() const
{
	return x; // return x of the vector
}

float Vector3D::getY() const
{
	return y; // return y of the vector
}

float Vector3D::getZ() const
{
	return z; // return z of the vector
}

float Vector3D::magnitude() const
{
	// We use var*var instead of pow(var, 2) for performance reasons.
	// More about it: https://baptiste-wicht.com/posts/2017/09/cpp11-performance-tip-when-to-use-std-pow.html

	// Also for square root, we can use The Babylonian square-root algorithm / Heron's Method to increase the performance.
	// However, for this project it was not specified what exact precision we are looking for when computing square roots, therefore
	// I will stick with sqrt option from Math library. But my suggestion is to consider using above mentioned algorithms for better performance.

	// https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Babylonian_method

	return sqrt((x*x) + (y*y) + (z*z)); // return magnitude
}

Vector3D& Vector3D::operator=(const Vector3D& rhs)
{
	if (this == &rhs) return  (*this);
	x = rhs.x; // copy x
	y = rhs.y; // copy y
	z = rhs.z; // copy z

	return *this;
}

Vector3D Vector3D::operator+(const Vector3D& rhs)
{
	return Vector3D(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vector3D Vector3D::operator-(const Vector3D& rhs)
{
	return Vector3D(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vector3D Vector3D::operator*(float rhs)
{	
	return Vector3D(x * rhs, y * rhs, z * rhs);
}

Vector3D Vector3D::operator/(float rhs)
{
	// We need to check if rhs is not 0. If rhs is 0 exception will be thrown
	if (areSame(0, rhs))
	{
		throw std::invalid_argument("Division By Zero"); // throw exception
	}
	else
	{
		return Vector3D(x / rhs, y / rhs, z / rhs);
	}
}

float Vector3D::operator*(Vector3D& rhs)
{
	float result = (x * rhs.x) + (y * rhs.y) + (z * rhs.z); // compute scalar product
	return result;
}

Vector3D Vector3D::operator%(Vector3D& rhs)
{
	float cx = (y * rhs.z) - (z * rhs.y); // calculate x of resulting vector
	float cy = (z * rhs.x) - (x * rhs.z); // calculate y of resulting vector
	float cz = (x * rhs.y) - (y * rhs.x); // calculate z of resulting vector

	return Vector3D(cx, cy, cz);
}

Vector3D Vector3D::unitVector()
{
	float mag = magnitude(); // calculate magnitude

	return Vector3D(x / mag, y / mag, z / mag);
}

Vector3D Vector3D::orthogonal(Vector3D* rhs)
{
	Vector3D v = (*this) % (*rhs); // calculate vector product
	return v.unitVector(); // return unit vector of v ( this will give orthogonal )
}
bool Vector3D::areSame(float a, float b)
{
	return fabs(a - b) < 0.000001;
}
std::ostream& operator<<(std::ostream& os, const Vector3D& v)
{
	os << "Vector(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
	return os;
}