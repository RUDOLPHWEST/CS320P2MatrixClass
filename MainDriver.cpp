#include <iostream>
#include <vector>
#include "Matrix.h"
using namespace std;

int main()
{
	matrix<int> m1(3, 3);
	matrix<int> tempM1(3, 3);
	matrix<int> m2(3, 2);
	matrix<int> m3{ { 1, 2, 3 }, { 2, 3, 4 }, { 2, 3, 4 } };
	matrix<int> m3_1{ { 1, 2, 3 }, { 2, 3, 4 }, { 2, 3, 4 } };
	matrix<int> m3_2{ { 1, 2 }, { 2, 3 }, { 2, 3 } };
	matrix<int> m4(3, 5);
	matrix<int> m5(3, 3);
	matrix<int> m6{ { 3, 0, -1, 2 }, { 4, 1, 3, -2 }, { 0, 2, -1, 3 }, { 1, 0, 1, 4 } };
	matrix<int> m6_1{ { 3, 0, -1, 2 }, { 4, 1, 3, -2 }, { 0, 2, -1, 3 }, { 1, 0, 1, 4 } };
	matrix<int> m7(4, 4);
	vector<int> v1{ 1, 2, 3 };
	vector<int> v2{ 2, 3, 4 };

	int multiplyVal = 0;

	cout << "m3 =\n";
	cout << m3 << endl;

	/*cout << "Enter 3 x 3 matrix row by row:\n";
	cin >> m1;
	tempM1 = m1;

	cout << "Enter 3 x 2 matrix row by row:\n";
	cin >> m2;*/

	//cout << "m1:\n";
	//cout << m1;

	//cout << "m2:\n";
	//cout << m2;

	//cout << "m1 + m3\n";
	//cout << m1 + m3 << endl;
	//cout << "m1 = " << endl << m1 << endl;
	//cout << "m2 = " << endl << m2 << endl;

	//cout << "m5 += m1  += m1\n";
	//cout << (m5 += (m1 += m1)) << endl;
	//cout << "m1 = " << endl << m1 << endl;
	//cout << "m5 = " << endl << m5 << endl;

	//matrix multiply
	//3x3 3x3
	//cout << "------------------------------------------------------------------" << endl;
	//cout << "m1 * m3_1\n";
	//cout << m3 * m3_1 << endl;
	//cout << "m3 = " << endl << m3 << endl;
	//cout << "m3_1 = " << endl << m3_1 << endl;
	////3x3  3x2
	//cout << "m1 * m3_2\n";
	//cout << m3 * m3_2 << endl;
	//cout << "m3 = " << endl << m3 << endl;
	//cout << "m3_2 = " << endl << m3_2 << endl;
	//cout << "------------------------------------------------------------------" << endl;

	////scalar -- tested
	//cout << "Enter an int to multiply against m1: \n";
	//cin >> multiplyVal;
	//cout << "m1 * " << multiplyVal << endl;
	//cout << (m1 * multiplyVal) << endl;

	////reset m1
	//m1 = tempM1;

	////scalar *
	//cout << "m1*3\n";
	//cout << m1 * 3 << endl;

	////reset m1
	//m1 = tempM1;

	////scalar *=
	//cout << "m1 *= " << multiplyVal << endl;
	//cout << m1 * multiplyVal << endl;
	//cout << "------------------------------------------------------------------" << endl;

	/*cout << "m3.transpose\n";
	cout << m3.t() << endl;
	cout << "m3 = " << endl << m3 << endl;

	cout << "m6.transpose\n";
	cout << m6.t() << endl;
	cout << "m6 = " << endl << m6 << endl;

	cout << "------------------------------------------------------------------" << endl;*/

	//row
	//cout << "m3 row k\n";
	//cout << "k = 2" << endl;
	//int xx = 1; //base 0
	//vector<int> newRow = m3.row(xx);
	//for (int i = 0; i < m3.numcols(); i++)
	//	cout << newRow[i] << " ";
	//cout << endl;
	//cout << endl;
	//cout << "m3_2 row k\n";
	//cout << "k = 3" << endl;
	//int yy = 2; //base 0
	//vector<int> newRow1 = m3_2.row(yy);
	//for (int j = 0; j < m3_2.numcols(); j++)
	//	cout << newRow1[j] << " ";
	//cout << endl;
	//cout << "------------------------------------------------------------------" << endl;

	//col
	//cout << "m3 col k\n";
	//cout << "k = 2" << endl;
	//int zz = 2; //base 0
	//vector<int> newCol = m3.col(zz);
	//for (int i = 0; i < m3.numcols(); i++)
	//	cout << newCol[i] << " ";
	//cout << endl;
	//cout << endl;
	//cout << "m3_2 col k\n";
	//cout << "k = 1" << endl;
	//int zzz = 1; //base 0
	//vector<int> newCol1 = m3_2.col(zzz);
	//for (int j = 0; j < m3_2.numcols(); j++)
	//	cout << newCol1[j] << " ";
	//cout << endl;
	//cout << "------------------------------------------------------------------" << endl;

	//cout << "v1 = " << v1[0] << " " << v1[1] << " " << v1[2] << endl;
	//cout << "v2 = " << v2[0] << " " << v2[1] << " " << v2[2] << endl;
	//cout << "v1 dot v2 =  " << dot(v1, v2) << endl;

	//deleterow
	cout << "m1:\n";
	cout << m1;
	cout << "Testing the creation of new array from m1 by removing row " << m1.numrows() - 1 << " of m1 " << endl;
	cout << m1.deleteRow(m1.numrows() - 1) << endl;
	cout << "m3:\n";
	cout << m3;
	cout << "Testing the creation of new array from m3 by removing row " << m3.numrows() - 2 << " of m3 " << endl;
	cout << m3.deleteRow(m3.numrows() - 2) << endl;

	//deletecol
	cout << "m1: " << endl;
	cout << m1;
	cout << "Testing the creation of new array from m1 by removing col " << m1.numcols() - 1 << " of m1 " << endl;
	cout << m1.deleteCol(m1.numcols() - 1) << endl;
	cout << "m3: " << endl;
	cout << m3;
	cout << m3;
	cout << "Testing the creation of new array from m3 by removing col " << m3.numcols() - 2 << " of m3 " << endl;
	cout << m3.deleteCol(m3.numcols() - 2) << endl;
	//cout << "m6:\n";
	//cout << m6 << endl;
	//cout << "Determinant of m6 = " << m6.det() << endl;

	////you need to write eye()	cout << "m7 = I(4):" << endl << (m7 = eye<int>(4)) << endl;

	//cout << "zeroes(4,4):" << endl << zeroes<int>(4, 4) << endl;

	//cout << "ones(4,4):" << endl << ones<int>(4, 4) << endl;

	//YOU NEED WRITE MORE TESTS!!!!!!!!!!

	return 0;

}
