#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

#include <iostream>
#include <ctime>
#include "person/person.h"
#include "job/job.h"
#include "resource/resource.h"


int main()
{
    sf::Window window;
    window.create(sf::VideoMode(1000, 1000), "SFML works!", sf::Style::Default);
    // For the following, see https://www.sfml-dev.org/tutorials/2.5/window-window.php
    window.setVerticalSyncEnabled(true); // call it once, after creating the window
    window.setFramerateLimit(60); // call it once, after creating the window

    Person<Farmer> farmer1{"Marez"};
    Person<Farmer> farmer2{"Anna"};

    Person<Smith> smith1{"Cicciobello"};
    Person<Smith> smith2{"Baxter"};

    run_life(farmer1, farmer2);


    sf::Clock clock;

    while (window.isOpen())
    {
        //sf::Time elapsed = clock.restart();
        //std::cout << "Elapsed seconds: " << elapsed.asSeconds() << std::endl;

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    std::cout << "new width: " << event.size.width << std::endl;
                    std::cout << "new height: " << event.size.height << std::endl;
                    break;
                case sf::Event::LostFocus:
                    std::cout << "Lost focus" << std::endl;
                case sf::Event::GainedFocus:
                    std::cout << "Gained focus" << std::endl;
                case sf::Event::KeyPressed:
                    std::cout << "Key pressed" << static_cast<char>(event.key.code) << std::endl;
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        std::cout << "the escape key was pressed" << std::endl;
                        std::cout << "control:" << event.key.control << std::endl;
                        std::cout << "alt:" << event.key.alt << std::endl;
                        std::cout << "shift:" << event.key.shift << std::endl;
                        std::cout << "system:" << event.key.system << std::endl;
                    }
                    break;
                case sf::Event::MouseWheelScrolled:
                    if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
                        std::cout << "wheel type: vertical" << std::endl;
                    else if (event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel)
                        std::cout << "wheel type: horizontal" << std::endl;
                    else
                        std::cout << "wheel type: unknown" << std::endl;
                    std::cout << "wheel movement: " << event.mouseWheelScroll.delta << std::endl;
                    std::cout << "mouse x: " << event.mouseWheelScroll.x << std::endl;
                    std::cout << "mouse y: " << event.mouseWheelScroll.y << std::endl;
                case sf::Event::MouseButtonPressed:
                    switch (event.mouseButton.button)
                    {
                        case sf::Mouse::Right:
                            std::cout << "the right button was pressed" << std::endl;
                            break;
                        case sf::Mouse::Left:
                            std::cout << "the left button was pressed" << std::endl;
                            break;
                        case sf::Mouse::Middle:
                            std::cout << "the center button was pressed" << std::endl;
                            break;
                        default:
                            break;
                    }
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                case sf::Event::MouseMoved:
                    std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
                    std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
                case sf::Event::MouseEntered:
                    std::cout << "the mouse cursor has entered the window" << std::endl;
                case sf::Event::MouseLeft:
                    std::cout << "the mouse cursor has left the window" << std::endl;
                default:
                    break;
            }
        }

        sf::sleep(sf::seconds(.2));


    }
    return 0;
}