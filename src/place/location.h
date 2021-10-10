#include <string>
#include <iostream>

#ifndef LOCATION_H_
#define LOCATION_H_

class Position
{
    std::array<int, 2> position;

    public:
        Position(std::array<int, 2> pos) :
            position{std::move(pos)}
            {}

    friend std::ostream& operator<<(std::ostream& os, Position& p)
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
        Tile(std::array<int, 2> pos, std::string tile_name) :
            position{pos},
            tile_name{std::move(tile_name)}
        {}

        friend std::ostream& operator<<(std::ostream& os, Tile& tile)
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
        Location() :
            tiles_{}
            {}

        void print();
};

#endif // PERSON_H_