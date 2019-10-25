 #include "trapezoid.hpp"

Trapezoid::Trapezoid() {
    for (int i = 0; i < 4; ++i) {
        x_[i] = 0;
        y_[i] = 0;
    }
}

Trapezoid::Trapezoid(std::istream& is) {
    is >> *this;
    assert(IsCorrect());
}

int Trapezoid::IsCorrect() const {
    double vec1_x = x_[3] - x_[0];
    double vec1_y = y_[3] - y_[0];

    double vec2_x = x_[2] - x_[1];
    double vec2_y = y_[2] - y_[1];

    double vec3_x = x_[1] - x_[0];
    double vec3_y = y_[1] - y_[0];

    double vec4_x = x_[2] - x_[3];
    double vec4_y = y_[2] - y_[3];
    
    if ((vec1_x / vec2_x == vec1_y / vec2_y) || (vec3_x / vec4_x == vec3_y / vec4_y) || //отношение соответствующих координат
            (vec1_x == 0 && vec2_x == 0) || (vec1_y == 0 && vec2_y == 0) || (vec3_x == 0 && vec4_x == 0) || (vec3_y == 0 && vec4_y == 0)) {
        return 1;
    }
    return 0;
}

std::ostream& Trapezoid::CalculateCenter(std::ostream& os) const {
    double xCenter = 0;
    double yCenter = 0;

    for (int i = 0; i < 4; ++i) {
        xCenter += x_[i];
        yCenter += y_[i];
    }

    xCenter /= 4;
    yCenter /= 4;

    os << "Center : " << "(" << xCenter << ", " << yCenter << ')' << std::endl;

    return os;
}

std::ostream& Trapezoid::CalculateArea(std::ostream& os) const {
    double area1 = 0.5 * abs((x_[2] - x_[1]) * (y_[3] - y_[1]) - (x_[3] - x_[1]) * (y_[2] - y_[1]));
    double area2 = 0.5 * abs((x_[0] - x_[1]) * (y_[3] - y_[1]) - (x_[3] - x_[1]) * (y_[0] - y_[1]));
    
    double area = area1 + area2;

    os << "Area: " << area << std::endl << std::endl;

    return os;
}

void Trapezoid::Print(std::ostream& os) const {
    os << *this;
}

std::ostream& operator<< (std::ostream &os, const Trapezoid& trapezoid) {
    os << "Trapezoid:" << std::endl;
    os << "Coordinates: " << "A(" << trapezoid.x_[0] << ", " << trapezoid.y_[0] << "), ";
    os << "B(" << trapezoid.x_[1] << ", " << trapezoid.y_[1] << "), ";
    os << "C(" << trapezoid.x_[2] << ", " << trapezoid.y_[2] << "), ";
    os << "D(" << trapezoid.x_[3] << ", " << trapezoid.y_[3] << ")" << std::endl;
    
    return os;
}

std::istream& operator>> (std::istream& is, Trapezoid& trapezoid) {
    is >> trapezoid.x_[0] >> trapezoid.y_[0];
    is >> trapezoid.x_[1] >> trapezoid.y_[1];
    is >> trapezoid.x_[2] >> trapezoid.y_[2];
    is >> trapezoid.x_[3] >> trapezoid.y_[3];

    return is;
}
