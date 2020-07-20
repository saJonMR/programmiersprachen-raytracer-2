#ifndef SHPERE_HPP
#define SHPERE_HPP

#include "hitpoint.hpp"
#include "ray.hpp"
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <iostream>

class Sphere : public Shape {
public:
    Sphere();
    Sphere(glm::vec3 center, float r);
    Sphere(glm::vec3 center, float r, std::string name, Color rgb);
    ~Sphere();
    /* virtual */ float volume() const override;
    /* virtual */ float area() const override;

    /* virtual */ std::ostream& print(std::ostream& os) const override;

    HitPoint intersect(Ray const& ray) const;
private:
    glm::vec3 center_;
    float radius_;
};

#endif //SPHERE_HPP