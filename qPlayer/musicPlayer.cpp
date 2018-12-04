#include "musicPlayer.h"

player::MusicPlayer::MusicPlayer():
	m_currentSong{m_jukebox.begin()}
{
	populateJukebox();
	DEBUG("MusicPlayer created");
}

player::MusicPlayer::~MusicPlayer()
{
	for (sf::Music* m : m_jukebox) {
		delete m;
	}
	DEBUG("MusicPlayer destroyed");
}

void player::MusicPlayer::play()
{
	(*m_currentSong)->play();
	DEBUG((*m_currentSong)->getDuration().asSeconds());
}

void player::MusicPlayer::stop()
{
	(*m_currentSong)->stop();
}

void player::MusicPlayer::pause()
{
	(*m_currentSong)->pause();
}

void player::MusicPlayer::next()
{
	stop();
	if (m_currentSong == m_jukebox.end() - 1) {
		m_currentSong = m_jukebox.begin();
	} 
	else {
		m_currentSong++;
	}
	play();
}

void player::MusicPlayer::prev()
{
	stop();
	if (m_currentSong == m_jukebox.begin()) {
		m_currentSong = m_jukebox.end() - 1;
	}
	else {
		m_currentSong--;
	}
	play();
}

void player::MusicPlayer::populateJukebox()
{
	for (const std::filesystem::directory_entry& file : std::filesystem::directory_iterator("playlist")) {
		if (file.is_regular_file()) {
			DEBUG(file.path().filename());
			m_jukebox.push_back(new sf::Music());
			m_jukebox.back()->openFromFile(file.path().string());
		}
	}
	m_currentSong = m_jukebox.begin();

	DEBUG("Jukebox populated");
}