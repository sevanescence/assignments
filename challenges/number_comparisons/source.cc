#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n1, n2;

    cout << "Enter a number: ";
    cin >> n1;
    cout << "Enter another number: ";
    cin >> n2;

    if (n1 == n2) {
        cout << "These numbers are the same." << endl;
    } else {
        cout << (n1 < n2 ? n1 : n2) << " is smaller." << endl;
    }
}
