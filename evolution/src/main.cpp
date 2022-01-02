#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

#include <iostream>
#include <ctime>
#include <random>

#include "src/common/common.h"
#include "src/common/event_handler.h"
#include "src/world/world.h"

int main()
{
    std::random_device rd;  // For some reason needed to visualize stuff

    sf::RenderWindow window(sf::VideoMode(evolution::kWidth, evolution::kHeight), "Test Window");

    sf::Event event;
    sf::Clock clock;

    // For the following, see https://www.sfml-dev.org/tutorials/2.5/window-window.php
    window.setVerticalSyncEnabled(true); // call it once, after creating the window
    window.setFramerateLimit(60); // call it once, after creating the window

    evolution::world::World world{};
    world.initialize();

    bool verbose = false;

    while (window.isOpen())
    {
        clock.restart();

        while (window.pollEvent(event))
        {
            evolution::handle_events(event, window);
        }

        if (world.is_finished())
        {
            world.reset();
        }

        world.step();
        world.draw(window);
        if (verbose) { world.count_trees(); }

        sf::Time elapsed = clock.getElapsedTime();
        if (verbose)
        {
            std::cout << "FPS: " << 1/elapsed.asSeconds() << std::endl;
        }
    }
    return 0;
}