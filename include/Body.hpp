#ifndef BODY_HPP
#define BODY_HPP

#include "Vector2D.hpp"

// Body interface: 

class Body {
private:
    Vector2D pos_;
    Vector2D vel_;
    Vector2D acc_;
    double mass_;
    //constexpr static double G = 6.67430e-11;
    constexpr static double G = 1.0; // Dimensionless

public:

    // Constructors:
    Body(Vector2D, Vector2D, double);
    Body(const Body&);

    // Accessors:
    const Vector2D& getPosition() const;
    const Vector2D& getVelocity() const;
    const Vector2D& getAcceleration() const;
    double getMass() const;

    // Setters:
    void setPosition(const Vector2D&);
    void setVelocity(const Vector2D&);
    void setAcceleration(const Vector2D&);

    // Apply gravitational force from other body:
    void applyForce(const Body&);
    double KineticEnergy() const;
    double PotentialEnergy(const Body&) const;
};

#endif