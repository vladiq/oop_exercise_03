#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include <iostream>
#include <cmath>
#include <assert.h>


#include "figure.hpp"

class Trapezoid: public Figure {

public:
    Trapezoid();
	Trapezoid(std::istream& is);

    int IsCorrect() const override;
	std::ostream& CalculateCenter(std::ostream& os) const override;
	std::ostream& CalculateArea(std::ostream& os) const override;
	void Print(std::ostream& os) const override;

	friend std::ostream& operator << (std::ostream& os, const Trapezoid& trapezoid);
	friend std::istream& operator >> (std::istream& is, Trapezoid& trapezoid);

    ~Trapezoid() {}
};

#endif // TRAPEZOID_H 
