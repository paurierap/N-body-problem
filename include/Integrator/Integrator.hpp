#ifndef INTEGRATOR_HPP
#define INTEGRATOR_HPP

#include "Body.hpp"
#include <vector>

// Abstract type for integrator:

class Integrator
{
public:
    virtual ~Integrator() = default;
    virtual void integrate(std::vector<Body>&,double) = 0;
};

#endif