#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

#include <iostream>
#include <ctime>
#include "person/person.h"
#include "job/job.h"
#include "resource/resource.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");

    Person<Farmer> farmer1{"a"};
    Person<Farmer> farmer2{"b"};

    Person<Smith> smith1{"c"};
    Person<Smith> smith2{"d"};

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::sleep(sf::seconds(.2));

    std::cout << "Here " << std::endl;

    }
    return 0;
}