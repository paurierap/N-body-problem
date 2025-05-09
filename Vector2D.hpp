#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <iostream>

class Vector2D {
private:
    double x_, y_;
public:

    // Constructors
    Vector2D();
    Vector2D(double, double);
    Vector2D(const Vector2D&);

    // Assignment
    Vector2D& operator=(const Vector2D&);
    Vector2D& operator+=(const Vector2D&);
    Vector2D& operator-=(const Vector2D&);
    Vector2D& operator*=(double);
    Vector2D& operator/=(double);

    // Access operator
    double& operator[](int);
    double operator[](int) const;
    
    // Overload arithmetic operators
    friend Vector2D operator+(const Vector2D&, const Vector2D&);
    friend Vector2D operator-(const Vector2D&, const Vector2D&);
    friend Vector2D operator*(double, const Vector2D&);
    friend Vector2D operator*(const Vector2D&, double);
    friend Vector2D operator/(double, const Vector2D&);
    friend Vector2D operator/(const Vector2D&, double);

    // Get norm of a vector
    friend double norm(const Vector2D&);

    // Output vector in a nice format
    friend std::ostream& operator<<(std::ostream&, const Vector2D&);
};

#endif