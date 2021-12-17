#include "src/common/event_handler.h"

namespace evolution
{

void handle_events(sf::Event& event, sf::RenderWindow& window)
{
    constexpr bool verbose{false};
    switch (event.type)
    {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::Resized:
            if (verbose)
            {
                std::cout << "new width: " << event.size.width << std::endl;
                std::cout << "new height: " << event.size.height << std::endl;
            }
            break;
        case sf::Event::LostFocus:
            if (verbose)
            {
                std::cout << "Lost focus" << std::endl;
            }
        case sf::Event::GainedFocus:
            if (verbose)
            {
                std::cout << "Gained focus" << std::endl;
            }
        case sf::Event::KeyPressed:
            if (verbose)
            {
                std::cout << "Key pressed" << static_cast<char>(event.key.code) << std::endl;
                if (event.key.code == sf::Keyboard::Escape)
                {
                    std::cout << "the escape key was pressed" << std::endl;
                    std::cout << "control:" << event.key.control << std::endl;
                    std::cout << "alt:" << event.key.alt << std::endl;
                    std::cout << "shift:" << event.key.shift << std::endl;
                    std::cout << "system:" << event.key.system << std::endl;
                }
            }
            break;
        case sf::Event::MouseWheelScrolled:
            if (verbose)
            {
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
                    std::cout << "wheel type: vertical" << std::endl;
                else if (event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel)
                    std::cout << "wheel type: horizontal" << std::endl;
                else
                    std::cout << "wheel type: unknown" << std::endl;
                std::cout << "wheel movement: " << event.mouseWheelScroll.delta << std::endl;
                std::cout << "mouse x: " << event.mouseWheelScroll.x << std::endl;
                std::cout << "mouse y: " << event.mouseWheelScroll.y << std::endl;
            }
        case sf::Event::MouseButtonPressed:
            if (verbose)
            {
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
            }
        case sf::Event::MouseMoved:
            if (verbose)
            {
                std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
                std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
            }
        case sf::Event::MouseEntered:
            if (verbose)
            {
                std::cout << "the mouse cursor has entered the window" << std::endl;
            }
        case sf::Event::MouseLeft:
            if (verbose)
            {
                std::cout << "the mouse cursor has left the window" << std::endl;
            }
        default:
            break;
    }
}

}  // namespace evolution