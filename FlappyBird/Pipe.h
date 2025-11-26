#pragma once
#include <SFML/Graphics.hpp>
class Pipe {
public:
    Pipe(float x, float gapY, float gapSize, float windowHeight);

    void update(float speed);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBoundsTop() const;
    sf::FloatRect getBoundsBottom() const;

    float getX();
    /*void updatePosTop(float x);
    void updatePosBtm(float x, float gapY, float gapSize);*/
    void updatePosTop(float x, float gapY);
    void updatePosBtm(float x, float gapY, float gapSize, float windowHeight);

private:
    sf::RectangleShape topPipe;
    sf::RectangleShape bottomPipe;

};
