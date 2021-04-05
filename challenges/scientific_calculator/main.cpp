#include <iostream>
#include <iomanip>
#include <string>

long const LIGHT_SPEED = 300000000;

// Makoto Miyamoto
// COSC 1436
// Scientific Calculator
// TODO: Display a menu with the following
//       options in numerical order (and 6
//       to close the program).
// NOTE: Values need to be rounded to the
//       nearest thousandth.

double getEnergy(double mass);
double getVelocity(double distance, double time);
double getAcceleration(double vFinal, double vInitial, double tFinal, double tInitial);
double getForce(double mass, double acceleration);
double getVoltage(double current, double resistance);
void displayMenu();
std::string parseToNearestThousandth(double num);
double queryDouble(std::string prompt);
void clear();

int main(void) {
    int choice;
    while (choice != 6) {
        displayMenu();
        std::cout << "> ";
        while (! (std::cin >> choice) || choice < 1 || choice > 6) {
            std::cout << "Invalid input. Choose an integer between 1 and 6." << '\n';
            clear();
            std::cout << "> ";
        }
        double mass, distance, time, vFinal, vInitial, tFinal, tInitial, acceleration, current, resistance;
        // double velocity, force, voltage;
        switch (choice) {
            case 1:
                mass = queryDouble("Enter mass (g): ");
                std::cout << "Energy is " << std::setprecision(3) << getEnergy(mass) << '\n';
                break;
            case 2:
                distance = queryDouble("Enter distance (m): ");
                time = queryDouble("Enter time (seconds): ");
                std::cout << "Velocity is " << std::setprecision(3) << getVelocity(distance, time) << '\n';
                break;
            case 3:
                vFinal = queryDouble("Enter final velocity (m/s): ");
                vInitial = queryDouble("Enter initial velocity (m/s): ");
                tFinal = queryDouble("Enter final time (s): ");
                tInitial = queryDouble("Enter initial time (s): ");
                acceleration = getAcceleration(vFinal, vInitial, tFinal, tInitial);
                std::cout << "Acceleration is " << std::setprecision(3) << acceleration << '\n';
                break;
            case 4:
                mass = queryDouble("Enter mass (g): ");
                acceleration = queryDouble("Enter acceleration: ");
                std::cout << std::setprecision(3) << getForce(mass, acceleration) << '\n';
                break;
            case 5:
                current = queryDouble("Enter current (amps): ");
                resistance = queryDouble("Enter resistance (ohms): ");
                std::cout << std::setprecision(3) << getVoltage(current, resistance) << '\n';
                break;
            default:
                return 0;
        }
        clear();
        std::cout << "Press enter to continue . . .";
        std::cin.get();
        if (std::system("cls"))
            std::system("clear");
    }

    return 0;
}

double getEnergy(double mass) {
    return mass * (LIGHT_SPEED * LIGHT_SPEED);
}

double getVelocity(double distance, double time) {
    return distance / time;
}

// THIS IS TOO LONG
double getAcceleration(double vFinal, double vInitial, double tFinal, double tInitial) {
    return (vFinal - vInitial) / (tFinal - tInitial);
}

double getForce(double mass, double acceleration) {
    return mass * acceleration;
}

double getVoltage(double current, double resistance) {
    return current * resistance;
}

void displayMenu() {
    std::cout << "SCIENTIFIC CALCULATOR" << '\n';
    std::cout << "--------------------------------" << '\n';
    std::cout << "1) Energy" << '\n';
    std::cout << "2) Velocity" << '\n';
    std::cout << "3) Acceleration" << '\n';
    std::cout << "4) Force" << '\n';
    std::cout << "5) Voltage" << '\n';
    std::cout << "6) Quit" << '\n';
    std::cout << "--------------------------------" << '\n';
}

double queryDouble(std::string prompt) {
    std::cout << prompt;
    double in;
    while (! (std::cin >> in)) {
        std::cout << "Invalid input. Expected a number." << '\n';
        clear();
        return queryDouble(prompt);
    }
    return in;
}

void clear() {
    std::cin.clear();
    std::cin.ignore(123, '\n');
}