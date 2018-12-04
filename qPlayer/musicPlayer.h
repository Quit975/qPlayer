#pragma once
#include "core.h"
#include <SFML/Audio.hpp>
#include <vector>
#include <filesystem>

namespace player {
	class MusicPlayer
	{
	private:
		std::vector<std::string> m_playlist;

		std::vector<sf::Music*> m_jukebox;
		std::vector<sf::Music*>::iterator m_currentSong;

		//flags
		bool m_isPlaying;

		//private interface
		void populateJukebox();

	public:
		MusicPlayer();
		~MusicPlayer();

		void play();
		void stop();
		void pause();
		void next();
		void prev();
	};
}

