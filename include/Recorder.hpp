#ifndef RECORDER_HPP
#define RECORDER_HPP

#include "Vector2D.hpp"
#include "Body.hpp"
#include <fstream>
#include <string>

// Recorder interface:

class Recorder {
    private:
        std::ofstream file_;
        int bodyCount_;
    public:
        Recorder(const std::string& filename, int bodyCount);
        ~Recorder();
    
        void record(double time, const std::vector<Body>& bodies);
};

#endif