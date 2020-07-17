#ifndef BOX_HPP
#define BOX_HPP

#include "shape.hpp"

#include <glm/vec3.hpp>

class Box : public Shape {
public:
    Box();
    Box(glm::vec3 min, glm::vec3 max);
    Box(glm::vec3 min, glm::vec3 max, std::string name, Color rgb);
    //~Box();
    /* virtual */ float volume() const override;
    /* virtual */ float area() const override;

    /* virtual */ std::ostream& print(std::ostream& os) const override;
private:
    glm::vec3 min_;
    glm::vec3 max_;
};

#endif //BOX_HPP