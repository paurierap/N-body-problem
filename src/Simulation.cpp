// Simulation implementation:

#include "Simulation.hpp"
#include "Recorder.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <cstddef>

Simulation::Simulation(std::vector<Body> bodies, std::unique_ptr<Integrator> integrator, double T0, double Tf, double dt) : 
    bodies_(std::move(bodies)), integrator_(std::move(integrator)), T_start(T0), T_end(Tf), dt_(dt)
{

    // Check validity of time interval:
    if (T_end <= T_start) throw std::invalid_argument("T_end must be greater than T_start");

    // Check upper bound on number of steps:
    numberOfSteps = static_cast<std::size_t>((T_end - T_start) / dt_);
    if (numberOfSteps > maxSteps) 
    {
        std::cerr << "Warning: the resulting time step dt is too small for this time interval. Adjusting dt to fit within " << maxSteps << " steps. New dt = ";
        dt_ = (T_end - T_start) / static_cast<double>(maxSteps);
        std::cerr << dt_ << "\n";

        numberOfSteps = maxSteps;
    }
}

void Simulation::simulate(const std::string& filename)
{
    std::cout << "Simulating " << bodies_.size() << " bodies from T = " << T_start << " to T = " << T_end << " with dt = " << dt_ << ":\n";

    Recorder output(filename, bodies_.size());

    // Record initial state:
    output.record(T_start, bodies_);

    // Loop and integrate for each time step:
    for (std::size_t step = 1; step <= numberOfSteps; step++)
    {
        integrator_->integrate(bodies_, dt_);
        output.record(T_start + step * dt_, bodies_);
    }

    std::cout << "Simulation finished! \n";
}