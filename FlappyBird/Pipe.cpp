#include "Pipe.h"
#include<iostream>
#include <SFML/Graphics.hpp>
//#include "Windows.h"

Pipe::Pipe(float x, float gapY, float gapSize, float windowHeight) {
    // Top pipe
    topPipe.setSize(sf::Vector2f(80, gapY));
    topPipe.setFillColor(sf::Color::Green);
    topPipe.setPosition(x, 0);

    // Bottom pipe
    float bottomHeight = windowHeight - (gapY + gapSize);

    bottomPipe.setSize(sf::Vector2f(80, bottomHeight));
    bottomPipe.setFillColor(sf::Color::Green);
    bottomPipe.setPosition(x, gapY + gapSize);

}

void Pipe::update(float speed) {
    topPipe.move(-speed, 0);
    bottomPipe.move(-speed, 0);

}

void Pipe::draw(sf::RenderWindow& window) {
    window.draw(topPipe);
    window.draw(bottomPipe);
}

sf::FloatRect Pipe::getBoundsTop() const {
    return topPipe.getGlobalBounds();
}

sf::FloatRect Pipe::getBoundsBottom() const {
    return bottomPipe.getGlobalBounds();
}

float Pipe::getX() {
    return topPipe.getPosition().x;
}


void Pipe::updatePosTop(float x, float gapY) {
    topPipe.setSize(sf::Vector2f(80, gapY));
    topPipe.setPosition(x, 0);
}

void Pipe::updatePosBtm(float x, float gapY, float gapSize, float windowHeight) {
    float bottomHeight = windowHeight - (gapY + gapSize);
    bottomPipe.setSize(sf::Vector2f(80, bottomHeight));
    bottomPipe.setPosition(x, gapY + gapSize);
}

//void Pipe::updatePosTop(float x) {
//   
//    topPipe.setPosition(x, 0);
//}
//
//void Pipe::updatePosBtm(float x, float gapY, float gapSize) {
//    
//    bottomPipe.setPosition(x, gapY + gapSize);
//}





