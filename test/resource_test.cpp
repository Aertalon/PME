#include "src/resource.hpp"

#include "boost/ut.hpp"

// NOLINTBEGIN(readability-magic-numbers)

auto main() -> int
{
    using namespace boost::ut;

    test("constexpr ctors and getter test") = [&] {
        constexpr Grain g{10};
        expect(constant<eq(g.getQuantity(), 10)>);

        constexpr Frankincense f{5};
        constexpr Frankincense f1{f};
        expect(constant<eq(f1.getQuantity(), 5)>);

        constexpr Frankincense f2 = f;
        expect(constant<eq(f2.getQuantity(), 5)>);

        constexpr Frankincense f3 = Frankincense{10};
        expect(constant<eq(f3.getQuantity(), 10)>);
    };

    test("sum operator") = [&] {
        Grain g1{10};
        Grain g2{5};

        Grain g3 = g1 + g2;

        // Check expected result
        expect(eq(g3.getQuantity(), 15));
        // Check that the sum operator empties the previous values
        expect(eq(g1.getQuantity(), 0));
        expect(eq(g2.getQuantity(), 0));

        // Consume: expected consumable
        expect(g3.consume(Grain{12}));
        expect(eq(g3.getQuantity(), 3));

        // Consume: expected non consumble and emptied
        expect(!g3.consume(Grain{4}));
        expect(eq(g3.getQuantity(), 0));

        Grain g4 = g1 + g2;
        // Three empty values
        expect(eq(g1.getQuantity(), 0));
        expect(eq(g2.getQuantity(), 0));
        expect(eq(g4.getQuantity(), 0));
    };

}

// NOLINTEND(readability-magic-numbers)
