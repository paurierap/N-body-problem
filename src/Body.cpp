// Body implementation

#include "Body.hpp"
#include "Vector2D.hpp"
#include <cmath>

// Apply gravitational force from other body:
void Body::applyForce(const Body& other_body) noexcept
{
    Vector2D r_vec{other_body.getPosition() - pos_};
    constexpr double eps = 1e-5; // Gravitational softening length to avoid r->0
    double r = norm(r_vec);
    double denom = std::pow(r * r + eps * eps, 1.5);
    
    acc_ += G * other_body.mass_ / denom * r_vec;
}

// Calculate contributions to energy
double Body::kineticEnergy() const noexcept
{
    double v = norm(vel_);
    return 0.5 * mass_ * v * v;
}

double Body::potentialEnergy(const Body& other_body) const noexcept
{
    if (&other_body == this) return 0.0;
    return - G * mass_ * other_body.getMass() / norm(other_body.getPosition() - pos_);
}