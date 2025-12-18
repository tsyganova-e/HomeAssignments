/*
 * Elena Tsyganova
 * st142266@student.spbu.ru
 * Assignment3
 */
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

template <size_t M, size_t N, typename T = double>
class Matrix
{
private:
    T data[M][N];

public:
    template<size_t, size_t, typename> friend class Matrix;
    Matrix()
    {
        for (size_t i = 0; i < M; ++i)
            for (size_t j = 0; j < N; ++j)
                data[i][j] = T{};
    }

    T& operator()(size_t i, size_t j)
    {
        return data[i][j];
    }

    Matrix<M, N, T> operator+(Matrix<M, N, T>& other)
    {
        Matrix<M, N, T> result;
        for (size_t i = 0; i < M; ++i)
            for (size_t j = 0; j < N; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix<M, N, T> operator*(T& scalar)
    {
        Matrix<M, N, T> result;
        for (size_t i = 0; i < M; ++i)
            for (size_t j = 0; j < N; ++j)
                result.data[i][j] = data[i][j] * scalar;
        return result;
    }

    template <size_t P>
    Matrix<M, P, T> operator*(Matrix<N, P, T>& other)
    {
        Matrix<M, P, T> result;
        for (size_t i = 0; i < M; ++i)
            for (size_t j = 0; j < P; ++j)
                for (size_t k = 0; k < N; ++k)
                    result.data[i][j] = result.data[i][j] + data[i][k] * other.data[k][j];
        return result;
    }

    Matrix<N, M, T> transpose()
    {
        Matrix<N, M, T> result;
        for (size_t i = 0; i < M; ++i)
            for (size_t j = 0; j < N; ++j)
                result.data[j][i] = data[i][j];
        return result;
    }

};

#endif
