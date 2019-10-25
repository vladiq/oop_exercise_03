#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <cmath>

#include "figure.hpp"

class Rectangle: public Figure {

public:
	Rectangle();
	Rectangle(std::istream& is);

	bool IsCorrect() const override;
	void CalculateCenter() override;
	double CalculateArea() override;
	void Print(std::ostream& os) const override;

	friend std::ostream& operator << (std::ostream& os, const Rectangle& rectangle);
	friend std::istream& operator >> (std::istream& is, Rectangle& rectangle);

	~Rectangle() {}
};

#endif //RECTANGLE_H
