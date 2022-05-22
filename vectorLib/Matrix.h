#pragma once
#include "Vector.h"

template<class T>
class TMatrix : public TVector<TVector<T>>
{
protected:

	int len1;

public:

	TMatrix();
	TMatrix(int n1);
	TMatrix(int n1, int n2);
	TMatrix(int n1, int n2, T v);
	TMatrix(const TMatrix<T>& m);
	~TMatrix();

	int GetLen1() const;

	TMatrix<T>& operator = (const TMatrix<T>& m);
	bool operator == (const TMatrix<T>& m);
	TMatrix<T> operator + (const TMatrix<T>& m);
	TMatrix<T> operator - (const TMatrix<T>& m);
	TMatrix<T> operator * (const TMatrix<T>& p);
	TMatrix<T> operator * (const T c);

	//TMatrix<T> operator * (const TVector<T>& v);
};



template<class T>
inline TMatrix<T>::TMatrix() : TVector<TVector<T>>::TVector()
{
	this ->len = 0;
	this-> len1 = 0;
	this-> data = 0;
}

template<class T>
inline TMatrix<T>::TMatrix(int n1) : TVector<TVector<T>>::TVector(n1)
{
	len1 = 1;
	for (int i = 0; i < n1; i++)
	{
		this->data[i] = 1;
		for (int j = 0; j < 1; j++) {
			data[i][j] = 0;
		}
	}
}

template<class T>
inline TMatrix<T>::TMatrix(int n1, int n2) : TVector<TVector<T>>::TVector(n1)
{
	len1 = n2;
	for (int i = 0; i < n1; i++)
	{
		this->data[i] = n2;
		for (int j = 0; j < n2; j++) {
			data[i][j] = 0;
		}
	}
}

template<class T>
inline TMatrix<T>::TMatrix(int n1, int n2, T v) : TVector<TVector<T>>::TVector(n1)
{
	len1 = n2;
	for (int i = 0; i < n1; i++)
	{
		this->data[i] = n2;
		for (int j = 0; j < n2; j++) {
			data[i][j] = v;
		}
	}
}

template<class T>
inline TMatrix<T>::TMatrix(const TMatrix<T>& m) 
{

	len1 = m.len1;
	this->len = m.len;
	this->data = new TVector<T>[len1];
	for (int i = 0; i < len1; i++)
		this->data[i] = TVector<T>(this->len);
	this->len = m.len;

	for (int i = 0; i < m.len1; i++)
		for (int j = 0; j < m.len; j++)
			this->data[i][j] = m.data[i][j];

}

template<class T>
inline TMatrix<T>::~TMatrix()
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
}

template<class T>
inline int TMatrix<T>::GetLen1() const
{
	return len1;
}

template<class T>
inline TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& m)
{
	if (this == &m) return *this;
	if (this->len != m.len || len1 != m.len1) {
		cout << "sizes don't match" << endl;}
	for (int i = 0; i < len1; i++)
		for (int j = 0; j < this->len; j++)
			data[i][j] = m.data[i][j];
	return *this;
}

template<class T>
inline bool TMatrix<T>::operator==(const TMatrix<T>& m)
{
	if (this->len != m.len || len1 != m.len1) return false;
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len; j++)
			if (data[i][j] != m.data[i][j]) return false;
	}
	return true;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator+(const TMatrix& m)
{
	if (this->len != m.len || len1 != m.len1) {
		cout << "sizes don't match" << endl;
	}
	TMatrix res(*this);
	for (int i = 0; i < len1; i++)
		for (int j = 0; j < this->len; j++)
			res.data[i][j] = this->data[i][j] + m.data[i][j];
	return res;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator-(const TMatrix& m)
{
	if (this->len != m.len || len1 != m.len1) {
		cout << "sizes don't match" << endl;
	}
	TMatrix res(*this);
	for (int i = 0; i < len1; i++)
		for (int j = 0; j < this->len; j++)
			res.data[i][j] = this->data[i][j] - m.data[i][j];
	return res;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& p)
{
	TMatrix<T> res(p.len, len1, 0);
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < p.len; j++)
		{
			res[i][j] = 0;
			for (int l = 0; l < this->len; l++)
				res[i][j] += this->data[i][l] * p.data[l][j];
		}
	}
	return res;
}

template <class T>
TMatrix<T> TMatrix<T>::operator*(const T a) 
{
	TMatrix<T> res(*this);

	for (int i = 0; i < len1; i++) {
		res[i] = res[i] * a;
	}
	return res;
}


/*template<class T>
TMatrix<T> TMatrix<T>::operator*(const TVector<T>& v) 
{
	TVector<T> temp(v);
	if ((this->len) != temp.GetLen()) throw "problem";

	TMatrix<T> res(1, len1, 0);
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			res[i][j] = 0;
			for (int x = 0; x < this->len; x++)
				res[i][j] += this->data[i][x] * temp[x];
		}
	}
	return res;
}*/


