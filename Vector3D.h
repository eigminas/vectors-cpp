#include <ostream>
#ifndef VECTOR3D_H
#define VECTOR3D_H
class Vector3D {
public:

	// constructors

	Vector3D(); // empty constructor
	Vector3D(float x, float y, float z); // regular constructor

	// member functions
	
	float getX() const; // return x of the vector
	float getY() const; // return y of the vector
	float getZ() const; // return z of the vector

	float magnitude() const; // compute the magnitude of a vector

	Vector3D& operator=(const  Vector3D& rhs); // operator to assign

	Vector3D operator+(const Vector3D& rhs); // operator to add two vectors
	Vector3D operator-(const Vector3D& rhs); // operator to subtract two vectors

	Vector3D operator*(float rhs); // operators to multiply a vector by a scalar
	Vector3D operator/(float rhs); // operators to divide a vector by a scalar

	// overload other operators to allow sensible expressions of vectors
	// to be written (Use operator* for scalar product and operator% for
	// vector product)
	float operator*(Vector3D& rhs);
	Vector3D operator%(Vector3D& rhs);

	// produce a unit vector (one of magnitude 1) pointing in the same direction as a given vector
	Vector3D unitVector();		// ???

	// return a unit vector orthogonal to two given vectors (hint : use vector product)
	Vector3D orthogonal(Vector3D* rhs);

private:
	float x, y, z;
	bool areSame(float a, float b); // needed for float comparison
};
#endif 
std::ostream& operator<<(std::ostream& os, const Vector3D& v);