#include "shape.hpp"

Shape::Shape() {}

Shape::Shape(std::string name, Color rgb) :
    name_{name},
    color_{rgb}
{}
