#include <iostream>
#include <algorithm>
#include <array>
#include <variant>

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

#include "src/body/body.h"
#include "src/brain/brain.h"
#include "src/common/common.h"
#include "src/geometry/geometry.h"
#include "src/graphics_handler/graphics_handler.h"

#ifndef EVOLUTION_AGENT_H_
#define EVOLUTION_AGENT_H_

namespace evolution
{
namespace agent
{

template<class Self>
class Entity
{
    public:
        Self& self() { return static_cast<Self&>(*this); }

        void update() {};

        void update_world(graphics_handler::GraphicsHandler& gh)
        {
            if (is_alive())
            {
                body_.draw(gh);
            }
        }

        bool is_alive() const { return is_alive_; }
        void dies() { is_alive_ = false; }

    protected:
        body::Body<Self> body_{};

    private:
        bool is_alive_{true};
};

struct PerceivedInformation
{
        Agent* agent_at_location{};
        Tree* tree_at_location{};
        std::array<int, 4> surrounding_agents{};
        std::array<int, 4> surrounding_trees{};
        geometry::Vector direction{};
};

class AgentPerception
{
    public:
        AgentPerception() = default;

        void set_perception(
            geometry::Point const& head,
            geometry::Point const& tail,
            std::vector<evolution::agent::Tree>& trees);

        PerceivedInformation get_perceived_info() const { return info_; }

        std::array<int, 6> to_array() const
        {
            return {
                info_.surrounding_trees[0],
                info_.surrounding_trees[1],
                info_.surrounding_trees[2],
                info_.surrounding_trees[3],
                info_.direction.x(),
                info_.direction.y()};
        }

    private:
        PerceivedInformation info_{};
};

class Agent : public Entity<Agent>
{
    static constexpr int length_{2};
    public:
        Agent()
        {
            auto head = geometry::point_generator.generate();
            this->body_ = body::Body<Agent>(head, head + geometry::Vector(length_, 0), length_);
        }

        Agent(Agent const& mother) : Agent()
        {
            brain_ = brain::Brain(mother.get_brain());
        }

        void update(std::vector<evolution::agent::Tree>& trees)
        {
            if (is_alive())
            {
                perceive(trees);
                decide();
                act();

                energy_--;
                if (energy_ == 0)
                {
                    dies();
                }
            }
        }

        void perceive(std::vector<evolution::agent::Tree>& trees);
        void decide();
        void act();

        brain::Brain get_brain() const  { return brain_; }

        geometry::Point head() const { return this->body_.head(); }

    private:

        friend std::ostream& operator<<(std::ostream& os, Agent const& a)
        {
            os << "Agent with head at ";
            os << a.head();
            if (a.is_alive())
            {
                os << " is alive";
            }
            else
            {
                os << " is dead";
            }
            return os;
        }

        brain::Brain brain_{};
        Actions action_{};
        AgentPerception perception_{};

        int energy_{500};
};

class Tree : public Entity<Tree>
{
    public:
        Tree()
        {
            this->body_ = body::Body<Tree>(
                geometry::point_generator.generate(), 2);
        }

    geometry::Point position() { return this->body_.position(); }
};

}  // namespace agent
}  // namespace evolution

#endif // EVOLUTION_AGENT_H_