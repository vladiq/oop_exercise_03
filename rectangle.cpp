#include "rectangle.hpp"

Rectangle::Rectangle() {
    for (int i = 0; i < 4; ++i) {
        x_[i] = 0;
        y_[i] = 0;
    }
    area_ = 0;
	xCenter_ = 0;
    yCenter_ = 0;
}

Rectangle::Rectangle(std::istream& is) {
    is >> *this;
    area_ = CalculateArea();
    CalculateCenter();
}

bool Rectangle::IsCorrect() const {
    double vec1_x = x_[1] - x_[0];
    double vec1_y = y_[1] - y_[0];

    double vec2_x = x_[2] - x_[1];
    double vec2_y = y_[2] - y_[1];

    double vec3_x = x_[3] - x_[0];
    double vec3_y = y_[3] - y_[0];

    double dotProduct1 = vec1_x * vec2_x + vec1_y * vec2_y;
    double dotProduct2 = vec3_x * vec1_x + vec3_y * vec1_y;

    if (dotProduct1 == 0 && dotProduct2 == 0) {
        return true;
    }
    return false;
}

void Rectangle::CalculateCenter() {
    xCenter_ = (x_[0] + x_[2]) / 2;
    yCenter_ = (y_[0] + y_[2]) / 2;
}

double Rectangle::CalculateArea() {
    double xHeight = x_[1] - x_[0];
    double yHeight = y_[1] - y_[0];

    double xWidth = x_[2] - x_[1];
    double yWidth = y_[2] - y_[1];

    return sqrt(xHeight * xHeight + yHeight * yHeight) * sqrt(xWidth * xWidth + yWidth * yWidth);
}

void Rectangle::Print(std::ostream& os) const {
    os << *this;
}

std::ostream& operator<< (std::ostream &os, const Rectangle& rectangle) {
    os << "Rectangle:" << std::endl;
    os << "Coordinates: " << "A(" << rectangle.x_[0] << ", " << rectangle.y_[0] << "), ";
    os << "B(" << rectangle.x_[1] << ", " << rectangle.y_[1] << "), ";
    os << "C(" << rectangle.x_[2] << ", " << rectangle.y_[2] << "), ";
    os << "D(" << rectangle.x_[3] << ", " << rectangle.y_[3] << ")" << std::endl;
    os << "Center : " << "(" << rectangle.xCenter_ << ", " << rectangle.yCenter_ << ')' << std::endl;
    os << "Area: " << rectangle.area_ << std::endl << std::endl;
    
    return os;
}

std::istream& operator>> (std::istream& is, Rectangle& rectangle) {
    is >> rectangle.x_[0] >> rectangle.y_[0];
    is >> rectangle.x_[1] >> rectangle.y_[1];
    is >> rectangle.x_[2] >> rectangle.y_[2];
    is >> rectangle.x_[3] >> rectangle.y_[3];

    return is;
}
