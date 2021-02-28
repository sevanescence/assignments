#include <iostream>
#include <stdio.h>
#include <map>

#define ARR_LENGTH 3

using namespace std;

char getLetterGrade(int grade) {
    if (grade >= 100)
        return 'P';
    else if (grade < 70)
        return 'F';

    map<int, char> letterGradeMap { { 70, 'C' }, { 80, 'B' }, { 90, 'A' } };
    map<int, char>::iterator it;

    for (it = letterGradeMap.begin(); it != letterGradeMap.end(); it++) {
        if (grade % it->first < 10)
            return it->second;
    }

    return '?';
}

int main(int argc, char const *argv[]) {
    int    grades [ARR_LENGTH] = { };
    double average;
    char   letterGrade;

    int total (0);
    for (int i = 0; i < ARR_LENGTH; i++) {
        cout << "Enter grade " << i+1 << ": ";
        cin >> grades[i];
        total += grades[i];
    }

    average     = (double) total / ARR_LENGTH;
    letterGrade = getLetterGrade(average);

    if (letterGrade == 'P') {
        cout << "You got a perfect score!" << endl;
    } else {
        cout << "You received " << (letterGrade == 'F' || letterGrade == 'A' ? "an " : "a ") << letterGrade << " average." << endl;
    }
}
