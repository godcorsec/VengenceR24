#pragma once

#include <iostream>
#include "Time.h"

const char* white = "\x1b[38;2;255;255;255m";
const char* lime = "\x1b[38;2;0;255;0m";
const char* grey = "\x1b[38;2;75;75;75m";
const char* red = "\x1b[38;2;196;12;27m";
const char* cyan = "\x1b[38;2;3;215;252m";
const char* yellow = "\x1b[38;2;196;193;12m";

namespace vLogging {

	template<typename T, typename... Args>
	void info(T first, Args... args)
	{
		std::cout << grey << "[" << white << vget_fmt_time() << cyan << "  INFO" <<grey << "] " << white;


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