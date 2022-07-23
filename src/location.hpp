#include <string>
#include <iostream>
#include <array>

#ifndef LOCATION_H_
#define LOCATION_H_

class Position
{
    std::array<int, 2> position;

    public:
        constexpr Position(std::array<int, 2> pos) :
            position{std::move(pos)}
            {}

    template<class OStream>
    constexpr friend OStream& operator<<(OStream& os, Position& p)
        {
            os << "(" << p.position[0] << ", " << p.position[1] << ")";
            return os;
        }
};

class Tile
{
    Position position;
    std::string tile_name;

    public:
        template<
            class StringLike,
            std::enable_if_t<std::is_constructible<std::string, std::decay_t<StringLike>>::value, int> = 0>
        constexpr Tile(std::array<int, 2> pos, StringLike tile_name) :
            position{pos},
            tile_name{std::move(tile_name)}
        {}

        template<class OStream>
        constexpr friend OStream& operator<<(OStream& os, Tile& tile)
        {
            os << "Tile " << tile.tile_name;
            os << " is in position " << tile.position;
            return os;
        }
};


template<std::size_t N>
class Location
{
    std::array<Tile, N> tiles_;

    public:
        constexpr Location() :
            tiles_{}
            {}

        void print();
};

#endif // PERSON_H_