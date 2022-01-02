#include "src/agent/agent.h"

namespace evolution
{
namespace agent
{

void AgentPerception::set_perception(
    geometry::Point const& head,
    geometry::Point const& tail,
    std::vector<evolution::agent::Tree>& trees)
{
    info_.surrounding_trees.fill(0);
    info_.tree_at_location = nullptr;

    info_.direction = head - tail;
    auto front = head + info_.direction;
    auto front_left = head + info_.direction;
    front_left.rotate_around(head, geometry::Rotation::Counterclockwise);
    auto front_right = head + info_.direction;
    front_right.rotate_around(head, geometry::Rotation::Clockwise);

    for (auto& t: trees)
    {
        if (t.is_alive())
        {
            if (t.position() == head)
            {
                info_.tree_at_location = &t;
                info_.surrounding_trees[0] = 1;
            }

            if (t.position() == front)
            {
                info_.surrounding_trees[1] = 1;
            }

            if (t.position() == front_left)
            {
                info_.surrounding_trees[2] = 1;
            }

            if (t.position() == front_right)
            {
                info_.surrounding_trees[3] = 1;
            }
        }
    }
}

void Agent::perceive(std::vector<evolution::agent::Tree>& trees)
{
    perception_.set_perception(
        this->body_.head(),
        this->body_.tail(),
        trees);
}

void Agent::decide()
{
    action_ = brain_.decide(perception_.to_array());
}

void Agent::act()
{
    body_.move(action_);
    if (action_ == Actions::Eat)
    {
        if (perception_.get_perceived_info().tree_at_location != nullptr)
        {
            perception_.get_perceived_info().tree_at_location->dies();
            energy_ += 20;
        }
    }
}

}  // namespace agent
}  // namespace evolution