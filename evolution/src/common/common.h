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
}  // namespace evolution

#endif // EVOLUTION_COMMON_H_