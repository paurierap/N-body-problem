// System implementation:

#include "System.hpp"
#include <stdexcept>

System::System(std::vector<Body> bodies, double T0, double Tf, double dt) : 
    bodies_(std::move(bodies)), T_start(T0), T_end(Tf), dt_(dt) 
{
    if (std::abs(T_end) < std::abs(T_start)) 
    {
        throw std::runtime_error("T_end must be equal or larger than T_start");
    }
    else if (dt_ <= 0.0) 
    {
        throw std::runtime_error("dt must be positive");
    }
}

void System::simulate()
{
    int numberOfSteps = static_cast<int>((T_end - T_start) / dt_);

    for (int step = 1; step <= numberOfSteps; step++)
    {
        // Reset accelerations
        for (auto& body : bodies_) {
            body.resetAcceleration();
        }

        // Compute pairwise forces
        for (size_t i = 0; i < bodies_.size(); ++i) {
            for (size_t j = i + 1; j < bodies_.size(); ++j) {
                bodies_[i].applyForce(bodies_[j]);
                bodies_[j].applyForce(bodies_[i]); // Newton's 3rd law
            }
        }

        // Update all bodies
        for (auto& body : bodies_) {
            body.updateVelocity(dt_);
            body.updatePosition(dt_);
        }
    }

}

