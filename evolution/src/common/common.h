#include <random>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <array>

#ifndef EVOLUTION_COMMON_H_
#define EVOLUTION_COMMON_H_

namespace evolution
{

constexpr int kWidth{800};
constexpr int kHeight{600};
constexpr int kElsPerPixel{4};

constexpr int kTotal{kWidth * kHeight * kElsPerPixel};

enum class Actions
{
    Eat,
    MoveForward,
    TurnLeft,
    TurnRight,
};

template<int Min, int Max>
class IntRandomGenerator final
{
    public:
        IntRandomGenerator() :
            random_generator_(rd_()),
            distrib_(std::uniform_int_distribution<>(Min, Max))
        {}

        int generate() { return distrib_(random_generator_); }

    private:
        std::random_device rd_;
        std::mt19937 random_generator_;
        std::uniform_int_distribution<int> distrib_;
};

Actions generate_random_action();
}  // namespace evolution

#endif // EVOLUTION_COMMON_H_