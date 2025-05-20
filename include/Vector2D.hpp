#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <iostream>
#include <stdexcept>

class Vector2D {
private:
    double x_ = 0;
    double y_ = 0;

public:

    // Constructors
    constexpr Vector2D() = default;
    constexpr Vector2D(double x, double y) noexcept : x_(x), y_(y) {}

    // Rule of five
    Vector2D(const Vector2D&) = default;
    Vector2D(Vector2D&&) = default;
    Vector2D& operator=(const Vector2D&) = default;
    Vector2D& operator=(Vector2D&&) = default;
    ~Vector2D() = default;

    // Assignment
    Vector2D& operator+=(const Vector2D&) noexcept;
    Vector2D& operator-=(const Vector2D&) noexcept;
    Vector2D& operator*=(double) noexcept;
    Vector2D& operator/=(double);

    // Access operator
    double& operator[](int);
    double operator[](int) const;
    
    // Overload arithmetic operators
    friend Vector2D operator+(const Vector2D&, const Vector2D&);
    friend Vector2D operator-(const Vector2D&, const Vector2D&);
    friend Vector2D operator*(double, const Vector2D&);
    friend Vector2D operator*(const Vector2D&, double);
    friend Vector2D operator/(const Vector2D&, double);

    // Output vector in a nice format
    friend std::ostream& operator<<(std::ostream&, const Vector2D&) noexcept;
};

// Get norm of a vector
double norm(const Vector2D&) noexcept;

#endif