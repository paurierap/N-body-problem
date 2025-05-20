#ifndef BODY_HPP
#define BODY_HPP

#include "Vector2D.hpp"

// Body interface: 

class Body {
private:
    Vector2D pos_;
    Vector2D vel_;
    Vector2D acc_;
    double mass_ = 1;
    //constexpr static double G = 6.67430e-11;
    constexpr static double G = 1; // Dimensionless

public:

    // Constructor:
    constexpr Body() = default;
    constexpr Body(Vector2D pos, Vector2D vel, double mass) noexcept : 
    pos_(pos), vel_(vel), acc_(), mass_(mass) {}
    
    // Rule of five
    Body(const Body&) = default;
    Body(Body&&) = default;
    Body& operator=(const Body&) = default;
    Body& operator=(Body&&) = default;
    ~Body() = default;

    // Accessors:
    constexpr const Vector2D& getPosition() const noexcept {return pos_; };
    constexpr const Vector2D& getVelocity() const noexcept {return vel_; };
    constexpr const Vector2D& getAcceleration() const noexcept {return acc_; };
    constexpr double getMass() const noexcept {return mass_; };

    // Setters:
    constexpr void setPosition(const Vector2D& pos) noexcept {pos_ = pos;  };
    constexpr void setVelocity(const Vector2D& vel) noexcept {vel_ = vel; };
    constexpr void setAcceleration(const Vector2D& acc) noexcept{acc_ = acc; };

    // Apply gravitational force from other body:
    void applyForce(const Body&) noexcept;
    double kineticEnergy() const noexcept;
    double potentialEnergy(const Body&) const noexcept;
};

#endif