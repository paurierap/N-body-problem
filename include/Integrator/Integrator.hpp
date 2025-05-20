#ifndef INTEGRATOR_HPP
#define INTEGRATOR_HPP

#include "Body.hpp"
#include <vector>
#include <string>

// Abstract type for integrator:

class Integrator
{
public:
    virtual ~Integrator() = default;
    virtual void integrate(std::vector<Body>&,double) = 0;
    virtual std::string name() const noexcept = 0;
};

#endif