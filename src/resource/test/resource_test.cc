#include <gtest/gtest.h>
#include "../resource.h"

TEST(ResouceTest, CreateResource)
{
  Grain g1{10};
  Grain g2{5};

  Grain g3 = g1 + g2;
  EXPECT_EQ(g3.getQuantity(), 15);
  EXPECT_TRUE(g3.consume(Grain{12}));
  EXPECT_EQ(g3.getQuantity(), 3);

  EXPECT_FALSE(g3.consume(Grain{4}));
  EXPECT_EQ(g3.getQuantity(), 0);

  Frankincense f{5};
  Frankincense f2{2};
  Frankincense f3{f+f2};

  EXPECT_EQ(f3.getQuantity(), 7);

}
