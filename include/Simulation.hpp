#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "Body.hpp"
#include "Vector2D.hpp"
#include "Integrator.hpp"
#include "VerletIntegrator.hpp"
#include <vector>
#include <string>
#include <memory>

// Simulation interface:

using IntegratorPtr = std::unique_ptr<Integrator>;

class Simulation {
private:
    std::vector<Body> bodies_;
    IntegratorPtr integrator_ {std::make_unique<VerletIntegrator>()};
    double tStart = 0;
    double tEnd = 1;
    double dt_ = 1e-4;
    std::size_t numSteps;
    static constexpr std::size_t maxSteps = 1e5;

public:
    Simulation(std::vector<Body>, IntegratorPtr, double, double, double);
    void simulate(const std::string& = "output.csv");
    void setIntegrator(IntegratorPtr newIntegrator);
};

#endif