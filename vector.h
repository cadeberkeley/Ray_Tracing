#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <type_traits>
#include <math.h>

#include "vector.cpp"

template <typename T, size_t N> class Vector {
    
    static_assert(std::is_arithmetic<T>::value, "Not an arithmetic type");

    public:
        static T dot(Vector<T, N> a, Vector<T, N> b) {
            T sum = 0;
            for (int i = 0; i < N; i++) {
                sum += a.elements[i] *= b.elements[i];
            }
            return sum;
        }

        static Vector cross(Vector<T, N> a, Vector<T, N> b) {
            assert(N == 3);
            T cross [3] = { a.elements[1] * b.elements[2] - a.elements[2] * b.elements[1],
                                a.elements[2] * b.elements[0] - a.elements[0] * b.elements[2],
                                a.elements[0] * b.elements[1] - a.elements[1] * b.elements[0]
                            };
            return Vector<T, N>(cross);
        }

    public:
        T elements [N];

        Vector() {
            elements = new T[N];
        }

        Vector(T (&elems)[N]) {
            for (int i=0; i < N; i++) {
                elements[i] = elems[i];
            }
        }


        T dot(Vector<T, N> other) {
            return Vector<T, N>::dot(*this, other);
        }

        Vector cross(Vector<T, N> other) {
            return Vector<T, N>::cross(*this, other);
        }

        Vector normalized() {
            return *this / length();
        }

        float length() {
            T sum = 0;
            for (int i = 0; i < N; i++) {
                sum += elements[i];
            }
            return (T) sqrt(sum);
        }
        

        Vector& operator+=(const Vector<T, N>& other) {
            for (int i = 0; i < N; i++) {
                elements[i] += other.elements[i];
            }
            return *this;
        }

        friend Vector operator+(Vector a, const Vector<T, N>& b) {
            a += b;
            return a;
        }

        Vector& operator-=(const Vector<T, N>& other) {
            for (int i = 0; i < N; i++) {
                elements[i] -= other.elements[i];
            }
            return *this;
        }

        friend Vector operator-(Vector a, const Vector<T, N>& b) {
            a -= b;
            return a;
        }

        Vector& operator*=(const T scalar) {
            for (int i = 0; i < N; i++) {
                elements[i] *= scalar;
            }
            return *this;
        }

        friend Vector operator*(Vector v, const T scalar) {
            v *= scalar;
            return v;
        }

        Vector& operator/=(const T scalar) {
            for (int i = 0; i < N; i++) {
                elements[i] /= scalar;
            }
            return *this;
        }

        friend Vector operator/(Vector v, const T scalar) {
            v /= scalar;
            return v;
        }

        friend std::ostream & operator<<(std::ostream& os, const Vector<T, N>& v) {
            os << "(";
            for (int i = 0; i < N-1; i++) {
                os << v.elements[i] << ", ";
            }
            os << v.elements[N-1] << ")" << std::endl;
            return os;
        }

};



#endif