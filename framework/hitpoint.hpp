#ifndef HITPOINT_HPP
#define HITPOINT_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>

struct HitPoint {
    bool cut_;
    float distance_;
    std::string name_;
    Color rgb;
    glm::vec3 cutpoint_;
    glm::vec3 direction_;
};

#endif //HITPOINT_HPP