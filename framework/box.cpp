#include "box.hpp"

Box::Box() :
    min_{0.0, 0.0, 0.0},
    max_{1.0, 1.0, 1.0}
{}

Box::Box(glm::vec3 min, glm::vec3 max) :
    min_{min},
    max_{max}
{}

Box::Box(glm::vec3 min, glm::vec3 max, std::string name, Color rgb) :
    min_{min},
    max_{max},
    Shape(name, rgb)
{}

float Box::volume() const {
    float h = (min_.x - max_.x) * -1;
    float w = (min_.y - max_.y) * -1;
    float l = (min_.z - max_.z) * -1;
    return(h * w * l);
}

float Box::area() const {
    float h = (min_.x - max_.x) * -1;
    float w = (min_.y - max_.y) * -1;
    float l = (min_.z - max_.z) * -1;
    return(2 * (h * w) + 2 * (h * l) + 2 * (l * w));
}

std::ostream& Box::print(std::ostream& os) const {
    Shape::print(os);
    os << ", Min: {" << min_.x << ", " << min_.y << ", " << min_.z << "}, " << "Max: {" << max_.x << ", " << max_.y << ", " << max_.z << "}.";
    return os;
}