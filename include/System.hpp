#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "Body.hpp"
#include "Vector2D.hpp"
#include <vector>

// System interface:

class System {
private:
    std::vector<Body> bodies_;
    double T_start;
    double T_end;
    double dt_;

public:
    System(std::vector<Body>, double = 0, double = 1, double = 1e-3);
    void simulate();
};

#endif