// Test the solver

#include "Body.hpp"
#include "Simulation.hpp"
#include "Integrator.hpp"
#include "VerletIntegrator.hpp"
#include "EulerIntegrator.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>
#include <optional>

int main(int argc, char* argv[])
{
    // Check input arguments and correct usage:
    if (argc < 2) 
    {
        std::cerr << "Usage: " << argv[0] << " <initial_conditions_file> [T_start] [T_end] [dt] \n";
        return 1;
    }

    // Open file, parse and copy contents into vector<Body>:
    std::ifstream file(argv[1]);
    if (!file.is_open()) throw std::runtime_error("Input file could not be read");

    std::vector<Body> bodies;
    std::string line;

    while (std::getline(file, line)) 
    {
        // Skip comments or empty lines
        if (line.empty() || line[0] == '#') continue;

        std::stringstream ss(line);
        std::string token;
        std::vector<double> initial_conditions;

        while (std::getline(ss, token, ',')) initial_conditions.push_back(std::stod(token));

        if (initial_conditions.size() != 5) throw std::runtime_error("Input file was incorrectly read.");
        
        bodies.emplace_back(Vector2D(initial_conditions[0], initial_conditions[1]), Vector2D(initial_conditions[2], initial_conditions[3]), initial_conditions[4]);
    }

    // // Set default values for simulation parameters:
    // double T_start{0.0}, T_end{10.0}, dt{1e-4};

    // if (argc >= 3) T_start = std::stod(argv[2]);
    // if (argc >= 4) T_end = std::stod(argv[3]);
    // if (argc >= 5) dt = std::stod(argv[4]);

    // // Choose integrator:
    auto integrator{std::make_unique<VerletIntegrator>()};

    // // Simulate problem:
    // Simulation sim(bodies, std::move(integrator), T_start, T_end, dt);

    // sim.simulate("output.csv");

    std::optional<Simulation> sim;

    if (argc == 2) {
        sim.emplace(bodies, std::move(integrator));
    } else if (argc == 3) {
        double T_start = std::stod(argv[2]);
        sim.emplace(bodies, std::move(integrator), T_start);
    } else if (argc == 4) {
        double T_start = std::stod(argv[2]);
        double T_end = std::stod(argv[3]);
        sim.emplace(bodies, std::move(integrator), T_start, T_end);
    } else {
        double T_start = std::stod(argv[2]);
        double T_end = std::stod(argv[3]);
        double dt = std::stod(argv[4]);
        sim.emplace(bodies, std::move(integrator), T_start, T_end, dt);
    }

    sim->simulate("output.csv");

    return EXIT_SUCCESS;
}