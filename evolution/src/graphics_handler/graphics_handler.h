#include <SFML/Graphics.hpp>
#include <array>

#include "src/common/common.h"
#include "src/geometry/geometry.h"

#ifndef EVOLUTION_GRAPHICS_HANDLER_H_
#define EVOLUTION_GRAPHICS_HANDLER_H_

namespace evolution
{
namespace graphics_handler
{

class GraphicsHandler
{
    public:
        using data_type = std::array<sf::Uint8, kTotal>;

        GraphicsHandler()
        {
            texture_.create(kWidth, kHeight);
            sprite_.setTexture(texture_);
        };

        void reset()
        {
            pixels_.fill(sf::Uint8(255));
        }

        void set_pixel(geometry::Point const& p, sf::Color color)
        {
            if (p.is_valid())
            {
                pixels_.at(p.to_pixel() + 0) = color.r;
                pixels_.at(p.to_pixel() + 1) = color.g;
                pixels_.at(p.to_pixel() + 2) = color.b;
                pixels_.at(p.to_pixel() + 3) = color.a;
            }
        }

        void draw(sf::RenderWindow& window)
        {
            texture_.update(pixels_.data());

            window.draw(sprite_);
            window.display();
        }


        data_type get_data()
        {
            return pixels_;
        }

    private:
        data_type pixels_{};
        sf::Texture texture_;
        sf::Sprite sprite_;

};

}  // namespace graphics_handler
}  // namespace evolution

#endif // EVOLUTION_GRAPHICS_HANDLER_H_