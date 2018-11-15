#pragma once

#include "core.h"
#include "window.h"

class qPlayer
{
private:
	gui::Window m_window;

public:
	qPlayer();
	~qPlayer();

	//public interface
	void run();
};