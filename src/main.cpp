// Test the solver

#include "System.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept> 

int main()
{
    std::ifstream in("bodies.txt");
    std::vector<Body> bodies;
    double x, y, vx, vy, m;

    if (!in.is_open()) throw std::runtime_error("Input file could not be read");
    while (in >> x >> y >> vx >> vy >> m) {
        bodies.emplace_back(Vector2D(x, y), Vector2D(vx, vy), m);
    }

    System sys(bodies);

    sys.simulate();
    return EXIT_SUCCESS;
}