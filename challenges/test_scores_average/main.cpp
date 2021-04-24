#include <iostream>
#include <string>

void getTestScores(int *scores, int const &length);
double getAverage(int *scores, int const &length);
int getSum(int *scores, int const &length);

int main() {
    int const LENGTH = 2;
    int scores[LENGTH];
    getTestScores(scores, LENGTH);
    double average = getAverage(scores, LENGTH);
    std::cout << average << std::endl;
}

void getTestScores(int *scores, int const &length) {
    int c = 0;
    for (int i = 0; i < length; i++) {
        std::cout << "Enter test score #" << i+1 << ": ";
        if (! (std::cin >> c) || c > 100 || c < 0) {
            std::cout << "Invalid input. Enter a number from 0-100" << '\n';
            i--;
            continue;
        }
        scores[i] = c;
    }
}

double getAverage(int *scores, int const &length) {
    int sum = getSum(scores, length);
    return (double) sum / length;
}

int getSum(int *scores, int const &length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += scores[i];
    }
    return sum;
}