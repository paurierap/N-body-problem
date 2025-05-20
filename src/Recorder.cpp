// Implementation of Recorder

#include "Recorder.hpp"
#include "Body.hpp"
#include <stdexcept>
#include <string>
#include <vector>

Recorder::Recorder(const std::string& filename, std::size_t bodyCount) : file_(filename), bodyCount_(bodyCount)
{
    if (!file_.is_open()) throw std::runtime_error("Could not open file for recording");

    // Write header for output file
    file_ << "# Time";
    for (std::size_t i = 0; i < bodyCount_; ++i) {
        file_ << ", x" << i << ", y" << i;
    }

    file_ << ", Total energy" << '\n';
}
       
void Recorder::record(double time, const std::vector<Body>& bodies)
{
    double E_tot = 0.0;

    file_ << time;
    for (const auto& body : bodies) {
        // Write positions:
        file_ << ", " << body.getPosition()[0] << ", " << body.getPosition()[1];

        // Calculate kinetic energy:
        E_tot += body.kineticEnergy();
    }

    // Calculate potential energy
    for (std::size_t i = 0; i < bodies.size(); ++i) {
        for (std::size_t j = i + 1; j < bodies.size(); ++j) {
            E_tot += bodies[i].potentialEnergy(bodies[j]);
        }
    }

    file_ << ", " << E_tot << '\n';
}