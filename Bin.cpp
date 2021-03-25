#include "Bin.h"
#include "Vector3D.h"
#include <stdexcept>
#include <iostream>

Bin::Bin(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Bin capacity cannot be" + n); // throw exception
	}
	else
	{
		length = 0; // initially bin is empty
		size = n; // size is equal to n
		ptr_arr = new Vector3D[size]; // allocate required amount of contiguous memory
	}
}

Bin::Bin(const Bin& rhs)
{
	length = rhs.length; // copy length
	size = rhs.size; // copy size
	ptr_arr = new Vector3D[rhs.size]; // allocate required amount of contiguous memory
	copyValues(rhs.ptr_arr, ptr_arr); // copy values
}

Bin::~Bin()
{
	delete[] ptr_arr; // release dynamically allocated memory
}

float Bin::getX(int a) const
{
	// check if a is within bounds
	if (a >= 0 && a < length)
	{
		return ptr_arr[a].getX(); // return x of a-th vector
	}
	else
	{
		throw std::invalid_argument("Out of bonds: " + a); // throw exception
	}
	
}

float Bin::getY(int a) const
{
	// check if a is within bounds
	if (a >= 0 && a < length)
	{
		return ptr_arr[a].getY(); // return y of a-th vector
	}
	else
	{
		throw std::invalid_argument("Out of bonds: " + a); // throw exception
	}
}

float Bin::getZ(int a) const
{
	// check if a is within bounds
	if (a >= 0 && a < length)
	{
		return ptr_arr[a].getZ(); // return z of a-th vector
	}
	else
	{
		throw std::invalid_argument("Out of bonds: " + a); // throw exception
	}
}

int Bin::getSize() const
{
	return size; // return size
}

int Bin::getLength() const
{
	return length; // return length
}

void Bin::add(float x, float y, float z)
{
	// check if there is enough space for a new vector
	if (length < size)
	{
		ptr_arr[length] = Vector3D(x, y, z); // add new vector
		length++; // increment length
	}
	// if there is not enough space for a new vector, we will allocate more memory and then add new vector
	else
	{
		allocateMoreMemory(); // allocate more memory
		ptr_arr[length] = Vector3D(x, y, z); // add new vector
		length++; // increment length
	}
}

void Bin::remove(int b)
{
	// check if b is within bounds
	if (b >= 0 && b < length)
	{
		// delete a vector
		for (int i = b; i < length-1; i++)
		{
			ptr_arr[i] = ptr_arr[i + 1];
		}
		length--; // decrement length
	}
	else
	{
		throw std::invalid_argument("Out of bonds: " + b); // throw exception
	}
}

Bin& Bin::operator=(const Bin& rhs)
{
	
	length = rhs.length; // copy length
	size = rhs.size; // copy size
	delete[] ptr_arr; // delete memory currently pointer by ptr_arr
	ptr_arr = new Vector3D[rhs.size]; // allocate required amount of contiguous memory
	copyValues(rhs.ptr_arr, ptr_arr); // copy values

	return *this;
}

void Bin::allocateMoreMemory()
{
	// create temporary pointer to Vector3D array with bigger size
	int newSize = size * 2;
	Vector3D* temp_ptr_arr = new Vector3D[newSize];
	// copy values from old pointer to Vector3D array to the new one
	copyValues(ptr_arr, temp_ptr_arr);
	// Release memory that is reserved by the old array
	delete[] ptr_arr;
	// ptr_arr now should point to the newly allocated memory
	ptr_arr = temp_ptr_arr;
	size = newSize; // update size
}

void Bin::copyValues(Vector3D* copy_from, Vector3D* copy_to)
{
	// copy values one by one
	for (int i = 0; i < size; i++)
	{
		copy_to[i] = copy_from[i];
	}
}

std::ostream& operator<<(std::ostream& os, const Bin& b)
{
	os << "************************************************" << std::endl;
	os << "size   = " << b.getSize() << std::endl;
	os << "length = " << b.getLength() << std::endl;
	os << std::endl;
	os << "vectors:" << std::endl;
	os << std::endl;
	for (int i = 0; i < b.getLength(); i++)
	{
		os << "[" << i << "] --> vector(" << b.getX(i) << ", " << b.getY(i) << ", " << b.getZ(i) << ")" << std::endl;
	}
	os << "************************************************" << std::endl;
	return os;
}