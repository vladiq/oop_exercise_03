#include "square.hpp"

Square::Square() {
    for (int i = 0; i < 4; ++i) {
        x_[i] = 0;
        y_[i] = 0;
    }
}

Square::Square(std::istream& is) {
    is >> *this;
    assert(IsCorrect());
}

int Square::IsCorrect() const {
    double vec1_x = x_[1] - x_[0];
    double vec1_y = y_[1] - y_[0];

    double vec2_x = x_[2] - x_[1];
    double vec2_y = y_[2] - y_[1];

    double vec3_x = x_[3] - x_[0];
    double vec3_y = y_[3] - y_[0];

    double vec4_x = x_[3] - x_[2];
    double vec4_y = y_[3] - y_[2];

    double dotProduct1 = vec1_x * vec2_x + vec1_y * vec2_y;
    double dotProduct2 = vec3_x * vec1_x + vec3_y * vec1_y;
    double dotProduct3 = vec3_x * vec4_x + vec3_y * vec4_y;

    double vec1_length = sqrt(vec1_x * vec1_x + vec1_y * vec1_y);
    double vec2_length = sqrt(vec2_x * vec2_x + vec2_y * vec2_y);

    if (dotProduct1 == 0 && dotProduct2 == 0 && dotProduct3 == 0 && vec1_length == vec2_length) {
        return 1;
    }
    return 0;
}

std::ostream& Square::CalculateCenter(std::ostream& os) const {
    double xCenter = (x_[0] + x_[2]) / 2;
    double yCenter = (y_[0] + y_[2]) / 2;

    os << "Center : " << "(" << xCenter << ", " << yCenter << ')' << std::endl;
    return os;
}

std::ostream& Square::CalculateArea(std::ostream& os) const {
    double vecX = x_[1] - x_[0];
    double vecY = y_[1] - y_[0];

    double area = vecX * vecX + vecY * vecY;

    os << "Area: " << area << std::endl << std::endl;
    return os;
}

void Square::Print(std::ostream& os) const {
    os << *this;
}

std::ostream& operator<< (std::ostream &os, const Square& square) {
    os << "Square:" << std::endl;
    os << "Coordinates: " << "A(" << square.x_[0] << ", " << square.y_[0] << "), ";
    os << "B(" << square.x_[1] << ", " << square.y_[1] << "), ";
    os << "C(" << square.x_[2] << ", " << square.y_[2] << "), ";
    os << "D(" << square.x_[3] << ", " << square.y_[3] << ")" << std::endl;
    
    return os;
}

std::istream& operator>> (std::istream& is, Square& square) {
    is >> square.x_[0] >> square.y_[0];
    is >> square.x_[1] >> square.y_[1];
    is >> square.x_[2] >> square.y_[2];
    is >> square.x_[3] >> square.y_[3];

    return is;
}
