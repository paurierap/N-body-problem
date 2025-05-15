// Vector2D implementation

#include "Vector2D.hpp"
#include <cmath>
#include <stdexcept>

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
Vector2D& Vector2D::operator+=(const Vector2D& other) {
    x_ += other.x_;
    y_ += other.y_;
    return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& other) {
    x_ -= other.x_;
    y_ -= other.y_;
    return *this;
}

Vector2D& Vector2D::operator*=(double scalar) {
    x_ *= scalar;
    y_ *= scalar;
    return *this;
}

Vector2D& Vector2D::operator/=(double scalar) {
    if (scalar == 0) throw std::runtime_error("Division by zero");
    x_ /= scalar;
    y_ /= scalar;
    return *this;
}

Vector2D operator+(const Vector2D& u, const Vector2D& v)
{
    return Vector2D(u) += v;
}

Vector2D operator-(const Vector2D& u, const Vector2D& v)
{
    return Vector2D(u) -= v;
}

Vector2D operator*(const Vector2D& u, double scalar)
{
    return Vector2D(u) *= scalar;
}

Vector2D operator*(double scalar, const Vector2D& u)
{
    return Vector2D(u) *= scalar;
}

Vector2D operator/(const Vector2D& u, double scalar)
{
    return Vector2D(u) /= scalar;
}

Vector2D operator/(double scalar, const Vector2D& u)
{
    return Vector2D(u) /= scalar;
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

double Vector2D::operator[](int index) const {
    if (index == 0) return x_;
    if (index == 1) return y_;
    throw std::out_of_range("Index out of range: Vector2D only supports indices 0 and 1");
}

// Print vector formatted:
std::ostream& operator<<(std::ostream& output, const Vector2D& vec)
{
    output << "(" << vec.x_ << ", " << vec.y_ << ")";
    return output;
}