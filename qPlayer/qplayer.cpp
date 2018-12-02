#include "qplayer.h"

qPlayer::qPlayer():
	m_running{true}
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
	while (m_running) {
		m_window.processEvents();
		update();
		m_window.draw();
	}

	m_window.close();
}

void qPlayer::update()
{
	Task e = m_window.update();

	if (e.op() == Operation::NO_OP) {
		return;
	}

	switch (e.op()) {
	case Operation::PLAY:
		DEBUG("Play button pressed");
		break;

	case Operation::PAUSE:
		DEBUG("Pause button pressed");
		break;

	case Operation::STOP:
		DEBUG("Stop button pressed");
		break;

	case Operation::PREV:
		DEBUG("Prev button pressed");
		break;

	case Operation::NEXT:
		DEBUG("Next button pressed");
		break;

	case Operation::CLOSE:
		DEBUG("Pause button pressed");
		m_running = false;
		break;

	case Operation::SEEK:
		DEBUG("Seek");
		break;
	}
}