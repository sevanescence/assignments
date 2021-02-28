#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>

#define LENGTH_OF_12 2

using namespace std;

int getIntLength(int num);

int main(void) {
    for (int i = 1; i <= 12; i++) {
        cout << i << setw(LENGTH_OF_12 - getIntLength(i)) << " ";
        string line;
        
        for (int k = 1; k <= 12; k++) {
            cout << ""
        }
    }
    return 0;
}

int getIntLength(int num) {
    return log10(num) + 1;
}