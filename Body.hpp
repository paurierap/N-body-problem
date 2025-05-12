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
    constexpr static double G = 6.67430e-11;

public:

    // Constructors:
    Body(Vector2D, Vector2D, double);
    Body(const Body&);

    // Accessors:
    const Vector2D& getPosition() const;
    const Vector2D& getVelocity() const;
    double getMass() const;

    // Update functions:
    void resetAcceleration();
    void applyForce(const Body&);
    void updatePosition(double);
    void updateVelocity(double);
};

#endif