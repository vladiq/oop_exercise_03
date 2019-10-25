#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <cmath>

#include "figure.hpp"

class Square: public Figure {

public:
    Square();
	Square(std::istream& is);

    bool IsCorrect() const override;
	void CalculateCenter() override;
	double CalculateArea() override;
	void Print(std::ostream& os) const override;

	friend std::ostream& operator << (std::ostream& os, const Square& square);
	friend std::istream& operator >> (std::istream& is, Square& square);

    ~Square() {}
};

#endif //  SQUARE_H
