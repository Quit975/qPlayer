#include "qplayer.h"

qPlayer::qPlayer()
{
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
