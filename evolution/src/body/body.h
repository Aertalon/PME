#include "src/common/common.h"
#include "src/geometry/geometry.h"
#include "src/graphics_handler/graphics_handler.h"

#ifndef EVOLUTION_BODY_H_
#define EVOLUTION_BODY_H_

namespace evolution
{

namespace agent
{
// Forward declaration
class Agent;
class Tree;
} // agent

namespace body
{

template<class BodyOwner>
class Body {};

template <>
class Body<agent::Agent>
{
    public:

        Body() = default;

        Body(geometry::Point const& head, geometry::Point const& tail, int const& length) :
            head_{head},
            tail_{tail},
            length_{length}
        {}

    void move(Actions const& a);

    friend std::ostream& operator<<(std::ostream& os, Body const& b)
    {
        os << "Head: " << b.head_ << ", tail: " << b.tail_;
        return os;
    }

    void draw(graphics_handler::GraphicsHandler& gh) const;

    geometry::Point head() const { return head_; }
    geometry::Point tail() const { return tail_; }

    private:
        geometry::Point head_{};
        geometry::Point tail_{};
        int length_{};
};

template <>
class Body<agent::Tree>
{
    public:

        Body() = default;

        Body(geometry::Point const& position, int const& length) :
            position_{position},
            length_{length}
        {}

    friend std::ostream& operator<<(std::ostream& os, Body const& b)
    {
        os << "Position: " << b.position_;
        return os;
    }

    void draw(graphics_handler::GraphicsHandler& gh) const;

    geometry::Point position() const { return position_; }

    private:
        geometry::Point position_{};
        int length_{};
};


}  // namespace body
}  // namespace evolution

#endif // EVOLUTION_AGENT_H_