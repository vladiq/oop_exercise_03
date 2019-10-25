#include <iostream>
#include <vector>
#include <cmath>

#include "figure.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "trapezoid.hpp"

int main(void) {
    std::vector<Figure*> figures;
    int input;

    while (true) {
        std::cout << "===================================" << std::endl;
        std::cout << "Available commands:" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "1. Add a figure via id" << std::endl;
        std::cout << "2. Print info for every figure" << std::endl;
        std::cout << "3. Remove a figure via id" << std::endl << std::endl;

        std::cin >> input;

        if (input == 0) {
            break;
        }

        if (input > 3) {
            std::cout << "ERROR: invalid command" << std::endl << std::endl;
            continue;
        }

        switch(input) {
            case 1:
                int figureID;
                std::cout << "Enter a figure id (1 - square, 2 - rectangle, 3 - trapezoid): ";
                std::cin >> figureID;

                if (figureID < 1 || figureID > 3) {
                    std::cout << "ERROR: invalid id" << std::endl;
                    continue;
                }

                std::cout << "Enter 4 (x, y) points in a sequence" << std::endl;
                Figure* newFigure;

                switch (figureID) {
                    case 1:
                        newFigure = new Square(std::cin);
                        figures.push_back(newFigure);
                    break;

                    case 2:
                        newFigure = new Rectangle(std::cin);
                        figures.push_back(newFigure);

                    break;

                    case 3:
                        newFigure = new Trapezoid(std::cin);
                        figures.push_back(newFigure);
                    break;
                }
            break;

            case 2:
                if (figures.size() == 0) {
                    std::cout << "No figures to display" << std::endl << std::endl;
                } else {
                    int id = 0;
                    for (Figure* currentFigure : figures) {
                        std::cout << "ID: " << id << std::endl;
                        currentFigure->Print(std::cout);
                        currentFigure->CalculateCenter(std::cout);
                        currentFigure->CalculateArea(std::cout);
                        ++id;
                    }
                }
            break;

            case 3:
                size_t id;
                std::cout << "Enter a figure id: ";
                std::cin >> id;

                if (id > figures.size() - 1) {
                    std::cout << "ERROR: invalid id" << std::endl << std::endl;
                } else {
                    delete figures[id];
                    figures.erase(figures.begin() + id);
                }
            break;
        }
    }

    for (size_t i = 0; i < figures.size(); ++i) {
		delete figures[i];
	}
}
