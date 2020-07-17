#include "sphere.hpp"
#include <cmath>

Sphere::Sphere() :
    center_{1.0, 1.0, 1.0},
    radius_{1.0}
{}

Sphere::Sphere(glm::vec3 center, float r) :
    center_{center},
    radius_{r}
{}

float Sphere::volume() const {
    return((4.0 / 3.0) * M_PI * pow(radius_, 3));
}

float Sphere::area() const {
    return(4 * M_PI * pow(radius_, 2));
}