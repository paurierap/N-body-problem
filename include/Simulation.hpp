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
    double tStart;
    double tEnd;
    double dt_;
    std::size_t numSteps;
    static constexpr std::size_t maxSteps = 100000;

public:
    Simulation(std::vector<Body>, IntegratorPtr, double = 0, double = 1, double = 1e-4);
    void simulate(const std::string& = "output.csv");
    void setIntegrator(IntegratorPtr newIntegrator);
};

#endif