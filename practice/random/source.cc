#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

int main(void) {
    srand(time(nullptr));

    int num;
    
    num = rand();
    cout << num << endl;

    char reroll;
    cout << "Do you want to re-roll your number? (Y/n) ";
    cin >> reroll;
    if (reroll == 'Y') {
        cout << rand() << endl;
        return 0;
    }

    cout << num << endl;

    return 0;
}
