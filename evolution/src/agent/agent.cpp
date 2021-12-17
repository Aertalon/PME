#include "src/agent/agent.h"


namespace
{
std::random_device action_rd;
std::mt19937 action_gen(action_rd());
std::uniform_int_distribution<> action_distrib(1, 4);

using Actions = evolution::agent::Actions;
Actions generate_random_action()
{
    return static_cast<Actions>(action_distrib(action_gen));
}

}

namespace evolution
{
namespace agent
{

void Body::move(Actions const& a)
{
    if (a == Actions::MoveForward)
    {
        auto dir = head_ - tail_;
        head_ += dir;
        tail_ += dir;
    }
    else if (a == Actions::TurnLeft)
    {
        head_.rotate_around(tail_, geometry::Rotation::Counterclockwise);
    }
    else if (a == Actions::TurnRight)
    {
        head_.rotate_around(tail_, geometry::Rotation::Clockwise);
    }
    else
    {
        // Other actions are not movements
    }
}

void Body::draw(graphics_handler::GraphicsHandler& gh)
{
    constexpr int h{50};

    for(int j{-h}; j < h+1; j++)
    {
        for(int i{-h}; i < h+1; i++)
        {
            gh.set_pixel(
                geometry::Point{tail_.x() + j, kHeight - tail_.y() + i}, sf::Color::Blue);
            gh.set_pixel(
                geometry::Point{head_.x() + j, kHeight - head_.y() + i}, sf::Color::Red);
        }
    }
}


void Agent::update()
{
    perceive();
    decide();
    act();
}

void Agent::perceive()
{}

void Agent::decide ()
{
    action_ = generate_random_action();
    std::cout << static_cast<int>(action_) << std::endl;
}

void Agent::update_world(graphics_handler::GraphicsHandler& gh)
{
    body_.draw(gh);
}

void Agent::act()
{
    body_.move(action_);

    std::cout << "Agent's body position: ";
    std::cout << body_ << std::endl;
}

}  // namespace agent
}  // namespace evolution