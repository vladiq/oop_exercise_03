#ifndef FIGURE_H
#define FIGURE_H

class Figure {

protected:
	double area_;
	double xCenter_, yCenter_;
	double x_[4];
	double y_[4];

public:
	Figure() {}

	virtual bool IsCorrect() const = 0;
	virtual void CalculateCenter() = 0;
	virtual double CalculateArea() = 0;
	virtual void Print(std::ostream& os) const = 0;

	virtual ~Figure() {}
};

#endif //FIGURE_H
