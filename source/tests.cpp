#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"

TEST_CASE("Box constructor, area and volume test", "[box]") {
  Box one{{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
  Box two;
  REQUIRE(one.area() == 0);
  REQUIRE(one.volume() == 0);
  REQUIRE(two.area() == 6);
  REQUIRE(two.volume() == 1);
}

TEST_CASE("Sphere constructor, area and volume test", "[sphere]") {
  Sphere one;
  Sphere two{{0.0, 0.0, 0.0}, 3.5};
  REQUIRE(one.area() == Approx(12.5663706));
  REQUIRE(one.volume() == Approx(4.1887902));
  REQUIRE(two.area() == Approx(153.93804));
  REQUIRE(two.volume() == Approx(179.59438));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
