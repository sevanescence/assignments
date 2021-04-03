#include <functional>
#include <iostream>
#include <string>
#include <math.h>
#include <map>

#define PI 3.14159

void displayMenu(void);
void getChoice(int& choice);
void getRadius(double& radius);
double calcArea(double& radius);
double calcCircumference(double& radius);
double calcDiameter(double& radius);
void displayTable(void);

int main(int argc, const char** argv) {
    int choice;
    do {
        double radius, area, circumference, diameter;
        if (std::system("cls"))
            std::system("clear");
        displayMenu();
        getChoice(choice);
        switch (choice) {
            case 1:
                getRadius(radius);
                std::cout << "radius = " << radius << '\n';
                // I can also just calculate everything in here
                // and print the respective measurements when
                // they are selected. But I don't think you
                // want that, so I am going to avoid it :(
                break;
            case 2:
                getRadius(radius);
                area = calcArea(radius);
                std::cout << "area = " << area << '\n';
                break;
            case 3:
                getRadius(radius);
                circumference = calcCircumference(radius);
                std::cout << "circumference = " << circumference << '\n';
                break;
            case 4:
                getRadius(radius);
                diameter = calcDiameter(radius);
                std::cout << "diameter = " << diameter << '\n';
                break;
            case 5:
                displayTable();
                break;
            case 6:
                continue;
                break;
            default:
                std::cout << "Invalid input. Try again." << '\n';
                break;
        }
        if (choice != 5) {
            std::cout << "Press enter to continue . . . ";
            std::cin.get();
        }
    } while (choice != 6);
    
    return 0;
}

void clearInput() {
    std::cin.clear();
    std::cin.ignore(123, '\n');
}

void displayMenu(void) {
    std::cout << "CIRCLE APPLICATION" << '\n';
    std::cout << "----------------------------" << '\n';
    std::cout << "1) Get Radius" << '\n';
    std::cout << "2) Calculate Area" << '\n';
    std::cout << "3) Calculate Circumference" << '\n';
    std::cout << "4) Calculate Diameter" << '\n';
    std::cout << "5) Display Table" << '\n';
    std::cout << "6) Exit" << '\n';
    std::cout << "----------------------------" << '\n';
}

void getChoice(int& choice) {
    std::cin >> choice;
    clearInput();
}

void getRadius(double& radius) {
    std::cout << "Enter radius: ";
    
    double tmp;
    if ((! (std::cin >> tmp)) || tmp < 0) {
        std::cout << "Invalid input. Must be a positive integer." << '\n';
        clearInput();
        return getRadius(radius);
    }
    clearInput();
    radius = tmp;
}

// std::round(100 * x) / 100 = x rounded to the nearest 100ths place.

double calcArea(double& radius) {
    return std::round(100 * (PI * (radius * radius))) / 100;
}

double calcCircumference(double& radius) {
    return std::round(100 * (2 * PI * radius)) / 100;
}

double calcDiameter(double& radius) {
    return std::round(100 * (radius * 2)) / 100;
}

std::string pad(double n) {
    std::string s;
    int i = (int) n;
    int d = (int) ((n - i) * 100);
    s = s.append(std::to_string(i)).append(".").append(std::to_string(d));
    return s;
}

void displayTable() {
    if (std::system("cls"))
        std::system("clear");
    
    std::cout << "Radius        Circumference" << '\n';
    std::cout << "--------------------------------" << '\n';
    double i;
    for (i = 1; i <= 9; i++) {
        std::cout << i << "             " << pad(calcCircumference(i)) << '\n';
    }
    std::cout << 10 << "            " << calcCircumference(i) << '\n';
    std::cout << "--------------------------------" << '\n';
    // brute force because im lazy and this isnt meant to be scalable.
    std::cout << "Press enter to continue . . . ";
    std::cin.get();
}