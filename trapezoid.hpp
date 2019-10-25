#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include <iostream>
#include <cmath>

#include "figure.hpp"

class Trapezoid: public Figure {

public:
    Trapezoid();
	Trapezoid(std::istream& is);

    bool IsCorrect() const override;
	void CalculateCenter() override;
	double CalculateArea() override;
	void Print(std::ostream& os) const override;

	friend std::ostream& operator << (std::ostream& os, const Trapezoid& trapezoid);
	friend std::istream& operator >> (std::istream& is, Trapezoid& trapezoid);

    ~Trapezoid() {}
};

#endif // TRAPEZOID_H 
