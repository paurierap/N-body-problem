#ifndef EULERINTEGRATOR_HPP
#define EULERINTEGRATOR_HPP

#include "Integrator.hpp"
#include "Body.hpp"
#include <vector>

class EulerIntegrator : public Integrator
{
public:
    virtual void integrate(std::vector<Body>& bodies, double dt) override
    {
        // Step 1: Reset and compute a(t)
        for (auto& body : bodies)
        {
            body.setAcceleration(Vector2D(0.0, 0.0));
        }

        for (std::size_t i = 0; i < bodies.size(); ++i) 
        {
            for (std::size_t j = i + 1; j < bodies.size(); ++j) 
            {
                bodies[i].applyForce(bodies[j]);
                bodies[j].applyForce(bodies[i]);
            }
        }

        // Step 2: Update x(t + dt)
        for (auto& body : bodies) 
        {
            body.setPosition(body.getPosition() + body.getVelocity() * dt);
            body.setVelocity(body.getVelocity() + body.getAcceleration() * dt);
        }
    }
};

#endif