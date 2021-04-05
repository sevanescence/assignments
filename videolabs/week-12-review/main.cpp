#include <iostream>

void EnterValues(double&, double&);
double CalcArea(double, double);
double CalcPerimeter(double, double);
double CalcDiagonal(double, double);
double DrawRectangle(double, double);

int main(void) {

    return 0;
}

void EnterValues(double& length, double& width) {
    std::cout << "Enter length: ";
    std::cin >> length;
    std::cin.clear();
    std::cin.ignore(123, '\n');
    std::cout << "Enter width: ";
    std::cin >> width;
    std::cin.clear();
    std::cin.ignore(123, '\n');
}

double CalcArea(double length, double width) { 
    return length * width;
}

double CalcPerimeter(double length, double width) {
    return 2 * (length + width);
}

double CalcDiagonal(double length, double width) {
    return (length + width) / 2.0;
}

double DrawRectangle(double length, double width) {
    
}