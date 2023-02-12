#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <type_traits>

#include "vector.cpp"

//+/=, -/=, //=, *=, <<, >>, cross, dot, unit

template <typename T> class Vector {
    
    static_assert(std::is_arithmetic<T>::value, "Not an arithmetic type");

    

    private:
        T* elements;

    public:
        int x, y, z;
        Vector(size_t size) {
            elements = new T[size];
        }
/*
        Vector(T* elems) {
            elements = elems;
        }
*/
        static Vector dot(Vector<T>& a, Vector<T> b);
        static Vector cross(Vector<T>& a, Vector<T> b);
        static Vector unit(Vector<T>& v);


        Vector dot(Vector<T>& a, Vector<T>& b);
        Vector cross(Vector<T>& a, Vector<T>& b);
        Vector unit();
        

        Vector& operator+=(const Vector<T>& other) {
            x += other.x;
            y += other.y;
            z += other.z;
            return *this;
        }
        friend Vector operator+(Vector a, const Vector<T>& b) {
            a += b;
            return a;
        }
        friend Vector operator-=(const Vector<T>& me, const Vector<T>& other);
        friend Vector operator-(const Vector<T>& other);
        friend Vector operator*=(const Vector<T>& me, const T scalar);
        friend Vector operator*(const Vector<T>& me, const T scalar);
        friend Vector operator/=(const Vector<T>& me, const T scalar);
        friend Vector operator/(const Vector<T>& me, const T scalar);


        friend std::ostream & operator<<(std::ostream& os, const Vector<T>& v) {
            os << "(" << v.x << ", " << v.y << ", " << v.z << ")" << std::endl;
            return os;
        }

};



#endif