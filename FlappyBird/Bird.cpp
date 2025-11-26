#include "Bird.h"
#include <SFML/Graphics.hpp>

Bird::Bird(int size) {
    bird.setRadius(size); // use setRadius for CircleShape
    bird.setFillColor(sf::Color::Yellow);
    bird.setPosition(100, 300);
}

void Bird::draw(sf::RenderWindow& window) {
    window.draw(bird);
}

void Bird::update(float velocity) {
    bird.move(0, velocity);
}

float Bird::getPosY() {
    return bird.getPosition().y;
}

float Bird :: getPosX() {
    return bird.getPosition().x;
}

float Bird::getRadius() {
    return bird.getRadius();
}

void Bird::setPosition(float x, float y) {
    bird.setPosition(x, y);
}

bool Bird::checkCollision(const Pipe& pipe) const {
    return bird.getGlobalBounds().intersects(pipe.getBoundsTop()) ||
        bird.getGlobalBounds().intersects(pipe.getBoundsBottom());
}
