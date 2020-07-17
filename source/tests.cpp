#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"

TEST_CASE("Box constructor, area and volume test", "[box]") {
  Box one{{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
  Box two{{0.0, 0.0, 0.0}, {1.0, 1.0, 1.0}};
  REQUIRE(one.area() == 0);
  REQUIRE(one.volume() == 0);
  REQUIRE(two.area() == 6);
  REQUIRE(two.volume() == 1);
}

TEST_CASE("Sphere constructor, area and volume test", "[sphere]") {
  
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
