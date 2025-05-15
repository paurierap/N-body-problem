// Body implementation

#include "Body.hpp"
#include "Vector2D.hpp"
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

const Vector2D& Body::getAcceleration() const
{
    return acc_;
}

double Body::getMass() const
{
    return mass_;
}


// Setters:
void Body::setPosition(const Vector2D& pos)
{
    pos_ = pos;
}

void Body::setVelocity(const Vector2D& vel)
{
    vel_ = vel;
}

void Body::setAcceleration(const Vector2D& acc)
{
    acc_ = acc;
}


// Apply gravitational force from other body:
void Body::applyForce(const Body& other_body)
{
    Vector2D r_vec{other_body.getPosition() - pos_};
    constexpr double eps = 1e-5; // Gravitational softening length to avoid r->0
    double r = std::pow(norm(r_vec) * norm(r_vec) + eps * eps, 1.5);
    
    acc_ += G * other_body.mass_ / r * r_vec;
}

double Body::KineticEnergy() const
{
    double v = norm(vel_);
    return 0.5 * mass_ * v * v;
}

double Body::PotentialEnergy(const Body& other_body) const
{
    return - G * mass_ * other_body.getMass() / norm(other_body.getPosition() - pos_);
}