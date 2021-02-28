#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int t(int n) { // trigger
    return 0.5 * (abs(n-3.5) / (n-3.5) + 1);
}

int nt(int n) { // negative trigger
    return 0.5 * (abs(n-3.5) / -(n-3.5) + 1);
}

int resolveMoviePoints(unsigned int n /* movies rented */) {
    double y;

    y = 70.83*n*n - 25*n*n*n + 4.167*n*n*n*n; // polynomial regression
    y = nt(n) * y + t(n) * 600;               // lim
    y += 1;                                   // add 1 to result for bitwise operation

    y = (int) y >> 1;                         // bit shift y back and forth to round down
    y = (int) y << 1;                         //  odd numbers to the nearest even (i.e. 601 to 600, keep 300, keep 150, etc.)

    return y;
}

int main(int argc, char const *argv[]) {
    int n;

    cout << "How many movies have you rented? ";
    cin >> n;

    cout << "With " << n << " movies, you are accredited " << resolveMoviePoints(n) << " points." << endl;
}
