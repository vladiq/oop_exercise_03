#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <cmath>
#include <assert.h>

#include "figure.hpp"

class Square: public Figure {

public:
    Square();
	Square(std::istream& is);

    int IsCorrect() const override;
	std::ostream& CalculateCenter(std::ostream& os) const override;
	std::ostream& CalculateArea(std::ostream& os) const override;
	void Print(std::ostream& os) const override;

	friend std::ostream& operator << (std::ostream& os, const Square& square);
	friend std::istream& operator >> (std::istream& is, Square& square);

    ~Square() {}
};

#endif //  SQUARE_H
