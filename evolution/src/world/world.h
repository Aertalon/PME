#include <vector>
#include "src/agent/agent.h"
#include "src/common/common.h"

#ifndef EVOLUTION_WORLD_H_
#define EVOLUTION_WORLD_H_

namespace evolution
{
namespace world
{

class World
{
    private:
        evolution::graphics_handler::GraphicsHandler graphic_handler_{};
        std::vector<evolution::agent::Agent> agents_;
        std::vector<evolution::agent::Tree> trees_;

        int num_agents_{300};
        int num_trees_{1000};

        int sample_freq_{10};
        int samples_{0};
        int max_samples_{300};

        int generation_{};

    public:
        World() = default;

        void initialize_agents()
        {
            agents_.clear();
            for (int i{0}; i < num_agents_+1; i++)
                agents_.push_back(evolution::agent::Agent());
        }

        void create_new_generation_of_agents()
        {
            std::vector<evolution::agent::Agent> remaining_agents;
            for (auto& a: agents_)
            {
                if (a.is_alive())
                {
                    remaining_agents.push_back(a);
                }
            }

            std::cout << "Generation " << generation_ << "; Number of remaining agents: " << remaining_agents.size() << std::endl;

            std::random_device rd;
            std::mt19937 random_generator(rd());
            std::uniform_int_distribution<> distrib(0, remaining_agents.size() - 1);

            for (auto& a: agents_)
            {
                if (!a.is_alive())
                {
                    int selected_previous = distrib(random_generator);
                    a = evolution::agent::Agent(remaining_agents[selected_previous]);
                }
            }
        }

        void initialize_trees()
        {
            trees_.clear();
            for (int i{0}; i < num_trees_+1; i++)
                trees_.push_back(evolution::agent::Tree());
        }

        void initialize()
        {
            initialize_agents();
            initialize_trees();
            samples_ = 0;
        }

        void reset()
        {
            remove_in_dangerous_zone();
            create_new_generation_of_agents();
            initialize_trees();
            generation_++;
            samples_ = 0;
        }

        void step()
        {
            for (auto& a: agents_)
            {
                a.update(trees_);
            }
            samples_++;
        }

        void draw(sf::RenderWindow& window)
        {
            if (samples_ % sample_freq_ == 0)
            {
                graphic_handler_.reset();

                for (auto& t: trees_)
                {
                    t.update_world(graphic_handler_);
                }

                for (auto& a: agents_)
                {
                    a.update_world(graphic_handler_);
                }

                graphic_handler_.draw(window);
            }
        }

        bool is_finished() const { return samples_ >= max_samples_; }

        void remove_in_dangerous_zone()
        {
            for (auto& a: agents_)
            {
                std::cout << a << std::endl;
                if ((a.head().x() >= kWidth / 4) &&  (a.head().x() <= 3*kWidth / 4))
                {
                    a.dies();
                }
            }
        }

        void count_trees() const
        {
            int trees_alive = std::accumulate(
                trees_.begin(),
                trees_.end(),
                0,
                [](int init, evolution::agent::Tree const& t) -> int
                {
                    if (t.is_alive()) { init++; }
                    return init;
                }
            );
            std::cout << "Trees alive: " << trees_alive << std::endl;
        }
};


}  // namespace world
}  // namespace evolution

#endif // EVOLUTION_WORLD_H_