// Body implementation

#include "Body.hpp"
#include <cmath>

// Constructors:
Body::Body(Vector2D pos, Vector2D vel, double mass) : 
    pos_(pos), vel_(vel), acc_(), mass_(mass) {}

Body::Body(const Body& body) : 
    pos_(body.pos_), vel_(body.vel_), acc_(), mass_(body.mass_) {}


// Accessors:
const Vector2D& Body::getPosition() const
{
    return pos_;
}

const Vector2D& Body::getVelocity() const
{
    return vel_;
}
    
double Body::getMass() const
{
    return mass_;
}


// Update functions:
void Body::resetAcceleration()
{
    for (int i = 0; i < 2; i++) acc_[i] = 0;
}

void Body::applyForce(const Body& other_body)
{
    Vector2D F_vec(other_body.pos_ - pos_);
    constexpr double eps = 1e-5; // Gravitational softening length to avoid r->0
    double r = norm(F_vec) * norm(F_vec) + eps * eps;
    
    double F_mag = G * other_body.mass_ * mass_ / std::sqrt(r * r * r);

    acc_ += F_mag * F_vec;
}

void Body::updatePosition(double dt)
{
    pos_ += dt * vel_;
}

void Body::updateVelocity(double dt)
{
    vel_ += dt * acc_;
}
