#include <iostream>
#include <string.h>
#include <iomanip>
#include <sstream> // std::stringstream
#include <math.h>

using namespace std;

/**
0 x 7 = 0
1 x 7 = 7
2 x 7 = 14
3 x 7 = 21
4 x 7 = 28
5 x 7 = 35
6 x 7 = 42
7 x 7 = 49
8 x 7 = 56
9 x 7 = 63
10 x 7 = 70
11 x 7 = 77
12 x 7 = 84

0 x 7  = 0
1 x 7  = 7
2 x 7  = 14
3 x 7  = 21
4 x 7  = 28
5 x 7  = 35
6 x 7  = 42
7 x 7  = 49
8 x 7  = 56
9 x 7  = 63
10 x 7 = 70
11 x 7 = 77
12 x 7 = 84

*/

// set width of space before equals sign to len(i-1) + len(n-1)

int nextInt();
int getIntLength(int num);

int main(void) {
    cout << "Enter an integer: ";
    int n (nextInt());
    int n_len (getIntLength(n));

    string largest = "12 x " + to_string(n);
    int l_len = largest.length();

    string current;
    for (int i = 0; i <= 12; i++) {
        current = to_string(i) + " x " + to_string(n);
        cout << current << setw(l_len - current.length() + 1) << " " << "= " << (i*n) << endl;
    }
}

int nextInt() {
    int res;
    if (! (cin >> res)) {
        cout << "TypeError: Input must be an integer." << endl;
        cin.clear();
        cin.ignore(123, '\n');
        return nextInt();
    }
    return res;
}

int getIntLength(int num) {
    return log10(num) + 1;
}

string dumpStringStream(stringstream& ss) {
    string str (ss.str());
    ss.clear();
    ss.ignore(str.length() + 10, '\n');
    return str;
}