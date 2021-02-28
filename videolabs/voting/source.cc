#include <iostream>
#include <stdio.h>
#include <regex>

using namespace std;

string query(string prompt) {
    string res;
    cout << prompt;
    cin >> res;
    return res;
}

bool queryBool(string prompt, string yes) {
    return query(prompt).compare(yes) == 0;
}

bool isInteger(string str) {
    return regex_match(str, regex("^(-|)[0-9]+?$"));
}

int queryInt(string prompt) {
    int res;
    string queryRes;

    queryRes = query(prompt);
    while (! isInteger(queryRes)) {
        cout << "Input must be a number." << endl;

        queryRes = query(prompt);
    }
    res = stoi(queryRes);

    return res;
}

int main(int argc, char const *argv[]) {
    bool isUSCitizen (queryBool("Are you a U.S. citizen? (Y/n) ", "Y"));
    int  age(queryInt("How old are you? "));

    if (isUSCitizen && age >= 18)
        cout << "You are able to vote." << endl;
    else
        cout << "You are unable to vote." << endl;
}
