#include <iostream>
#include <string>
#include <regex>

using namespace std;

string trim(string &str) {
    regex rgx("\\s+?", regex_constants::ECMAScript);
    cout << (regex_search(str, rgx)) << endl;
}

int main() {
    string text("Hello  world!");
    trim(text);
}