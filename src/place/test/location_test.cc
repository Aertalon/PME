#include <gtest/gtest.h>
#include "../location.h"
#include <iostream>


TEST(PlaceTest, CreateTile)
{
    Tile tile_ex{{10, 20}, "example_tile"};
    std::cout << tile_ex << std::endl;
}
