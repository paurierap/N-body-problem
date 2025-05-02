// Vector2D implementation

#include "Vector2D.hpp"
#include <cmath>


// Constructors:
Vector2D::Vector2D() : x_(0), y_(0) {}
Vector2D::Vector2D(double x, double y): x_(x), y_(y) {}
Vector2D::Vector2D(const Vector2D& vec): x_(vec.x_), y_(vec.y_) {}


// Copy assignment 
Vector2D& Vector2D::operator=(const Vector2D& vec){
    x_ = vec.x_;
    y_ = vec.y_;
    return *this;
}


// Arithmetic operators
Vector2D operator+(const Vector2D& u, const Vector2D& v)
{
    Vector2D w(u.x_ + v.x_, u.y_ + v.y_);
    return w;
}

Vector2D operator-(const Vector2D& u, const Vector2D& v)
{
    Vector2D w(u.x_ - v.x_, u.y_ - v.y_);
    return w;
}

Vector2D operator*(const Vector2D& u, double scalar)
{
    Vector2D w(scalar * u.x_, scalar * u.y_);
    return w;
}

Vector2D operator*(double scalar, const Vector2D& u)
{
    return u * scalar;
}


// Euclidean norm:
double norm(const Vector2D& vec)
{
    return std::sqrt(vec.x_ * vec.x_ + vec.y_ * vec.y_);
}


// Access to members x and y:
double& Vector2D::operator[](int index) {
    if (index == 0) return x_;
    if (index == 1) return y_;
    throw std::out_of_range("Index out of range: Vector2D only supports indices 0 and 1");
}


// Print vector formatted:
std::ostream& operator<<(std::ostream& output, const Vector2D& vec)
{
    output << "(" << vec.x_ << ", " << vec.y_ << ")" << std::endl;
    return output;
}