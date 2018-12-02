#pragma once

#include "core.h"
#include "window.h"
#include "resourceManager.h"

class qPlayer
{
private:
	gui::Window m_window;
	ResourceManager m_resourceManager; 

	//private interface
	void update();

	//flags
	bool m_running;

public:
	qPlayer();
	~qPlayer();

	//public interface
	void run();
};