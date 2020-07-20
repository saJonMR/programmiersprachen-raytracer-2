#include "shape.hpp"

Shape::Shape() {}

Shape::Shape(std::string name, Color rgb) :
    name_{name},
    color_{rgb}
{}

Shape::~Shape() {
    std::cout << "Shape deleted." << std::endl; 
}

std::ostream& Shape::print(std::ostream& os) const{
    os << "Name: \"" << name_ << "\", Color: (" << color_.r << ", " << color_.g << ", " << color_.b << ")";
    return os;
}

std::ostream& operator<<(std::ostream os, Shape const& s) {
    return s.print(os);
}