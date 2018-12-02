#pragma once

#include "core.h"
#include "window.h"
#include "resourceManager.h"

class qPlayer
{
private:
	gui::Window m_window;
	ResourceManager m_resourceManager; 

public:
	qPlayer();
	~qPlayer();

	//public interface
	void run();
};