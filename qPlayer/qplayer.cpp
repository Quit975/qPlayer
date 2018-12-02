#include "qplayer.h"

qPlayer::qPlayer()
{
	m_window.buildGUI(m_resourceManager);
	DEBUG("qPlayer created");
}

qPlayer::~qPlayer()
{
	DEBUG("qPlayer destroyed");
}

void qPlayer::run()
{
	while (!m_window.closureRequested()) {
		m_window.processEvents();
		m_window.draw();
	}
}
