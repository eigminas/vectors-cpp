#include <ostream>
#ifndef BIN_H
#define BIN_H
#include "Vector3D.h"
class Bin {
public:

	// constructors

	Bin(int n); // regular constructor where int n specifies the capacity of bin
	Bin(const Bin& rhs); // copy constructor
	~Bin(); // destructor

	// member functions

	float getX(int a) const; // returns x of a-th vector	[exception is thrown if a is out of bonds]
	float getY(int a) const; // returns y of a-th vector	[exception is thrown if a is out of bonds]
	float getZ(int a) const; // returns z of a-th vector	[exception is thrown if a is out of bonds]

	int getSize() const; // returns size (capacity) of the bin
	int getLength() const; // returns length of the bin (number of vectors that are stored in the bin)

	void add(float x, float y, float z); // adds vector(x, y, z) to the bin. If needed allocates more memory.
	void remove(int b); // removes b-th vector from the bin and shunts all the subsequent elements to fill the gap.

	Bin& operator=(const  Bin& rhs); // operator to assign

private:

	// private functions

	void allocateMoreMemory(); // allocates more memory for ptr_arr. Updates size value.
	void copyValues(Vector3D* copy_from, Vector3D* copy_to); // copy values from one array to another.

	// private fields (variables)
	Vector3D* ptr_arr; // pointer to array of vectors
	int size; // capacity of the bin
	int length; // length of the bin (number of vectors that are stored in the bin)
};
#endif 
std::ostream& operator<<(std::ostream& os, const Bin& b);