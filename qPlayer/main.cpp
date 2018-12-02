#include "qplayer.h"


int main() {
	try {
		qPlayer player;
		player.run();
	}
	catch (ResourceException& e) {
		std::cerr << e.what() << std::endl;
	}
	

	return 0;
}