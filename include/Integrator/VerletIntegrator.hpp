#ifndef VERLETINTEGRATOR_HPP
#define VERLETINTEGRATOR_HPP

#include "Integrator.hpp"
#include "Body.hpp"
#include <vector>

class VerletIntegrator : public Integrator
{
public:
    virtual void integrate(std::vector<Body>& bodies, double dt) override
    {
        std::vector<Vector2D> acc_old;
        acc_old.reserve(bodies.size());

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

        // Step 2: Save a(t), update x(t + dt)
        for (auto& body : bodies) 
        {
            acc_old.push_back(body.getAcceleration());
            body.setPosition(body.getPosition() + body.getVelocity() * dt + 0.5 * body.getAcceleration() * dt * dt);
        }

        // Step 3: Reset and compute a(t + dt)
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

        // Step 4: Update v(t + dt)
        for (std::size_t i = 0; i < bodies.size(); ++i) 
        {
            bodies[i].setVelocity(bodies[i].getVelocity() + 0.5 * dt * (acc_old[i] + bodies[i].getAcceleration()));
        }
    }
};

#endif
