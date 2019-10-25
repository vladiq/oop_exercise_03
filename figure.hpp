#ifndef FIGURE_H
#define FIGURE_H

class Figure {

protected:
	double x_[4];
	double y_[4];

public:
	Figure() {}

	virtual int IsCorrect() const = 0;
	virtual std::ostream& CalculateCenter(std::ostream& os) const = 0;
	virtual std::ostream& CalculateArea(std::ostream& os) const = 0;
	virtual void Print(std::ostream& os) const = 0;

	virtual ~Figure() {}
};

#endif //FIGURE_H
