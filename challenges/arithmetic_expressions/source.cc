#include <iostream>
#include <stdio.h>
#include <array>     // std::array
#include <algorithm> // std::for_each

using namespace std;


int main(int argc, char const *argv[]) {
    double sum = 0,
           res = 0,
           prd = 1,
           div = 1;
    array<int, 4> nums = { };

    for (int i = 0; i < nums.size(); i++) {
        cout << "Enter a number: ";
        cin >> nums.at(i);
    }
    sum = nums.at(0);
    res = nums.at(0);
    prd = nums.at(0);
    div = nums.at(0);

    bool first = true;
    for_each(nums.begin(), nums.end(), [&](int n) {
        if (first) {
            first = false;
            return;
        }

        sum += n;
        res -= n;
        prd *= n;
        div /= n;
    });

    cout   << "Sum:      " << sum
         << "\nResult:   " << res
         << "\nProduct:  " << prd
         << "\nDividend: " << div << endl;
}
