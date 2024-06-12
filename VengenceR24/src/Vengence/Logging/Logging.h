#pragma once

#include <iostream>
#include "Time.h"

extern const char* white;
extern const char* lime;
extern const char* grey;
extern const char* red;
extern const char* cyan;
extern const char* yellow;

namespace vLogging {

    template<typename T, typename... Args>
    void info(T first, Args... args)
    {
        std::cout << grey << "[" << white << vget_fmt_time() << cyan << "  INFO" << grey << "] " << white;

        std::cout << first << ' ';
        (std::cout << ... << args) << white << std::endl;
    }

    template<typename T, typename... Args>
    void error(T first, Args... args)
    {
        std::cout << grey << "[" << white << vget_fmt_time() << red << "  ERROR" << grey << "] " << white;

        std::cout << first << ' ';
        (std::cout << ... << args) << white << std::endl;
    }

}
