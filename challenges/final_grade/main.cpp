#include <iostream>
#include <string>

// Makoto Miyamoto
// COSC 1436
// Programming Challenge - Final Grade

/**
 * TODO: Write a C++ program that asks the user for
 *       5 grades, drops the lowest grade, calculates
 *       the average of the four remaining grades,
 *       and displays the letter grade for the average.
 *       Your program will need the following:
 *
 *       * A function that stores 5 grades from the user - use reference params (queryInt)
 *       * A function that returns the lowest value (lowestValue)
 *       * A function that returns the average of all the grades minus the lowest (averageExcludingLowest)
 *       * A function that takes an average as input and returns a letter grade (getLetterGrade)
 */

float averageExcludingLowest(int&, int&, int&, int&, int&);
char  getLetterGrade(float);
int   lowestValue(int**, int size);
int   indexOf(int**, int size, int value);
int   queryInt(std::string);

void test(int& i) {
    int* ia [1] = {&i};
    (*ia[0])++;
}

int main(void) {
    int g1, g2, g3, g4, g5;
    g1 = queryInt("Enter grade 1: ");
    g2 = queryInt("Enter grade 2: ");
    g3 = queryInt("Enter grade 3: ");
    g4 = queryInt("Enter grade 4: ");
    g5 = queryInt("Enter grade 5: ");

    float avg = averageExcludingLowest(g1, g2, g3, g4, g5);
    std::cout << "Your average grade is: " << avg << '\n';
    std::cout << "Your letter average is: " << getLetterGrade(avg) << '\n';

}

float averageExcludingLowest(int& g1, int& g2, int& g3, int& g4, int& g5) {
    int* grades [5] = { &g1, &g2, &g3, &g4, &g5 };
    int arrSize = 5;
    int lowestGradeIndex = indexOf(grades, arrSize, lowestValue(grades, arrSize));

    float avg;
    for (int i = 0; i < arrSize; i++) {
        if (i == lowestGradeIndex) continue;
        avg += *grades[i];
    }
    avg /= (float) 4;

    return avg;
}

char getLetterGrade(float grade) {
    int gradeRounded = ((int) grade / 10) * 10;
    if (gradeRounded >= 100) return 'A';
    switch(gradeRounded) {
        case 90:
            return 'A';
        case 80:
            return 'B';
        case 70:
            return 'C';
        default:
            return 'F';
    }
}

int lowestValue(int** grades, int size) {
    int lowest = *grades[0];
    for (int i = 0; i < size; i++) {
        if (*grades[i] < lowest) {
            lowest = (*grades[i]);
        }
    }
    return lowest;
}

int indexOf(int** grades, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (*grades[i] == value) {
            return i;
        }
    }
    return -1;
}

int queryInt(std::string query) {
    int n;
    std::cout << query;
    std::cin >> n;
    std::cin.clear();
    std::cin.ignore(123, '\n');
    return n;
}