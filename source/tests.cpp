#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"
#include "color.hpp"


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

TEST_CASE("print function test", "[sphere, box, shape]") {
  Sphere one({1.0, 1.0, 1.0}, 2, "Hans", {1, 1, 1});
  Box two{{0.0, 0.0, 0.0}, {1.0, 1.0, 1.0}, "Dieter", {1, 1, 1}};

  std::cout << std::endl;
  one.print(std::cout);

  two.print(std::cout);

}

TEST_CASE("intersect_ray_sphere", "[intersect]") {
  // Ray
  glm::vec3 ray_origin{0.0f, 0.0f, 0.0f};
  // ray direction has to be normalized!
  // you can use:
  // v = glm::normalize (some_vector)
  glm::vec3 ray_direction{0.0f, 0.0f, 1.0f};
  // Sphere
  glm::vec3 sphere_center{0.0f, 0.0f, 5.0f};
  float sphere_radius{1.0f};
  float distance = 0.0f;
  auto result = glm::intersectRaySphere(
    ray_origin, ray_direction,
    sphere_center,
    sphere_radius * sphere_radius, // squared radius !!!
    distance);
  REQUIRE(distance == Approx(4.0f));
}

TEST_CASE("static vs dynamic", "[sphere, shape]") {
  Color red{255, 0, 0};
  glm::vec3 position {0.0f, 0.0f, 0.0f};
  std::shared_ptr<Sphere> s1 = std::make_shared<Sphere>(position, 1.2f, "sphere0", red);
  std::shared_ptr<Shape> s2 = std::make_shared<Sphere>(position, 1.2f, "sphere1", red);
  
  std::cout << std::endl;
  s1->print(std::cout);
  s2->print(std::cout);
}

TEST_CASE("virtual Shape destructor", "[Shape]") {
  Color red{255, 0, 0};
  glm::vec3 position{0.0f, 0.0f, 0.0f};
  Sphere* s1 = new Sphere{position, 1.2f, "Sphere0", red};
  Shape* s2 = new Sphere{position, 1.2f, "Sphere1", red};

  std::cout << std::endl;
  s1->print(std::cout);
  s2->print(std::cout);

  delete s1;
  delete s2;
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
