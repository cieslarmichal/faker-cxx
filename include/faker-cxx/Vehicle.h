#pragma once

#include <string>

namespace faker{
    class Vehicle{
        public:
        std::string vehicle();

        std::string manufacturer();

        std::string model();

        std::string type();

        std::string fuel();

        std::string vin();

        std::string color();

        std::string vrm();

        std::string bicycle();
    };
}