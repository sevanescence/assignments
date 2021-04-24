#include <iostream>
#include <iomanip>
#include <string>

int calcSum(int scores[], int length);
int findMin(int scores[], int length);
int findMax(int scores[], int length);
void displayTable(std::string names[], int scores[], int length);

int main() {
    int sum, min, max;
    int const LENGTH = 10;
    std::string names[LENGTH] = { "John", "Bob", "Mary", "Tim", "Nick", "Lisa", "Homer", "Bart", "Mr. Burns", "Nelson" };
    int scores[LENGTH] = { 100, 30, 90, 80, 20, 75, 100, 40, 95, 60 };

    displayTable(names, scores, LENGTH);

    sum = calcSum(scores, LENGTH);
    min = findMin(scores, LENGTH);
    max = findMax(scores, LENGTH);

    std::cout << "sum: " << sum << '\n';
    std::cout << "min: " << min << '\n';
    std::cout << "max: " << max << '\n';

}

int calcSum(int scores[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += scores[i];
    }
    return sum;
}

int findMin(int scores[], int length) {
    int min = scores[0];
    for (int i = 0; i < length; i++) {
        if (min > scores[i]) {
            min = scores[i];
        }
    }
    return min;
}

int findMax(int scores[], int length) {
    int max = scores[0];
    for (int i = 0; i < length; i++) {
        if (max < scores[i]) {
            max = scores[i];
        }
    }
    return max;
}

void displayTable(std::string names[], int scores[], int length) {
    std::cout << std::left << std::setw(10) << "Names" << std::setw(10) << "Score" << std::endl;
    std::cout << "---------------" << std::endl;
    for (int i = 0; i < length; i++) {
        std::cout << std::left << std::setw(10) << names[i] << std::setw(10) << scores[i] << std::endl;
    }
    std::cout << "---------------" << std::endl;
}