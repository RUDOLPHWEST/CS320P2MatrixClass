#ifndef MATRIX_CPP
#define MATRIX_CPP
#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdlib.h> 
using namespace std;

template<typename T>
matrix<T>  matrix<T>::t() {

	matrix<T> result( this->numcols(), this->numrows() );
	for (int i = 0; i < this->numrows(); i++)// i = rows in this, and i = cols in that
	for (int j = 0; j < this->numcols(); j++)// j = cols in this, and j = rows in that
		result[j][i] = this->arr[i][j];
	return result;
}

template <typename T>
const matrix<T> & matrix<T>::operator=(const matrix<T> & rhs)
{
	assert(this->numrows() == rhs.numrows() && this->numcols() == rhs.numcols());
	if (this != &rhs)
		this->arr = rhs.arr;
	return *this;
}

template<typename T>
const matrix<T> matrix<T>::operator+=(const matrix<T> & rhs){
	assert(this->numrows() == rhs.numrows() && this->numcols() == rhs.numcols());
	for (int i = 0; i < numrows(); i++)
	for (int j = 0; j < numcols(); j++)
		this->arr[i][j] += rhs.arr[i][j];
	return *this;
}

template<typename T>
const matrix<T> matrix<T>::operator+ (const matrix<T> & rhs) const{

	assert(this->numrows() == rhs.numrows() && this->numcols() == rhs.numcols());

	matrix<T> result(*this);
	result += rhs;
	return result;
}

template<typename T> //scalar
const matrix<T> matrix<T>::operator*= (const  T &c){

	for (int i = 0; i < numrows(); i++)
	for (int j = 0; j < numcols(); j++)
		this->arr[i][j] *= c;
	return *this;
}


template<typename T> //scalar
const matrix<T>  matrix<T>::operator* (const  T &c) const{

	matrix<T> result(*this);
	result *= c;
	return result;
}

template<typename T>
const matrix<T> matrix<T>::operator* (const matrix<T> & rhs)const {

	assert(this->numcols() == rhs.numrows());
	matrix<T> result(numrows(), rhs.numcols());
	T sum = 0;

	for (int x = 0; x < numrows(); x++) {
		for (int i = 0; i < rhs.numcols(); i++) {
			for (int j = 0; j < numcols(); j++) {
				sum += this->arr[x][j] * rhs.arr[j][i];
			}
			result[x][i] = sum;
			sum = 0;
		}
	}
	return result;
}

template<typename T>
vector<T> matrix<T>::row(int k){ // assume k will be base zero

	assert(this->numrows() > k);
	vector<T> result;
	for (int i = 0; i < this->numcols(); i++)
		result.push_back(this->arr[k][i]);
	return result;
}

template<typename T>
vector<T> matrix<T>::col(int k){
	assert(this->numcols() > k);
	vector<T> result;
	for (int i = 0; i < this->numcols(); i++)
		result.push_back(this->arr[i][k]);
	return result;
}

template<typename T>
matrix<T> matrix<T>::deleteRow(int k){ // assume k will be base zero

	matrix<T> result(this->numrows() - 1, this->numcols());
	for (int i = 0; i < result.numrows(); i++)
	{
			if (i < k)
			{
				result[i] = this->arr[i];asdfasdfasdfasdfasdf
			}
			else if (i >= k)
			{
				result[i] = this->arr[i + 1];
			}
	}

	return result;
}

template<typename T>
matrix<T> matrix<T>::deleteCol(int k){

	matrix<T> result(this->numrows(), this->numcols() - 1);
	for (int i = 0; i < this->numrows(); i++)
	{
		for (int j = 0; j < this->numcols() - 1; j++)
		{
			if (j != k)
			{
				result[i][j] = this->arr[i][j];
			}
		}
	}
	return result;
}
template <typename T>
T matrix<T>::det_aux() {
	T sum;
	if (this->numrows() == 0)
		return 0;
	else if (this->numrows() == 1)
		return this->arr[0][0];
	else if (this->numrows() == 2)
		return this->arr[0][0] * this->arr[1][1]
		- this->arr[1][0] * this->arr[0][1];
	else{
		sum = T();
		for (int k = 0; k < this->numcols(); k++){
			sum += ((k % 2) ? -1 : 1)*(this->arr[0][k] *
				(this->deleteRow(0).deleteCol(k)).det_aux());
		}
	}
	return sum;
}

template <typename T>
T matrix<T>::det()
{
	assert(this->numrows() == this->numcols());
	return this->det_aux();
}

template<typename T>
void matrix<T>::read(istream & in = cin){

	int totalElements = numrows()*numcols();
	for (int i = 0; i < numrows(); i++)
	for (int j = 0; j < numcols(); j++)
		this->arr[i][j] = T();

	if (this->numrows() == 0) return;

	int numberOfElements = 0;
	while (numberOfElements < totalElements && in >> ws && !in.eof()){
		T element;
		numberOfElements++;
		in >> element;
		this->arr[(numberOfElements - 1) / numcols()][(numberOfElements - 1) % numcols()] = element;
	}
}

template<typename T>
void matrix<T>::print(ostream & out = cout) const{
	for (int i = 0; i < numrows(); i++) {
		cout << this->arr[i][0];
		for (int j = 1; j < numcols(); j++)
			cout << " " << this->arr[i][j];
		cout << endl;
	}
}

template<typename T>
istream& operator>>(istream &  in, matrix<T> & rhs){
	rhs.read(in);
	return in;
}

template<typename T>
ostream& operator<<(ostream & out, const  matrix<T> & rhs){
	rhs.print(out);
	return out;
}

template<typename T>
T dot(const vector<T> & lvec, const vector<T> & rvec){
	// You write code
	return T(); //dummy return
}
template<typename T>
matrix<T> eye(int n) {
	// You write code
	return matrix<T>(); //dummy return
}

template<typename T>
matrix<T> zeroes(int rows, int cols){
	matrix<T> zeroesMat(rows, cols);
	for (int i = 0; i < rows; i++)
	for (int j = 0; j < cols; j++)
		zeroesMat[i][j] = (T)0;
	return zeroesMat;
}

template<typename T>
matrix<T> ones(int rows, int cols){
	matrix<T> onesMat(rows, cols);
	for (int i = 0; i < rows; i++)
	for (int j = 0; j < cols; j++)
		onesMat[i][j] = (T)1;
	return onesMat;
}

#endif