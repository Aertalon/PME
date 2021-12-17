#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

#ifndef EVOLUTION_EVENT_HANDLER_H_
#define EVOLUTION_EVENT_HANDLER_H_

namespace evolution
{

void handle_events(sf::Event& event, sf::RenderWindow& window);

}  // namespace evolution

#endif // EVOLUTION_EVENT_HANDLER_H_