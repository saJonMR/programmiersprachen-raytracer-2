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

Sphere::Sphere(glm::vec3 center, float r, std::string name, Color rgb) :
    center_{center},
    radius_{r},
    Shape(name, rgb)
{}

float Sphere::volume() const {
    return((4.0 / 3.0) * M_PI * pow(radius_, 3));
}

float Sphere::area() const {
    return(4 * M_PI * pow(radius_, 2));
}

std::ostream& Sphere::print(std::ostream& os) const{
    Shape::print(os);
    os << ", Center: {" << center_.x << ", " << center_.y << ", " << center_.z << "}, Radius: " << radius_ << ".";
    return os;
}