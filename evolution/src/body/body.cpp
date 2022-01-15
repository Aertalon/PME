#include "body.h"

namespace evolution
{
namespace body
{

void Body<agent::Agent>::move(Actions const& a)
{
    if (a == Actions::MoveForward)
    {
        auto dir = head_ - tail_;
        auto new_head = head_ + dir;
        if (new_head.is_valid())
        {
            head_ += dir;
            tail_ += dir;
        }
    }
    else if (a == Actions::TurnLeft)
    {
        head_.rotate_around(tail_, geometry::Rotation::Counterclockwise, length_);
    }
    else if (a == Actions::TurnRight)
    {
        head_.rotate_around(tail_, geometry::Rotation::Clockwise, length_);
    }
    else
    {
        // Other actions are not movements
    }
}

void Body<agent::Agent>::draw(graphics_handler::GraphicsHandler& gh) const
{
    gh.set_square(tail_, length_, sf::Color::Red);
    gh.set_square(head_, length_, sf::Color::Blue);
}

void Body<agent::Tree>::draw(graphics_handler::GraphicsHandler& gh) const
{
    gh.set_square(position_, length_, sf::Color::Green);
}

}  // namespace body
}  // namespace evolution
