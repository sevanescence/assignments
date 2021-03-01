#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

int    promptInt(string query);     // return integer input
double promptDouble(string query);  // return number input
int    getNumberLength(int num);    // length of an integer
int    getNumberLength(double num); // length of a number parsed as an integer

int main(void) {
    // declare variables
    int numTests;      // number of test scores
    double testScore;  // current test score
    double totalScore; // total test score
    double average;    // average of test scores
    char choice;       // (Y/n) whether or not to continue

    do {
        numTests = promptInt("How many tests did you give? ");
        
        totalScore = 0;
        for (int i = 0; i < numTests; i++) {
            testScore = promptInt("Enter test score " + to_string(i) + ": ");
            totalScore += testScore;
        }

        average = totalScore / numTests;
        cout << "Total:   " << totalScore << endl;
        cout << "Average: " << setprecision(getNumberLength(average) + 2) << average << endl;

        cout << "Would you like to try again? (Y/n) ";
        cin >> choice;
    } while (toupper(choice) == 'Y');
    
    return 0;
}

int promptInt(string query) {
    return promptDouble(query);
}

double promptDouble(string query) {
    cout << query;
    double num;
    if (! (cin >> num)) {
        cout << "TypeError: Expected a number" << endl;
        cin.clear();
        cin.ignore(123, '\n');
        return promptDouble(query);
    }
    return num;
}

int getNumberLength(int num) {
    return log10(num) + 1;
}

int getNumberLength(double num) {
    return getNumberLength((int) num);
}