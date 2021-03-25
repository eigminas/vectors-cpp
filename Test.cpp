/********************************************************************************************************
					Test.cpp tests the functionality of Vector3D and Bin classes
*********************************************************************************************************/
#include <iostream>
#include <string>
#include "Vector3D.h"
#include "Bin.h"

using namespace std;

/********************************************************************************************************/
void printHeader(string str);
void testEmptyConstructor();
void testCompleteConstructor(float xc, float yc, float zc);
void testMagnitude(Vector3D v);
bool areSame(float a, float b);
void testequalsoperator(Vector3D v1);
void testPlusOperator(Vector3D v1, Vector3D v2);
void testMinusOperator(Vector3D v1, Vector3D v2);
void testMultiplyByScalarOperator(Vector3D v, float rhs);
void testDivideByScalarOperator(Vector3D v, float rhs);
void testScalarProductOperator(Vector3D v1, Vector3D v2);
void testVectorProductOperator(Vector3D v1, Vector3D v2);
void testUnitVector(Vector3D v);
void testOrthogonal(Vector3D v1, Vector3D v2);
/*------------------------------------------------------------------------------------------------------*/
void testBinConstructor(int n);
void testGetXOfNthVector();
void testGetYOfNthVector();
void testGetZOfNthVector();
void testAdd();
void testRemove();

void testBinCopyConstructor();
void testAssignementOperatorBin();
/********************************************************************************************************/

float EPSILON = 0.0001;

int main()
{
	// Tests for Vector3D class
	cout << "_____________________________________________________________________________________" << endl;
	cout << "                              Testing Vector3D class" << endl;
	cout << endl;
	testEmptyConstructor(); // test empty constructor
	testCompleteConstructor(10, 20.5, 30); // test regular constructor
	testMagnitude(Vector3D(4, 5.5, 8)); // test if magnitude is calculated correctly
	testequalsoperator(Vector3D(4, 5.5, 8)); // test if equals operator works correctly
	testPlusOperator(Vector3D(4, 5.5, 8), Vector3D(6, 7.5, 9)); // test if plus operator works correctly
	testMinusOperator(Vector3D(4, 5.5, 8), Vector3D(6, 7.5, 9)); // test if minus operator works correctly
	testMultiplyByScalarOperator(Vector3D(4, 5.5, 8), 5.2); // test if multiply operator multiply vector by scalar
	testDivideByScalarOperator(Vector3D(4, 5.5, 8), 5.2); // test if divide operator divides vector by scalar
	testScalarProductOperator(Vector3D(4, 5.5, 8), Vector3D(6, 7.5, 9)); // test if * operator calculates scalar product correctly
	testVectorProductOperator(Vector3D(4, 5.5, 8), Vector3D(6, 7.5, 9)); // test if / operator calculates vector product correctly
	testUnitVector(Vector3D(4, 5.5, 8)); // test if unit vector is calculated correctly
	testOrthogonal(Vector3D(4, 5.5, 8), Vector3D(6, 7.5, 9)); // test if orthogonal vector is calculated correctly

	// Tests for Bin class
	cout << endl;
	cout << "_____________________________________________________________________________________" << endl;
	cout << "                                Testing Bin class" << endl;
	cout << endl;
	testBinConstructor(2); // test if regular constructor works correctly
	testGetXOfNthVector(); // test if we can get X of n-th vector in the bin	[also checks if out of bounds exception is thrown]
	testGetYOfNthVector(); // test if we can get Z of n-th vector in the bin	[also checks if out of bounds exception is thrown]
	testGetZOfNthVector(); // test if we can get Ys of n-th vector in the bin	[also checks if out of bounds exception is thrown]
	testAdd(); // test if we can add a vector to the bin		  [also checks if extra memory is allocated when the bin is full]
	testRemove(); // test if we can remove a vector from the bin				[also checks if out of bounds exception is thrown]
	testBinCopyConstructor();
	testAssignementOperatorBin();
}


void printHeader(string str)
{
	cout << endl;
	cout << "*************************************************************************************" << endl;
	cout << "                                     "<< str <<"                                          " << endl;
	cout << "*************************************************************************************" << endl;
	cout << endl;
}

bool areSame(float a, float b)
{
	return fabs(a - b) < EPSILON;
}

void testEmptyConstructor()
{
	printHeader("TEST 1");

	cout << "TEST EMPTY CONSTUCTOR" << endl;
	cout << endl;
	cout << "Vector3D v = Vector3D();" << endl;
	cout << endl;

	Vector3D v = Vector3D(); // Create Vector3D object using empty constructor

	float x, y, z;

	x = v.getX(); // store x value
	y = v.getY(); // store y value
	z = v.getZ(); // store z value

	cout << "Expected: x = 0, y = 0, z = 0" << endl;
	cout << "Actual:   x = " << x << ", y = " << y << ", z = " << z << endl;
	cout << endl;
	// if any of x, y, z values are different then 0 - test fails
	if (!(areSame(x, 0)) || !(areSame(y, 0)) || !(areSame(z, 0)))
	{
		cout << "Failed" << endl;
	}
	else
	{
		cout << "Successful" << endl;
	}
}

void testCompleteConstructor(float xc, float yc, float zc)
{
	printHeader("TEST 2");
	cout << "TEST COMPLETE CONSTRUCTOR" << endl;
	cout << endl;
	cout << "Vector3D v = Vector3D(" << xc << ", " << yc << ", " << zc << ");" << endl;
	cout << endl;
	Vector3D v = Vector3D(xc, yc, zc);
	float x, y, z;
	
	x = v.getX(); // store x value
	y = v.getY(); // store y value
	z = v.getZ(); // store z value

	cout << "Expected: x = " << xc << ", y = " << yc << ", z = " << zc << endl;
	cout << "Actual:   x = " << x << ", y = " << y << ", z = " << z << endl;
	cout << endl;

	if (!(areSame(x, 10)) || !(areSame(y, 20.5)) || !(areSame(z, 30)))
	{
		cout << "Failed" << endl;
	}
	else
	{
		cout << "Successful" << endl;
	}
}

void testMagnitude(Vector3D v)
{
	float x, y, z;
	x = v.getX();
	y = v.getY();
	z = v.getZ();

	printHeader("TEST 3");
	cout << "TEST MAGNITUDE" << endl;
	cout << endl;
	cout << "We have v1 = " << v << endl;
	cout << endl;

	float mag = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));

	cout << "Expected:  magnitude = " << mag << endl;
	cout << "Actual:    magnitude = " << v.magnitude() << endl;
	if (areSame(mag, v.magnitude()))
	{
		cout << endl;
		cout << "Successful" << endl;
	}
	else
	{
		cout << endl;
		cout << "Failed" << endl;
	}
}

void testequalsoperator(Vector3D v1)
{	
	printHeader("TEST 4");
	cout << "TEST EQUALS (ASSIGNEMENT) OPERATOR" << endl;
	cout << endl;
	cout << "We have v1 = " << v1 << endl;
	cout << endl;
	Vector3D v2 = Vector3D();
	cout << "We have v2 = " << v2 << endl;
	cout << endl;
	cout << "v1 = v2" << endl;
	cout << endl;
	v1 = v2;
	cout << "if assignement is successful both vectors must have the same x, y, z values" << endl;
	cout << endl;
	cout << "We have v1 = " << v1 << endl;
	cout << "We have v2 = " << v2 << endl;
	cout << endl;

	if (areSame(v1.getX(), v2.getX()) || areSame(v1.getY(), v2.getY()) || areSame(v1.getZ(), v2.getZ()))
	{
		cout << "Successful" << endl;
	}
	else
	{
		cout << "Failed" << endl;
	}

	cout << endl;

	
}

void testPlusOperator(Vector3D v1, Vector3D v2)
{
	printHeader("TEST 5");
	cout << "TEST PLUS OPERATOR" << endl;
	cout << endl;
	cout << "We have v1 = " << v1 << endl;
	cout << endl;
	cout << "We have v2 = " << v2 << endl;
	cout << endl;
	cout << "Vector3D v3 = v1 + v2" << endl;
	Vector3D v3 = v1 + v2;
	cout << endl;
	cout << "Expected:  v3 = vector(" << v1.getX() + v2.getX() << ", " << v1.getY() + v2.getY() << ", " << v1.getZ() + v2.getZ() << ")" << endl;
	cout << endl;
	cout << "Actual:    v3 = vector(" << v3.getX() << ", " << v3.getY() << ", " << v3.getZ() << ")" << endl;
	cout << endl;

	if (areSame(v1.getX() + v2.getX(), v3.getX()) || areSame(v1.getY() + v2.getY(), v3.getY()) || areSame(v1.getZ() + v2.getZ(), v3.getZ()))
	{
		cout << "Successful" << endl;
	}
	else
	{
		cout << "Failed" << endl;
	}

	cout << endl;
}

void testMinusOperator(Vector3D v1, Vector3D v2)
{
	printHeader("TEST 6");
	cout << "TEST MINUS OPERATOR" << endl;
	cout << endl;
	cout << "We have v1 = " << v1 << endl;
	cout << endl;
	cout << "We have v2 = " << v2 << endl;
	cout << endl;
	cout << "Vector3D v3 = v1 - v2" << endl;
	Vector3D v3 = v1 - v2;
	cout << endl;
	cout << "Expected:  v3 = vector(" << v1.getX() - v2.getX() << ", " << v1.getY() - v2.getY() << ", " << v1.getZ() - v2.getZ() << ")" << endl;
	cout << endl;
	cout << "Actual:    v3 = vector(" << v3.getX() << ", " << v3.getY() << ", " << v3.getZ() << ")" << endl;
	cout << endl;

	if (areSame(v1.getX() - v2.getX(), v3.getX()) || areSame(v1.getY() - v2.getY(), v3.getY()) || areSame(v1.getZ() - v2.getZ(), v3.getZ()))
	{
		cout << "Successful" << endl;
	}
	else
	{
		cout << "Failed" << endl;
	}

	cout << endl;
}

void testMultiplyByScalarOperator(Vector3D v, float rhs)
{
	printHeader("TEST 7");
	cout << "TEST MULTIPLY BY SCALAR OPERATOR" << endl;
	cout << endl;
	cout << "We have v1 = " << v << endl;
	cout << endl;
	cout << "We have sc = " << rhs << endl;
	cout << endl;
	cout << "Vector3D v2 = v1 * sc" << endl;
	Vector3D v3 = v * rhs;
	cout << endl;
	cout << "Expected:  v2 = vector(" << v.getX() * rhs << ", " << v.getY() * rhs << ", " << v.getZ() * rhs << ")" << endl;
	cout << endl;
	cout << "Actual:    v2 = " << v3 << endl;
	cout << endl;

	if (areSame(v.getX() * rhs, v3.getX()) || areSame(v.getY() * rhs, v3.getY()) || areSame(v.getZ() * rhs, v3.getZ()))
	{
		cout << "Successful" << endl;
	}
	else
	{
		cout << "Failed" << endl;
	}

	cout << endl;
}

void testDivideByScalarOperator(Vector3D v, float rhs)
{
	printHeader("TEST 8");
	cout << "TEST DIVIDE BY SCALAR OPERATOR" << endl;
	cout << endl;
	cout << "We have v1 = " << v << endl;
	cout << endl;
	cout << "We have sc = " << rhs << endl;
	cout << endl;
	cout << "Vector3D v2 = v1 / sc" << endl;
	Vector3D v3 = v / rhs;
	cout << endl;
	cout << "Expected:  v2 = vector(" << v.getX() / rhs << ", " << v.getY() / rhs << ", " << v.getZ() / rhs << ")" << endl;
	cout << endl;
	cout << "Actual:    v2 = " << v3 << endl;
	cout << endl;

	if (areSame(v.getX() / rhs, v3.getX()) || areSame(v.getY() / rhs, v3.getY()) || areSame(v.getZ() / rhs, v3.getZ()))
	{
		cout << "Successful" << endl;
	}
	else
	{
		cout << "Failed" << endl;
	}

	cout << endl;
}

void testScalarProductOperator(Vector3D v1, Vector3D v2)
{
	printHeader("TEST 9");
	cout << "TEST SCALAR PRODUCT OPERATOR" << endl;
	cout << endl;
	cout << "We have v1 = " << v1 << endl;
	cout << endl;
	cout << "We have v2 = " << v2 << endl;
	cout << endl;
	cout << "float scalarProduct = v1 * v2" << endl;
	cout << endl;
	float spe = (v1.getX() * v2.getX()) + (v1.getY() * v2.getY()) + (v1.getZ() * v2.getZ());
	float spa = v1 * v2;

	cout << "Expected:  scalarProduct = " << spe << endl;
	cout << "Actual:    scalarProduct = " << spa << endl;
	cout << endl;
	if (areSame(spe, spa))
	{
		cout << "Successful" << endl;
	}
	else
	{
		cout << "Failed" << endl;
	}
}

void testVectorProductOperator(Vector3D v1, Vector3D v2)
{
	printHeader("TEST 10");
	cout << "TEST VECTOR PRODUCT OPERATOR" << endl;
	cout << endl;
	cout << "We have v1 = " << v1 << endl;
	cout << endl;
	cout << "We have v2 = " << v2 << endl;
	cout << endl;

	float xvp = (v1.getY() * v2.getZ()) - (v1.getZ() * v2.getY());
	float yvp = (v1.getZ() * v2.getX()) - (v1.getX() * v2.getZ());
	float zvp = (v1.getX() * v2.getY()) - (v1.getY() * v2.getX());

	cout << "Vector3D v3 = v1 % v2" << endl;
	cout << endl;
	Vector3D v3 = v1 % v2;

	cout << "Expected:  v3 = vector(" << xvp << ", " << yvp << ", " << zvp << " )" << endl;
	cout << "Actual:    v3 = " << v3 << endl;
	cout << endl;
	if (!areSame(xvp, v3.getX()) || !areSame(yvp, v3.getY()) || !areSame(zvp, v3.getZ()))
	{
		cout << "Failed" << endl;
	}
	else
	{
		cout << "Successful" << endl;
	}
}

void testUnitVector(Vector3D v)
{
	printHeader("TEST 11");
	cout << "TEST UNIT VECTOR" << endl;
	cout << endl;
	cout << "We have v = " << v << endl;
	cout << endl;
	float mag = v.magnitude();

	float xres = v.getX() / mag;
	float yres = v.getY() / mag;
	float zres = v.getZ() / mag;

	cout << "Vector3D unitv = v.unitVector()" << endl;
	cout << endl;
	Vector3D unitv = v.unitVector();

	cout << "Expected:  vector(" << xres << ", " << yres << ", " << zres << ")" << endl;
	cout << "Actual:    " << unitv << endl;
	cout << endl;

	if (!areSame(xres, unitv.getX()) || !areSame(yres, unitv.getY()) || !areSame(zres, unitv.getZ()))
	{
		cout << "Failed" << endl;
	}
	else
	{
		cout << "Successful" << endl;
	}
}

void testOrthogonal(Vector3D v1, Vector3D v2)
{
	printHeader("TEST 12");
	cout << "TEST ORTHOGONAL VECTOR" << endl;
	cout << endl;
	cout << "We have v1 = " << v1 << endl;
	cout << endl;
	cout << "We have v2 = " << v2 << endl;
	cout << endl;

	float xvp = (v1.getY() * v2.getZ()) - (v1.getZ() * v2.getY());
	float yvp = (v1.getZ() * v2.getX()) - (v1.getX() * v2.getZ());
	float zvp = (v1.getX() * v2.getY()) - (v1.getY() * v2.getX());

	float mag = sqrt(pow(xvp, 2) + pow(yvp, 2) + pow(zvp, 2));

	float xres = xvp / mag;
	float yres = yvp / mag;
	float zres = zvp / mag;

	cout << "Vector3D orthogonal = v1.orthogonal(&v2);" << endl;
	Vector3D orthogonal = v1.orthogonal(&v2);

	cout << "Expected:  vector( x = " << xres << ", y = " << yres << ", z = " << zres << ")" << endl;
	cout << "Actual:    " << orthogonal << endl;
	cout << endl;
	if (!areSame(xres, orthogonal.getX()) || !areSame(yres, orthogonal.getY()) || !areSame(zres, orthogonal.getZ()))
	{
		cout << "Failed" << endl;
	}
	else
	{
		cout << "Successful" << endl;
	}
}
/***********************************************************************************************************************************************/
void testBinConstructor(int n)
{
	printHeader("TEST 1");
	cout << "TEST CONSTRUCTOR" << endl;
	cout << endl;
	cout << "Bin bin = Bin(" << n << ")" << endl;
	Bin bin = Bin(n);
	cout << endl;
	cout << "Expected:  size = " << n << ", length = " << 0 << endl;
	cout << "Actual:    size = " << bin.getSize() << ", length = " << bin.getLength() << endl;
	cout << endl;

	if (bin.getSize() != n || bin.getLength() != 0)
	{
		cout << "Failed" << endl;
	}
	else
	{
		cout << "Successful" << endl;
	}
	cout << endl;
	cout << "Bin bin1 = Bin(" << 0 << ")" << endl;
	cout << endl;
	cout << "Expected:  exception" << endl;
	try
	{
		Bin bin1 = Bin(0);
		cout << "Actual:    not exception" << endl;
		cout << endl;
		cout << "Failed" << endl;
	}
	catch (invalid_argument e)
	{
		cout << "Actual:    exception" << endl;
		cout << endl;
		cout << "Successful" << endl;
	}

	cout << endl;
	cout << "Bin bin1 = Bin(" << -1 << ")" << endl;
	cout << endl;
	cout << "Expected:  exception" << endl;
	try
	{
		Bin bin2 = Bin(-1);
		cout << "Actual:    not exception" << endl;
		cout << endl;
		cout << "Failed" << endl;
	}
	catch (invalid_argument e)
	{
		cout << "Actual:    exception" << endl;
		cout << endl;
		cout << "Successful" << endl;
	}
}

void testGetXOfNthVector()
{
	printHeader("TEST 2");
	cout << "TEST GET X OF N-TH VECTOR" << endl;
	cout << endl;
	cout << "Bin bin = Bin(5)" << endl;
	Bin bin = Bin(5);
	cout << "bin.add(5, 4, 3)" << endl;
	bin.add(5, 4, 3);
	cout << endl;
	cout << "Expected:  bin.getX(0) = 5" << endl;
	cout << "Actual:    bin.getX(0) = " << bin.getX(0) << endl;
	cout << endl;
	if (areSame(bin.getX(0), 5))
	{
		cout << "Successful" << endl;
	}
	else
	{
		cout << "Failed" << endl;
	}

	cout << endl;
	cout << "Expected:  bin.getX(-1) = exception" << endl;
	try
	{
		bin.getX(-1);
		cout << "Actual:    bin.getX(-1) = not exception" << endl;
		cout << "Failed" << endl;
	}
	catch (invalid_argument e)
	{
		cout << "Actual:    bin.getX(-1) = exception" << endl;
		cout << endl;
		cout << "Successful" << endl;
	}

	cout << endl;
	cout << "Expected:  bin.getX(10) = exception" << endl;
	try
	{
		bin.getX(10);
		cout << "Actual:    bin.getX(10) = not exception" << endl;
		cout << "Failed" << endl;
	}
	catch (invalid_argument e)
	{
		cout << "Actual:    bin.getX(10) = exception" << endl;
		cout << endl;
		cout << "Successful" << endl;
	}
}

void testGetYOfNthVector()
{
	printHeader("TEST 3");
	cout << "TEST GET Y OF N-TH VECTOR" << endl;
	cout << endl;
	cout << "Bin bin = Bin(5)" << endl;
	Bin bin = Bin(5);
	cout << "bin.add(5, 4, 3)" << endl;
	bin.add(5, 4, 3);
	cout << endl;
	cout << "Expected:  bin.getY(0) = 4" << endl;
	cout << "Actual:    bin.getY(0) = " << bin.getY(0) << endl;
	cout << endl;
	if (areSame(bin.getY(0), 4))
	{
		cout << "Successful" << endl;
	}
	else
	{
		cout << "Failed" << endl;
	}

	cout << endl;
	cout << "Expected:  bin.getY(-1) = exception" << endl;
	try
	{
		bin.getY(-1);
		cout << "Actual:    bin.getY(-1) = not exception" << endl;
		cout << "Failed" << endl;
	}
	catch (invalid_argument e)
	{
		cout << "Actual:    bin.getY(-1) = exception" << endl;
		cout << endl;
		cout << "Successful" << endl;
	}

	cout << endl;
	cout << "Expected:  bin.getY(10) = exception" << endl;
	try
	{
		bin.getY(10);
		cout << "Actual:    bin.getY(10) = not exception" << endl;
		cout << "Failed" << endl;
	}
	catch (invalid_argument e)
	{
		cout << "Actual:    bin.getY(10) = exception" << endl;
		cout << endl;
		cout << "Successful" << endl;
	}
}

void testGetZOfNthVector()
{
	printHeader("TEST 4");
	cout << "TEST GET Z OF N-TH VECTOR" << endl;
	cout << endl;
	cout << "Bin bin = Bin(5)" << endl;
	Bin bin = Bin(5);
	cout << "bin.add(5, 4, 3)" << endl;
	bin.add(5, 4, 3);
	cout << endl;
	cout << "Expected:  bin.getZ(0) = 3" << endl;
	cout << "Actual:    bin.getZ(0) = " << bin.getZ(0) << endl;
	cout << endl;
	if (areSame(bin.getZ(0), 3))
	{
		cout << "Successful" << endl;
	}
	else
	{
		cout << "Failed" << endl;
	}

	cout << endl;
	cout << "Expected:  bin.getZ(-1) = exception" << endl;
	try
	{
		bin.getZ(-1);
		cout << "Actual:    bin.getZ(-1) = not exception" << endl;
		cout << "Failed" << endl;
	}
	catch (invalid_argument e)
	{
		cout << "Actual:    bin.getZ(-1) = exception" << endl;
		cout << endl;
		cout << "Successful" << endl;
	}

	cout << endl;
	cout << "Expected:  bin.getZ(10) = exception" << endl;
	try
	{
		bin.getZ(10);
		cout << "Actual:    bin.getZ(10) = not exception" << endl;
		cout << "Failed" << endl;
	}
	catch (invalid_argument e)
	{
		cout << "Actual:    bin.getZ(10) = exception" << endl;
		cout << endl;
		cout << "Successful" << endl;
	}
}

void testAdd()
{
	printHeader("TEST 5");
	cout << "TEST ADD VECTOR TO BIN" << endl;
	cout << endl;
	cout << "Bin bin = Bin(3)" << endl;
	Bin bin = Bin(3);
	cout << endl;
	cout << "Let us add 3 vectors:" << endl;
	cout << endl;
	cout << "bin.add(1, 1, 1)" << endl;
	cout << "bin.add(2, 2, 2)" << endl;
	cout << "bin.add(3, 3, 3)" << endl;
	cout << endl;
	bin.add(1, 1, 1);
	bin.add(2, 2, 2);
	bin.add(3, 3, 3);
	cout << "cout << bin << endl" << endl;
	cout << endl;
	cout << bin << endl;
	cout << endl;
	cout << "We have used full capacity of our bin." << endl;
	cout << "Let us add 4th vector to make sure add function allocates more memory" << endl;
	cout << endl;
	cout << "bin.add(4, 4, 4)" << endl;
	cout << endl;
	bin.add(4, 4, 4);
	cout << "cout << bin << endl" << endl;
	cout << endl;
	cout << bin << endl;
}

void testRemove()
{
	printHeader("TEST 6");
	cout << "TEST REMOVE VECTOR FROM BIN" << endl;
	cout << endl;
	cout << "Bin bin = Bin(3)" << endl;
	Bin bin = Bin(3);
	cout << endl;

	cout << "Let us add 3 vectors:" << endl;
	cout << endl;
	cout << "bin.add(1, 1, 1)" << endl;
	cout << "bin.add(2, 2, 2)" << endl;
	cout << "bin.add(3, 3, 3)" << endl;
	cout << endl;
	bin.add(1, 1, 1);
	bin.add(2, 2, 2);
	bin.add(3, 3, 3);
	cout << "cout << bin << endl" << endl;
	cout << endl;
	cout << bin << endl;
	cout << endl;
	cout << "bin.remove(1)" << endl;
	cout << endl;
	bin.remove(1);
	cout << "cout << bin << endl" << endl;
	cout << endl;
	cout << bin << endl;
	cout << endl;
	cout << "Test exception" << endl;
	cout << endl;
	cout << "bin.remove(2)" << endl;
	cout << endl;
	cout << "Expected:  exception" << endl;
	try
	{
		bin.remove(2);
		cout << "Actual: removed" << endl;
		cout << endl;
		cout << "Failed" << endl;
	}
	catch (invalid_argument e)
	{
		cout << "Actual:    exception" << endl;
		cout << endl;
		cout << "Successful" << endl;
	}
}

void testBinCopyConstructor()
{
	printHeader("TEST 7");
	cout << "TEST COPY CONSTRUCTOR" << endl;
	cout << endl;
	cout << "Bin bin1 = Bin(2)" << endl;
	Bin bin1 = Bin(2);
	cout << endl;
	cout << "Let us add 2 vectors to bin1:" << endl;
	cout << endl;
	cout << "bin1.add(1, 1, 1)" << endl;
	cout << "bin1.add(2, 2, 2)" << endl;
	bin1.add(1, 1, 1);
	bin1.add(2, 2, 2);
	cout << endl;
	cout << "cout << bin1 << endl" << endl;
	cout << endl;
	cout << bin1 << endl;
	cout << endl;
	cout << "Bin bin2 = bin1" << endl;
	Bin bin2 = bin1;
	cout << endl;
	cout << "cout << bin2 << endl" << endl;
	cout << endl;
	cout << bin2 << endl;
	cout << endl;
}

void testAssignementOperatorBin()
{
	printHeader("TEST 8");
	cout << "TEST ASSIGNEMENT OPERATOR" << endl;
	cout << endl;
	cout << "Bin bin1 = Bin(2)" << endl;
	Bin bin1 = Bin(2);
	cout << endl;
	cout << "Let us add 2 vectors to bin1:" << endl;
	cout << endl;
	cout << "bin1.add(1, 1, 1)" << endl;
	cout << "bin1.add(2, 2, 2)" << endl;
	bin1.add(1, 1, 1);
	bin1.add(2, 2, 2);
	cout << endl;
	cout << "cout << bin1 << endl" << endl;
	cout << endl;
	cout << bin1 << endl;
	cout << endl;
	cout << "Bin bin2 = Bin(3)" << endl;
	Bin bin2 = Bin(3);
	cout << endl;
	cout << "Let us add 3 vectors to bin2:" << endl;
	cout << endl;
	cout << "bin2.add(10, 10, 10)" << endl;
	cout << "bin2.add(20, 20, 20)" << endl;
	cout << "bin2.add(30, 30, 30)" << endl;
	bin2.add(10, 10, 10);
	bin2.add(20, 20, 20);
	bin2.add(30, 30, 30);
	cout << endl;
	cout << "cout << bin2 << endl" << endl;
	cout << endl;
	cout << bin2 << endl;
	cout << endl;
	cout << "bin1 = bin2" << endl;
	bin1 = bin2;
	cout << endl;
	cout << "cout << bin1 << endl" << endl;
	cout << endl;
	cout << bin1 << endl;
	cout << endl;
}