#include "src/location.hpp"

#include "boost/ut.hpp"
#include <iostream>

// NOLINTBEGIN(readability-magic-numbers)

auto main() -> int
{
    using namespace boost::ut;

    test("dummy location test") = [&] {

        Tile tile_ex{{10, 20}, "example_tile"};
        std::cout << tile_ex << std::endl;

    };

}

// NOLINTEND(readability-magic-numbers)
