#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <cmath>
#include <assert.h>


#include "figure.hpp"

class Rectangle: public Figure {

public:
	Rectangle();
	Rectangle(std::istream& is);

	int IsCorrect() const override;
	std::ostream& CalculateCenter(std::ostream& os) const override;
	std::ostream& CalculateArea(std::ostream& os) const override;
	void Print(std::ostream& os) const override;

	friend std::ostream& operator << (std::ostream& os, const Rectangle& rectangle);
	friend std::istream& operator >> (std::istream& is, Rectangle& rectangle);

	~Rectangle() {}
};

#endif //RECTANGLE_H
