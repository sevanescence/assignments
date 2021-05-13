#include <iostream>
#include <string>

using namespace std;

class StringSequenceIterator {
    private:
        int seq_count;
        char *sequences;
        string input;
        int current;
    public:
        StringSequenceIterator(string _input, char *_sequences) {
            input = _input;
            sequences = _sequences;
            seq_count = getOccurences();
            current = 0;
        }
        bool isOccurence(char _c) {
            for (int i = 0; sequences[i] != '\0'; i++) {
                if (_c == sequences[i])
                    return true;
            }
            return false;
        }
        int getOccurences() {
            int count = 0;
            string::iterator it;
            for (it = input.begin(); it != input.end(); ++it) {
                if (isOccurence(*it))
                    count++;
            }
            return count;
        }
        int count() {
            return seq_count;
        }
        char next() {
            for (current += 1; current < input.size(); current++) {
                if (isOccurence(input.at(current))) {
                    return input.at(current);
                }
            }
        }
};

int main() {
    cout << "Enter a string: ";
    string str;
    getline(cin, str);
    char sequence [] = "aeiou";
    StringSequenceIterator it(str, sequence);
    char c;
    while ((c = it.next()) != '\0') {
        cout << c;
    }
    cout << " " << it.count() << endl;
}
