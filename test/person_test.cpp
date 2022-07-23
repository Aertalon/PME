#include "src/person.hpp"

#include "boost/ut.hpp"
#include <iostream>

// NOLINTBEGIN(readability-magic-numbers)

auto main() -> int
{
    using namespace boost::ut;

    test("dummy person test") = [&] {

    pme::Smith smith("Joe");
    pme::Farmer farmer("Marez");

    };

}

// NOLINTEND(readability-magic-numbers)
