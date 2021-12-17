#include <random>
#include <iostream>
#include <algorithm>

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

#include "src/common/common.h"
#include "src/geometry/geometry.h"
#include "src/graphics_handler/graphics_handler.h"

#ifndef EVOLUTION_AGENT_H_
#define EVOLUTION_AGENT_H_

namespace evolution
{
namespace agent
{

enum class Actions
{
    Eat,
    MoveForward,
    TurnLeft,
    TurnRight,
};

class Body final
{
    public:

        Body() = default;

        Body(geometry::Point const& head, geometry::Point const& tail) :
            head_{std::move(head)},
            tail_{std::move(tail)}
        {}

    void move(Actions const& a);

    friend std::ostream& operator<<(std::ostream& os, Body const& b)
    {
        os << "Head: " << b.head_ << ", tail: " << b.tail_;
        return os;
    }

    void draw(graphics_handler::GraphicsHandler& gh);

    private:
        geometry::Point head_;
        geometry::Point tail_;
};

class Brain final
{
    Brain () = default;
};

class Agent final
{
    public:
        Agent()
        {
            auto head = geometry::Point{kWidth/2, kHeight/2};
            body_ = Body(head, head + geometry::Vector(1,0));
        }

        void update ();

        void perceive();
        void decide();
        void act();

        void update_world(graphics_handler::GraphicsHandler& gh);

    private:
        Brain brain_{};
        Body body_{};
        Actions action_{};
};

}  // namespace agent
}  // namespace evolution

#endif // EVOLUTION_AGENT_H_