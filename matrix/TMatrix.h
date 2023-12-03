#ifndef _TMATRIX_H_
#define _TMATRIX_H_
// Copyright 2023 Vasenkov Andrey
#include "../vector/TVector.h"
#include <iostream>

const int MAX_MATRIX_SIZE = 10000;

template<class T>
class TMatrix;
template<class T>
std::istream& operator>>(std::istream& istr, TMatrix<T>& v);
template<class T>
std::ostream& operator<<(std::ostream& ostr, const TMatrix<T>& m);

template<typename T>
class TMatrix : private TVector<TVector<T>> {
    using TVector<TVector<T>>::pMem;
    using TVector<TVector<T>>::_size;
public:
    TMatrix(size_t s) : TVector<TVector<T>>(s) {
        if (s > MAX_MATRIX_SIZE)
            throw std::length_error("Matrix size cannot be greater than MAX_VECTOR_SIZE = " + std::to_string(MAX_VECTOR_SIZE));
        if (s < 0)
            throw std::length_error("Matrix size cannot be less than zero");
        for (size_t i = 0; i < s; i++)
            pMem[i] = TVector<T>(s);
    }
    // ïî÷åìó ìîæíî ñäåëàòü òàê? Îáúÿñíèòü.
    using TVector<TVector<T>>::operator[];
    using TVector<TVector<T>>::at;
    using TVector<TVector<T>>::size;

    // ñðàâíåíèå
    bool operator==(const TMatrix& m) const noexcept {
        if (_size != m._size) { return false; }
        for (int i = 0; i < _size; i++) {
            if (pMem[i] != m.pMem[i]) { return false; }
        }
        return true;
    }
    bool operator!=(const TMatrix& m) const noexcept { return !(*this == m); }

    // ìàòðè÷íî-ñêàëÿðíûå îïåðàöèè
    TMatrix operator*(const T& val) {
        TMatrix<T> tmp(*this);
        for (int i = 0; i < _size; i++) {
            tmp[i] = tmp[i] * val;
        }
        return tmp;
    }

    // ìàòðè÷íî-âåêòîðíûå îïåðàöèè
    TVector<T> operator*(const TVector<T>& v) {
        if (v.size() != _size) { throw std::logic_error("Not equl size, operation not defined"); }
        TVector<T> tmp(v);
        for (int i = 0; i < _size; i++) {
            tmp[i] = pMem[i] * v;
        }
        return tmp;
    }

    // ìàòðè÷íî-ìàòðè÷íûå îïåðàöèè
    TMatrix operator+(const TMatrix& m) {
        if (m._size != _size) { throw std::logic_error("Not equl size, operation not defined"); }
        TMatrix<T> tmp(*this);
        for (int i = 0; i < _size; i++) {
            tmp[i] = tmp[i] + m[i];
        }
        return tmp;
    }
    TMatrix operator-(const TMatrix& m) {
        if (m._size != _size) { throw std::logic_error("Not equl size, operation not defined"); }
        TMatrix<T> tmp(*this);
        for (int i = 0; i < _size; i++) {
            tmp[i] = tmp[i] - m[i];
        }
        return tmp;
    }
    TMatrix operator*(const TMatrix& m) {
        if (m._size != _size) { throw std::logic_error("Not equl size, operation not defined"); }
        TMatrix<T> tmp(_size);
        for (int i = 0; i < _size; i++) {
            for (int j = 0; j < _size; j++) {
                tmp[i][j] = m[j][i];
            }
        }
        TMatrix<T> res(_size);
        for (int i = 0; i < _size; i++) {
            for (int j = 0; j < _size; j++) {
                res[i][j] = pMem[i] * tmp[j];
            }
        }
        return res;
    }

    // ââîä/âûâîä
    friend std::istream& operator>> <T>(std::istream& istr, TMatrix& v);
    friend std::ostream& operator<< <T>(std::ostream& ostr, const TMatrix& v);
};

template<class T>
std::istream& operator>>(std::istream& istr, TMatrix<T>& m) {
    for (size_t i = 0; i < m._size; i++)
        istr >> m[i];
    return istr;
}

template<class T>
std::ostream& operator<<(std::ostream& ostr, const TMatrix<T>& m) {
    for (size_t i = 0; i < m._size; i++) {
        ostr << m.pMem[i] << '\n';
    }
    return ostr;
}

#endif  // INCLUDE_MATRIX_H_