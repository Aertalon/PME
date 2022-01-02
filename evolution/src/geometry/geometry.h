#include "src/common/common.h"
#include <cmath>
#include <iostream>
#include <random>

#ifndef EVOLUTION_GEOMETRY_H_
#define EVOLUTION_GEOMETRY_H_

namespace evolution
{
namespace geometry
{
    /// Enumerate the possible 2d rotations
    enum class Rotation
    {
        Clockwise,
        Counterclockwise
    };

    /// A simple 2-d vector class
    class Vector final
    {
        public:

            constexpr Vector() = default;

            constexpr Vector(int x, int y):
                x_{x},
                y_{y}
            {}

        void rotate(Rotation r);
        void rotate(Rotation r, int dist);

        constexpr int x() const { return x_; }
        constexpr int y() const { return y_; }

        private:

            friend std::ostream& operator<<(std::ostream& os, Vector const& v)
            {
                os << "(" << v.x_ << ", " << v.y_ << ")";
                return os;
            }

            friend constexpr bool operator==(Vector const& lhs, Vector const& rhs)
            {
                return (lhs.x_ == rhs.x_) && (lhs.y_ == rhs.y_);
            }

            friend constexpr bool operator!=(Vector const& lhs, Vector const& rhs)
            {
                return !(lhs == rhs);
            }

            int x_{};
            int y_{};
    };

    /// A simple 2-d point class
    class Point final
    {
        public:

            constexpr Point() = default;

            constexpr Point(int x, int y) :
                x_{x},
                y_{y}
            {}

        bool is_valid() const;
        int to_pixel() const;

        Point& operator+=(Vector const& vec);

        void rotate_around(Point const& o, Rotation r);
        void rotate_around(Point const& o, Rotation r, int dist);

        constexpr int x() const { return x_; }
        constexpr int y() const { return y_; }

        private:
            friend std::ostream& operator<<(std::ostream& os, Point const& p)
            {
                os << "(" << p.x_ << ", " << p.y_ << ")";
                return os;
            }

            friend constexpr Point operator+(Point const& p, Vector const& vec)
            {
                Point q{p};
                q.x_ += vec.x();
                q.y_ += vec.y();
                return q;
            }

            friend constexpr Vector operator-(Point const& p1, Point const& p2)
            {
                return Vector{p1.x_ - p2.x_, p1.y_ - p2.y_};
            }

            friend constexpr bool operator==(Point const& lhs, Point const& rhs)
            {
                return (lhs.x_ == rhs.x_) && (lhs.y_ == rhs.y_);
            }

            friend constexpr bool operator!=(Point const& lhs, Point const& rhs)
            {
                return !(lhs == rhs);
            }

            int x_{};
            int y_{};
    };

template<int W, int H>
class PointRandomGenerator final
{
    public:
        PointRandomGenerator() = default;

        Point generate()
        {
            return evolution::geometry::Point(
                width_generator_.generate(),
                height_generator_.generate());
        }

    private:
        IntRandomGenerator<0, W> width_generator_{};
        IntRandomGenerator<0, H> height_generator_{};
};

inline PointRandomGenerator<kWidth, kHeight> point_generator{};

}  // namespace geometry
}  // namespace evolution

#endif // EVOLUTION_GEOMETRY_H_