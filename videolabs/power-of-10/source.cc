#include <iostream>
#include <math.h>
#include <iomanip>
#include <string.h>

using namespace std;

int getIntLength(int num);

int main(void) {
    for (int counter = 0; counter < 10; cout << counter++ << endl);

    cout << "Power of 10 = Standard Format" << endl;
    for (int exponent = 0; exponent < 10; exponent++) {
        int e = pow(10, exponent);
        int len = getIntLength(e);
        cout << "10 ^ " << exponent << setw(8) << " = " << setprecision(2) << e << setw(12-len) << "" << " - Length of " << len << " digits!" << endl;
    }
}

/*
    I spent an hour coming up with this solution only
    to realize that I didn't need it. Well, I don't care.
    I came this far, it's staying here. :T
*/

int getIntLength(int num) {
    return log10(num) + 1;
}

// int getIntLength(int num) {
//     int numCeil = ceil(log10(num));
//     int numFloor = floor(log10(num));
//     int t = numCeil - numFloor;
//     return !t * numCeil + t * numFloor + 1;
// }