#include "geometry.h"

namespace evolution
{
namespace geometry
{

void Vector::rotate(Rotation r)
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

void Vector::rotate(Rotation r, int dist)
{
    while(dist --> 0)
    {
        rotate(r);
    }
}

bool Point::is_valid() const
{
    return (x_ >= 0) && (x_ < kWidth) && (y_ >= 0) && (y_ < kHeight);
}

int Point::to_pixel() const
{
    return (x_ + y_*kWidth)*kElsPerPixel;
}

Point& Point::operator+=(Vector const& vec)
{
    *this = *this + vec;
    return *this;
}

void Point::rotate_around(Point const& o, Rotation r)
{
    rotate_around(o, r, 1);
}

void Point::rotate_around(Point const& o, Rotation r, int dist)
{
    auto v = *this - o;
    if (v != Vector{})
    {
        v.rotate(r, dist);
        *this = o + v;
    }
}

}  // namespace geometry
}  // namespace evolution
