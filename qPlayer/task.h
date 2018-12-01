#pragma once
#include "core.h"

class Task
{
private:
	Operation m_op;
	union {
		std::string m_string;
		float m_float;
	};
	

public:
	Task(Operation op, std::string detail): m_op{op}, m_string{detail} {}
	Task(Operation op, float num) : m_op{ op }, m_float{ num } {}
	Task(Operation op): m_op{op} {}
	Operation op() { return m_op; }
	std::string desc() { return m_string; }
	float num() { return m_float; }
};