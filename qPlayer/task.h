#pragma once
#include "core.h"

enum class Operation
{
	NO_OP
};

class Task
{
private:
	Operation m_op;
	std::string m_details;

public:
	Task(Operation op, std::string detail): m_op{op}, m_details{detail} {}
	Task(Operation op): m_op{op}, m_details{""} {}
	Operation op() { return m_op; }
	std::string details() { return m_details; }
};