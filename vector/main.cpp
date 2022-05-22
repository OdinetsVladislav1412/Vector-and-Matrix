#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include <time.h>
using namespace std;

int main()
{	
	/*clock_t t1 = clock();
	TMatrix<double> A(1200, 1200, 1);
	TMatrix<double> B(1200, 1200, 2);
	TMatrix<double> C(1200, 1200);
	C = A * B;
	clock_t t2 = clock();
	cout << "seconds = " << (double)(t2 - t1) / CLOCKS_PER_SEC << endl;*/

	int n;
	cout << "Enter the length of the vectors: ";
	cin >> n;
	TVector<double> A(n);
	cout << "Enter the coordinates of vector A: " << endl;
	cin >> A;

	TVector<double> B(n);
	cout << "Enter the coordinates of vector B: " << endl;
	cin >> B;

	cout << "A =" << A;
	cout << "B =" << B<< endl;

	cout << "A + B =" << A + B;
	cout << "A - B =" << A - B;
	cout << "B / A =" << B / A;
	cout << "Scalar product A and B = " << A * B << endl;
	cout << "A * 5 =" << A * 5;
	if (A == B) {
		cout << "A = B";
	}
	else {
		cout << "A != B";
	}
	
	cout << "Enter the length of the matrix: ";
	cin >> n;

	TMatrix<double> M1(n, n);
	cout << "Enter the values of matrix M1: " << endl;
	cin >> M1;

	TMatrix<double> M2(n, n);
	cout << "Enter the values of matrix M2: " << endl;
	cin >> M2;

	cout << "\nM1:\n" << M1;
	cout << "M2:\n" << M2;

	cout << "M1 + M2:\n" << M1+M2 << endl;
	cout << "M1 - M2:\n" << M1 - M2 << endl;
	cout << "M1 * M2:\n" << M1 * M2 << endl;
	if (M1 == M2){
		cout << "M1 = M2\n";
	}
	else
	{
		cout << "M1 != M2\n";
	}

	return 0;
};