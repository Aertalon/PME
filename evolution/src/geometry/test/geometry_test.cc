#include <gtest/gtest.h>
#include "src/geometry/geometry.h"

namespace evolution
{
namespace geometry
{

TEST(Geometry, ConstructionVector) {

  constexpr Vector vec_zero{};
  constexpr Vector vec{1,2};
  static_assert(vec != vec_zero);

  constexpr Vector vec_copyctor{vec};
  constexpr Vector vec_movector{std::move(vec)};

  Vector vec_copyass{};
  vec_copyass = Vector(vec);

  Vector vec_moveass{};
  vec_moveass = Vector(std::move(vec));

  static_assert(vec == vec_copyctor);
  static_assert(vec == vec_movector);
  EXPECT_TRUE(vec == vec_copyass);
  EXPECT_TRUE(vec == vec_moveass);
}


TEST(Geometry, ConstructionPoint) {

  constexpr Point point_zero{};
  constexpr Point point{1,2};
  static_assert(point != point_zero);

  constexpr Point point_copyctor{point};
  constexpr Point point_movector{std::move(point)};

  Point point_copyass{};
  point_copyass = Point(point);

  Point point_moveass{};
  point_moveass = Point(std::move(point));

  static_assert(point == point_copyctor);
  static_assert(point == point_movector);
  EXPECT_TRUE(point == point_copyass);
  EXPECT_TRUE(point == point_moveass);
}

TEST(Geometry, DifferenceAndSumPointAndVector) {

  constexpr Point p1{5, 12};
  constexpr Point p2{8, 10};

  static_assert(p2 - p1 == Vector(3, -2));

  constexpr Point p3{5, 10};
  constexpr Vector v{2, -5};

  static_assert(p3 + v == Point(7, 5));

}


TEST(Geometry, Rotate) {

  Vector v{1, 0};
  v.rotate(Rotation::Clockwise);
  EXPECT_TRUE(v == Vector(1, -1));
  v.rotate(Rotation::Clockwise);
  EXPECT_TRUE(v == Vector(0, -1));
  v.rotate(Rotation::Clockwise);
  EXPECT_TRUE(v == Vector(-1, -1));
  v.rotate(Rotation::Clockwise);
  EXPECT_TRUE(v == Vector(-1, 0));
  v.rotate(Rotation::Clockwise);
  EXPECT_TRUE(v == Vector(-1, 1));
  v.rotate(Rotation::Clockwise);
  EXPECT_TRUE(v == Vector(0, 1));
  v.rotate(Rotation::Clockwise);
  EXPECT_TRUE(v == Vector(1, 1));
  v.rotate(Rotation::Clockwise);
  EXPECT_TRUE(v == Vector(1, 0));

  v.rotate(Rotation::Counterclockwise);
  EXPECT_TRUE(v == Vector(1, 1));
  v.rotate(Rotation::Counterclockwise);
  EXPECT_TRUE(v == Vector(0, 1));
  v.rotate(Rotation::Counterclockwise);
  EXPECT_TRUE(v == Vector(-1, 1));
  v.rotate(Rotation::Counterclockwise);
  EXPECT_TRUE(v == Vector(-1, 0));
  v.rotate(Rotation::Counterclockwise);
  EXPECT_TRUE(v == Vector(-1, -1));
  v.rotate(Rotation::Counterclockwise);
  EXPECT_TRUE(v == Vector(0, -1));
  v.rotate(Rotation::Counterclockwise);
  EXPECT_TRUE(v == Vector(1, -1));
  v.rotate(Rotation::Counterclockwise);
  EXPECT_TRUE(v == Vector(1, 0));

  Point p1{1,0};
  constexpr Point o{0, 0};
  p1.rotate_around(o, Rotation::Clockwise);
  EXPECT_TRUE(p1 == Point(1, -1));
  p1.rotate_around(o, Rotation::Counterclockwise);
  p1.rotate_around(o, Rotation::Counterclockwise);
  EXPECT_TRUE(p1 == Point(1, 1));


}



}  // namespace geometry
}  // namespace evolution
