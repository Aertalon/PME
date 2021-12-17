#include "src/common/common.h"
#include <cmath>
#include <iostream>

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

            void rotate(Rotation r)
            {
                if (*this == Vector{})
                {
                    return;
                }
                bool const counterclockwise{r == Rotation::Counterclockwise};
                int coeff = counterclockwise ? 1 : -1;

                if (std::abs(x_) > std::abs(y_))
                {
                    y_ += coeff*std::copysign(1, x_);
                }
                else if (std::abs(x_) < std::abs(y_))
                {
                    x_ += -coeff*std::copysign(1, y_);
                }
                else
                {
                    if (((x_*y_  > 0) && !counterclockwise) || ((x_*y_  < 0) && counterclockwise))
                    {
                        y_ += coeff*std::copysign(1, x_);
                    }
                    else
                    {
                        x_ += -coeff*std::copysign(1, y_);
                    }
                }
            }

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



        bool is_valid() const
        {
            return (x_ >= 0) && (x_ < kWidth) && (y_ >= 0) && (y_ < kHeight);
        }

        int to_pixel() const
        {
            return (x_ + y_*kWidth)*kElsPerPixel;
        }

        Point& operator+=(Vector const& vec)
        {
            *this = *this + vec;
            return *this;
        }

        void rotate_around(Point const& o, Rotation r)
        {
            auto v = *this - o;
            std::cout << v << std::endl;
            if (v != Vector{})
            {
                v.rotate(r);
                std::cout << v << std::endl;

                *this = o + v;
            }
        }

        friend std::ostream& operator<<(std::ostream& os, Point const& p)
        {
            os << "(" << p.x_ << ", " << p.y_ << ")";
            return os;
        }

        constexpr int x()
        {
            return x_;
        }

        constexpr int y()
        {
            return y_;
        }

        private:

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

}  // namespace geometry
}  // namespace evolution

#endif // EVOLUTION_GEOMETRY_H_