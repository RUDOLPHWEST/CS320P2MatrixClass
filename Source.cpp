//template<typename T> //matrix multiply
//const matrix<T> matrix<T>::operator* (const matrix<T> & rhs)const{
//
//	assert(this->numcols() == rhs.numrows());
//	matrix<T> result(rhs.numrows(), this->numcols());
//
//	int i = 0;
//	int j = 0;
//	int m = 0;
//	int n = 0; //int x = 0; int y = 0;
//	int sum = 0;
//	for (i = 0; < this->numrows(); i++){
//		for (n = 0; < result.numcols(); n++){
//			for (j = 0; < this->numcols(); j++)
//			{
//				cout << "we did it boys" << endl;
//				sum += this->arr[i][j] * rhs.arr[m][n];
//				//j++; //shift this to the next value in the row
//				//m++; //shift rhs to the first value of next row
//			}
//
//			result[i][n] = sum;
//			sum = 0;
//			n++;
//		}
//		x++;
//	}
//	return result;
//}