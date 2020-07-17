#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "color.hpp"
#include <string>

class Shape {
public:
    Shape();
    Shape(std::string name, Color rgb);

    virtual float area() const = 0;
    virtual float volume() const = 0;

    virtual std::ostream& print(std::ostream& os) const;
protected:
    std::string name_;
    Color color_;
};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif //SHAPE_HPP