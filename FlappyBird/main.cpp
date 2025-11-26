#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>
//#include "Windows.h"
#include "Game.h"
#include"Bird.h"
#include "Pipe.h"

using namespace std;

/*
Something I would Like to point out, this is my first time using SFML for graphics
therefor AI was used to help with this aspect.

TO DO LIST:
-Scoreing: As of 26/11/2025 i have spent 3 hours trying to get text on the screen to
           display a score and it doesnt work, Because im making this using My oneDrive
           as my filing system and then later uploading it to git, the scoring system
           is becoming something i can only dream about. NOTE TO SELF- ALWAYS START ON GIT


FIXED LIST:

-Frames:   As this isnt running on a game engine and i am not handeling each frame on their own
           the game is rather "jumpy" for lack of better words, This needs fixed

           Fixed by using a clock to get CPU timings so it runs smoothly on all devices Hopefully
           (Delta Time Logic) Found it on google, it works so happy days :)

-Flight:   The bird does fly but not very well, i need to adjust the strenght of each jump

            Fixed: adjusted the gravity and the jumpstrenght now the bird glides/flys 
            Its a nicer play so im happy

*/
 int main() {
     //Porting over to game.ccp and game.h
     Game game(800, 600);
     game.run();

     
        return 0;
 }

 //This is the code to be ported over, Honestly i know its bad practice to keep it but its 
 //like a memory of all my hard work so :)
 static void hold() {
    float const windowHeight = 600;
    float const windowWidth = 800;

    int score = 0;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Flappy Bird");

    // Bird setup
    Bird bird(20);

    // Create a pipe
    int gap = 250;
    int px = 800;
    int py = rand() % static_cast<int>(windowHeight - gap - 200) + 100;
    Pipe pipe(px, py, gap,windowHeight); // x=600, gap at y=200, gap size=150


    float velocity = 0;
    const float gravity = 0.007f;
    const float jumpStrength = -1.0f;
    cout << "General Test" << endl;


    sf::Clock clock;  // declare before the loop

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {  //  Correct usage
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                velocity = jumpStrength; // Jump
            }
        }

        // Physics
        const float maxFallSpeed = 0.05f; // maximum downward speed
        velocity += gravity;

        // Clamp velocity so the bird falls slowly
        if (velocity > maxFallSpeed)
            velocity = maxFallSpeed;

        bird.update(velocity);



        // Ground collision
        if (bird.getPosY() + bird.getRadius() * 2 > window.getSize().y) {
            bird.setPosition(bird.getPosX(), window.getSize().y - bird.getRadius() * 2);
            velocity = 0; // Stop falling
        }

        // Celling Collision
        if (bird.getPosY() < 0) {
            bird.setPosition(bird.getPosX(), 0);
            velocity = 0; // stop upward movement

        }
        //Pipe reset
        if (pipe.getX() < 0) {
            //cout << "Pipe Reset"<<endl;
            pipe.updatePosTop(px,gap);
            pipe.updatePosBtm(px, py, gap,windowHeight);
        }
        //Did bird hit pipe??
        if (bird.checkCollision(pipe)) {
            cout << "Collision" << endl;
            //Trigger end of Game
            window.close();
        }

        //Render
        pipe.update(200 * dt); // 200 pixels per second
        window.clear(sf::Color::Cyan);
        bird.draw(window);
        pipe.draw(window);
        window.display();

        //Get new Gap Positoion
        py = rand() % static_cast<int>(windowHeight - gap - 200) + 100;
    }

    //return 0;
}