#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Bird.h"
#include "Pipe.h"

class Game {
public:
    Game(int windowWidth, int windowHeight);
    void run();

private:
    void processEvents();
    void update(float dt);
    void render();

    sf::RenderWindow window;
    sf::Clock clock;

    Bird bird;
    Pipe pipe;

    float windowWidth;
    float windowHeight;

    float velocity;
    const float gravity;
    const float jumpStrength;
    const float maxFallSpeed;

    int score;

    int gap;
    int px;
    int py;
};

#endif