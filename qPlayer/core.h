#pragma once
#include <SFML/System.hpp>
/*
Core header defining debug values, debug utils, errors, exceptions, etc.
qPlayer
*/

#include <iostream>
#include <stdexcept>
#include <string>

#ifndef NDEBUG
#define DEBUG(x) do {std::cout << x << std::endl;} while (false)
const bool debugMode = true;
#else
#define DEBUG(x)
const bool debugMode = false;
#endif // NDEBUG

#define LOG(x) do {std::cout << x << std::endl;} while (false)
#define FAIL(x) do {std::cerr << "Op failed: " << x << std::endl;} while (false)
#define ERR(x) do {std::cerr << "[" << __FILE__ << "][" << __FUNCTION__ << "][Line " << __LINE__ << "] " << x << std::endl;} while (false)

/////////////////////////////////// EVENT HANDLING
enum class Event
{
	NO_OP,
	CLOSE,
	LEFT_PRESS,
	LEFT_RELEASE,
	RIGHT_PRESS,
	RIGHT_RELEASE
};

enum class Operation
{
	NO_OP,
	PLAY,
	STOP,
	PAUSE,
	PREV,
	NEXT,
	CLOSE,
	SEEK
};

/////////////////////////////////// EXCEPTIONS
class ResourceException : public std::runtime_error {
public:
	ResourceException(const std::string& msg):
		std::runtime_error(msg)
	{}

	ResourceException(const char * msg):
		std::runtime_error(msg)
	{}
};

class EventException : public std::logic_error {
public:
	EventException(const std::string& msg) :
		std::logic_error(msg)
	{}

	EventException(const char * msg) :
		std::logic_error(msg)
	{}
};

////////////////////////////////// RESOURCE ENUMS
enum class Sprite {
	PLAY_BUTTON,
	STOP_BUTTON,
	PAUSE_BUTTON,
	PREV_BUTTON,
	NEXT_BUTTON,
	VOL_SLIDER,
	DISPLAY_BKGD
};