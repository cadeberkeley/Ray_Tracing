#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <type_traits>

#include "vector.cpp"

template <typename T, size_t N> class Vector {
    
    static_assert(std::is_arithmetic<T>::value, "Not an arithmetic type");

    public:
        T elements [N];
        T x, y, z;

        Vector() {
            elements = new T[N];
        }

        Vector(T (&elems)[N]) {
            for (int i=0; i < N; i++) {
                elements[i] = elems[i];
            }
        }

        static Vector dot(Vector<T, N>& a, Vector<T, N> b) {

        }

        static Vector cross(Vector<T, N>& a, Vector<T, N> b);
        static Vector unit(Vector<T, N>& v);


        Vector dot(Vector<T, N>& a, Vector<T, N>& b);
        Vector cross(Vector<T, N>& a, Vector<T, N>& b);
        Vector unit();
        

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

        friend Vector operator*(Vector me, const T scalar) {
            me *= scalar;
            return me;
        }

        Vector& operator/=(const T scalar) {
            for (int i = 0; i < N; i++) {
                elements[i] /= scalar;
            }
            return *this;
        }

        friend Vector operator/(Vector me, const T scalar) {
            me /= scalar;
            return me;
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