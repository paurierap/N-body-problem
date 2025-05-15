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
#include <cstddef>

int main(int argc, char* argv[])
{
    // Check input arguments and correct usage:
    if (argc < 2) 
    {
        std::cerr << "Usage: " << argv[0] << " <initial_conditions_file> [T_start] [T_end] [dt] \n";
        return 1;
    }

    // Open file and copy contents into vector<Body>:
    std::ifstream in(argv[1]);
    if (!in.is_open()) throw std::runtime_error("Input file could not be read");

    std::vector<Body> bodies;
    std::string line;

    while (std::getline(in, line)) 
    {
        // Skip comments or empty lines
        if (line.empty() || line[0] == '#') continue;
    
        std::istringstream iss(line);
        double x, y, vx, vy, m;
        if (iss >> x >> y >> vx >> vy >> m) bodies.emplace_back(Vector2D(x, y), Vector2D(vx, vy), m);
        else std::cerr << "Malformed line: " << line << '\n';
    }

    // Set default values for simulation parameters:
    double T_start{0.0}, T_end{10.0}, dt{1e-4};

    if (argc >= 3) T_start = std::stod(argv[2]);
    if (argc >= 4) T_end = std::stod(argv[3]);
    if (argc >= 5) dt = std::stod(argv[4]);

    // Choose integrator:
    auto integrator{std::make_unique<VerletIntegrator>()};

    // Simulate problem:
    Simulation sim(bodies, std::move(integrator), T_start, T_end, dt);

    sim.simulate("positions.csv");

    return EXIT_SUCCESS;
}