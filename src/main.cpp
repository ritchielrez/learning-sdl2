#include "Game.hpp"
#include <memory>

int main(int argc, char** argv) {
    std::unique_ptr<Game> game = std::make_unique<Game>();
	game->init("Game v1.0", SCREEN_WIDTH, SCREEN_HEIGHT);
	return 0;
}
