#pragma once

#include "core.h"
#include "window.h"
#include "resourceManager.h"
#include "musicPlayer.h"

class qPlayer
{
private:
	gui::Window m_window;
	player::MusicPlayer m_player;
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