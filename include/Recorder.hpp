#ifndef RECORDER_HPP
#define RECORDER_HPP

#include "Vector2D.hpp"
#include "Body.hpp"
#include <cstddef>
#include <fstream>
#include <string>

// Recorder interface:

class Recorder {
    private:
        std::ofstream file_;
        std::size_t bodyCount_;

    public:
        // Constructor
        Recorder(const std::string& filename, std::size_t bodyCount);

        // Default destructor (std::ofstream is RAII)
        ~Recorder() = default;

        // Make class uncopyable:
        Recorder(const Recorder&) = delete;
        Recorder& operator=(const Recorder&) = delete;

        // Make moveable:
        Recorder(Recorder&&) = default;
        Recorder& operator=(Recorder&&) = default;

        void record(double time, const std::vector<Body>& bodies);
};

#endif