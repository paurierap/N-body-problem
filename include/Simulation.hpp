#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "Body.hpp"
#include "Vector2D.hpp"
#include "Integrator.hpp"
#include <vector>
#include <string>

// Simulation interface:

class Simulation {
private:
    std::vector<Body> bodies_;
    std::unique_ptr<Integrator> integrator_;
    double T_start;
    double T_end;
    double dt_;
    std::size_t numberOfSteps;
    static constexpr int maxSteps = 1e5;

public:
    Simulation(std::vector<Body>, std::unique_ptr<Integrator>, double, double, double);
    void simulate(const std::string& = "output.csv");
};

#endif