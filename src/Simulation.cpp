// Simulation implementation:

#include "Simulation.hpp"
#include "Recorder.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <cstddef>

Simulation::Simulation(std::vector<Body> bodies, IntegratorPtr integrator, double T0, double Tf, double dt) : 
    bodies_(std::move(bodies)), integrator_(std::move(integrator)), tStart(T0), tEnd(Tf), dt_(dt)
{

    // Check validity of time interval:
    if (tEnd <= tStart) throw std::invalid_argument("tEnd must be greater than tStart");

    // Check upper bound on number of steps:
    numSteps = static_cast<std::size_t>((tEnd - tStart) / dt_);
    if (numSteps > maxSteps) 
    {
        std::cerr << "Warning: the resulting time step dt is too small for this time interval. Adjusting dt to fit within " << maxSteps << " steps. New dt = ";
        dt_ = (tEnd - tStart) / static_cast<double>(maxSteps);
        std::cerr << dt_ << "\n";

        numSteps = maxSteps;
    }
}

void Simulation::simulate(const std::string& filename)
{
    std::cout << "Simulating " << bodies_.size() << " bodies from T = " << tStart << " to T = " << tEnd << " with dt = " << dt_ << ":\n";

    Recorder output(filename, bodies_.size());

    // Record initial state:
    output.record(tStart, bodies_);

    // Loop and integrate for each time step:
    for (std::size_t step = 1; step <= numSteps; step++)
    {
        integrator_->integrate(bodies_, dt_);
        output.record(tStart + step * dt_, bodies_);
    }

    std::cout << "Simulation finished! \n";
}

void Simulation::setIntegrator(IntegratorPtr newIntegrator)
{
    integrator_ = std::move(newIntegrator);
}