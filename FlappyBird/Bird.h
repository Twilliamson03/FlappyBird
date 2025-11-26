#pragma once
#include <SFML/Graphics.hpp>
#include"Pipe.h"


class Bird {
public:
	Bird(int size);
	void draw(sf::RenderWindow& window);
	void update(float velocity);

	float getPosY();
	float getPosX();
	float getRadius();
	void setPosition(float x, float y);
	bool checkCollision(const Pipe& pipe) const;
private:
	sf::CircleShape bird;
};