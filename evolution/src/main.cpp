#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

#include <iostream>
#include <ctime>

#include <random>

#include "src/common/common.h"
#include "src/common/event_handler.h"
#include "src/agent/agent.h"
#include "src/graphics_handler/graphics_handler.h"

int main()
{

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(0, 255);

    sf::RenderWindow window(sf::VideoMode(evolution::kWidth, evolution::kHeight), "Test Window");
    evolution::graphics_handler::GraphicsHandler graphic_handler{};

    sf::Event event;

    // For the following, see https://www.sfml-dev.org/tutorials/2.5/window-window.php
    window.setVerticalSyncEnabled(true); // call it once, after creating the window
    window.setFramerateLimit(60); // call it once, after creating the window

    evolution::agent::Agent agent{};
    graphic_handler.reset();

    agent.update();
    agent.update_world(graphic_handler);

    graphic_handler.draw(window);


    while (window.isOpen())
    {

        sf::Clock clock;
        //sf::Time elapsed = clock.restart();
        //std::cout << "Elapsed seconds: " << elapsed.asSeconds() << std::endl;

        while (window.pollEvent(event))
        {
            evolution::handle_events(event, window);
            graphic_handler.reset();

            agent.update();
            agent.update_world(graphic_handler);

            graphic_handler.draw(window);
        }

        sf::sleep(sf::seconds(.2));


    }
    return 0;
}