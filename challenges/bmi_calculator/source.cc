#include <iostream>
#include <string>  // std::string
#include <regex>   // std::regex_match, std::regex
#include <math.h>  // std::pow
#include <iomanip> // std::setprecision

#define BMI_CONST 703.0

// Makoto Miyamoto
// COSC 1436
// BMI Calculator

// request height (f'i)
//  - calculate to inches
// request weight (lb)
// BMI = 703.0 * (weight / (height^2))

// it's a pile of functions!
std::string           query        (std::string prompt);
double             queryDouble     (std::string prompt);
std::string      getHealthStatus   (double bmi);
std::string *   splitStringInTwo   (std::string str, std::string delimiter);
int           queryFormattedHeight (std::string prompt);

int main() {
    int    height (queryFormattedHeight("Enter your height (x'y): "));
    double weight (queryDouble("Enter your weight in lb: "));
    double bmi    (BMI_CONST * (weight / std::pow(height, 2)));

    std::cout << "Your BMI is " << std::setprecision(4) << bmi << std::endl;
    std::cout << "Health status: " << getHealthStatus(bmi) << std::endl;
}

std::string query(std::string prompt) {
    std::string res;
    std::cout << prompt;

    std::cin >> res;
    return res;
}

double queryDouble(std::string prompt) {
    double res;
    std::cout << prompt;

    while (! (std::cin >> res)) {
        std::cout << "Input must be a decimal number." << std::endl;
        std::cin.clear();
        std::cin.ignore(123, '\n');
        return queryDouble(prompt);
    }

    return res;
}

std::string getHealthStatus(double bmi) {
    if (bmi > 30)
        return "Obese";
    else if (bmi >= 25)
        return "Overweight";
    else if (bmi >= 18.5)
        return "Normal";
    else
        return "Underweight";
}

std::string * splitStringInTwo(std::string str, std::string delimiter) {
    static std::string split [2];
    int splitAt (str.find(delimiter));

    split[0] = str.substr(0, splitAt);
    split[1] = str.substr(splitAt+1, str.length());

    return split;
}

int queryFormattedHeight(std::string prompt) {
    std::string heightString (query(prompt));
    
    if (! std::regex_match(heightString, std::regex("[0-9]+?'(1(0|1)|0?[0-9])"))) {
        std::cout << "Height must be formatted as ft'in (ex. 5'11, 6'0)." << std::endl;
        return queryFormattedHeight(prompt);
    }

    std::string * heightSplit (splitStringInTwo(heightString, "'"));
    int heightInches (std::stoi(heightSplit[0]) * 12 + std::stoi(heightSplit[1]));

    return heightInches;
}
