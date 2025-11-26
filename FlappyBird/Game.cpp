#include "Game.h"
#include <iostream>
#include <cstdlib> // for rand()

Game::Game(int windowWidth, int windowHeight)
    : window(sf::VideoMode(windowWidth, windowHeight), "Flappy Bird"),
    bird(20),
    gap(200),
    px(windowWidth),
    py(rand() % static_cast<int>(windowHeight - gap - 200) + 100),
    pipe(px, py, gap, windowHeight),
    velocity(0),
    gravity(0.25f),
    jumpStrength(-6.5f),
    maxFallSpeed(10.0f),
    score(0),
    windowWidth(windowWidth),
    windowHeight(windowHeight)
{
    std::cout << "Game started. Score: " << score << std::endl;
}

void Game::run() {
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        processEvents();
        update(dt);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
            velocity = jumpStrength; // Jump
        }
    }
}

void Game::update(float dt) {
    // Physics
    velocity += gravity * dt * 60;
    if (velocity > maxFallSpeed)
        velocity = maxFallSpeed;

    bird.update(velocity * dt * 60);

    // Ground collision
    if (bird.getPosY() + bird.getRadius() * 2 > windowHeight) {
        bird.setPosition(bird.getPosX(), windowHeight - bird.getRadius() * 2);
        velocity = 0;
    }

    // Ceiling collision
    if (bird.getPosY() < 0) {
        bird.setPosition(bird.getPosX(), 0);
        velocity = 0;
    }

    // Pipe reset
    if (pipe.getX() < 0) {
        score++;
        std::cout << "Score: " << score << std::endl;

        py = rand() % static_cast<int>(windowHeight - gap - 200) + 100;
        pipe.updatePosTop(px,py);              // reset top pipe
        pipe.updatePosBtm(px, py, gap,windowHeight);     // reset bottom pipe
    }

    // Collision check
    if (bird.checkCollision(pipe)) {
        std::cout << "Collision! Final Score: " << score << std::endl;
        window.close();
    }

    // Pipe movement
    pipe.update(200 * dt);
}

void Game::render() {
    window.clear(sf::Color::Cyan);
    bird.draw(window);
    pipe.draw(window); // draws both top and bottom pipes
    window.display();
}