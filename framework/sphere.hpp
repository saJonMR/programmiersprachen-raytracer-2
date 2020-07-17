#ifndef SHPERE_HPP
#define SHPERE_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>

class Sphere : public Shape {
public:
    Sphere();
    Sphere(glm::vec3 center, float r);
    Sphere(glm::vec3 center, float r, std::string name, Color rgb);
    //~Sphere();
    /* virtual */ float volume() const override;
    /* virtual */ float area() const override;
private:
    glm::vec3 center_;
    float radius_;
};

#endif //SPHERE_HPP