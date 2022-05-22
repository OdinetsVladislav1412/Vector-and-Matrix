#pragma once
#include <iostream>
using namespace std;



template<class T>
class TVector
{
protected:

	T* data;
	int len;

public:

    TVector();
	TVector(int n, T v);
    TVector(int n);
    TVector(const TVector<T>& p);
    ~TVector();

    int GetLen() const;

    T& operator[](int i);
    TVector<T>& operator = (const TVector<T>& p);
    TVector<T> operator + (const TVector<T>& p);
    TVector<T> operator - (const TVector<T>& p);
    TVector<T> operator / (const TVector<T>& p);
    T operator*(const TVector<T>& v);
    TVector<T> operator * (const T n);
    bool operator == (const TVector<T>& p);

    friend ostream& operator<<(ostream& ostr, TVector<T>& p)
    {
        for (int i = 0; i < p.GetLen(); i++)
            ostr << " " << p[i] ;
        if (int j = 0 <= p.GetLen()) {
            cout << "\n";
            j++;
            }
        else
        {
            cout << "\t ";
            ++j;
        }
        return ostr;
    }

    friend istream& operator>>(istream& t, TVector<T>& v) 
    {
        if (v.GetLen() == 0)
            throw "length must be > 0";
        for (int i = 0; i < v.GetLen(); i++) {
            cout << "[" << i << "]: ";
            t >> v[i];
        }
        return t;
    }
};



template<class T>
inline TVector<T>::TVector()
{
    len = 0;
    data = nullptr;
}

template<class T>
inline TVector<T>::TVector(int n, T v)
{
    if (n > 0)
    {
        data = new T[n];
        len = n;
        for (int i = 0; i < n; i++)
            data[i] = v;
    }
    else 
    {
        cout << "length <= 0"<< endl;
    }
}

template<class T>
inline TVector<T>::TVector(int n)
{
    data = new T[n];
    len = n;
    for (int i = 0; i < n; i++)
        data[i] = 0;
}

template<class T>
inline TVector<T>::TVector(const TVector<T>& p)
{
    data = new T[p.len];
    len = p.len;
    for (int i = 0; i < p.len; i++)
        data[i] = p.data[i];
}

template<class T>
inline TVector<T>::~TVector()
{
    if (data != nullptr)
    {
        delete[] data;
        data = nullptr;
    }
}

template<class T>
inline int TVector<T>::GetLen() const
{
    return len;
}

template<class T>
inline T& TVector<T>::operator[](int i)
{
   
        return data[i];
}

template<class T>
inline TVector<T>& TVector<T>::operator=(const TVector<T>& p)
{
    if (data != nullptr)
    {
        delete[] data;
        data = nullptr;
    }
    data = new T[p.len];
    len = p.len;
    for (int i = 0; i < p.len; i++)
        data[i] = p.data[i];
    return *this;
}

template<class T>
inline TVector<T> TVector<T>::operator+(const TVector<T>& p)
{
    if (this->len != p.len) {
        cout << "sizes don't match" << endl;
    }

    else {
        TVector<T> res(*this);
        for (int q = 0; q < len; q++)
        {
            res.data[q] = (this->data[q]) + p.data[q];
        }

        return res;
    }
}

template<class T>
inline TVector<T> TVector<T>::operator-(const TVector<T>& p)
{
    if (this->len != p.len) {
        cout << "sizes don't match" << endl;

    }
    else {
        TVector<T> res(*this);
        for (int q = 0; q < len; q++)
        {
            res.data[q] = (this->data[q]) - p.data[q];
        }
        return res;
    }
}

template<class T>
inline TVector<T> TVector<T>::operator/(const TVector<T>& p)
{
    if (this->len != p.len) {
        cout << "sizes don't match" << endl;

    }
    else {
        TVector<T> res(*this);
        for (int q = 0; q < len; q++)
        {
            res.data[q] = (this->data[q]) / p.data[q];
        }
        return res;
    }
}

template<class T>
inline T TVector<T>::operator*(const TVector<T>& v)
{
    if (len != v.GetLen()) {
        cout << "different sizes";
    }
    T res = 0;

    for (int i = 0; i < len; i++) {
        res += (this->data[i]) * v.data[i];
    }
    return res;
}

template<class T>
inline TVector<T> TVector<T>::operator*(const T n)
{
    TVector<T> res(len);

    for (int i = 0; i < len; i++)
        res[i] = data[i] * n;

    return res;
}

template<class T>
inline bool TVector<T>::operator==(const TVector<T>& p)
{
    if (len != p.len)
        return false;
    for (int i = 0; i < len; i++)
        if (data[i] != p.data[i])
            return false;
    return true;
}
