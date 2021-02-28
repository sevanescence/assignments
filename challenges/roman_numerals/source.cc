#include <iostream>
#include <string.h>

class Roman {
    public:
        std::string numerals [10];
        Roman() {
            numerals[0] = "I";
            numerals[1] = "II";
            numerals[2] = "III";
            numerals[3] = "IV";
            numerals[4] = "V";
            numerals[5] = "VI";
            numerals[6] = "VII";
            numerals[7] = "VIII";
            numerals[8] = "IX";
            numerals[9] = "X";
        }
};

std::string getRoman(Roman roman);

int main() {
    Roman roman;
    std::cout << getRoman(roman) << std::endl;
}

std::string getRoman(Roman roman) {
    int number;
    
    std::cout << "Pick a number: ";
    if (! (std::cin >> number)) {
        std::cout << "Input must be an integer." << std::endl;
        std::cin.clear();
        std::cin.ignore(123, '\n');
        return getRoman(roman);
    }

    switch (number) { // still used a switch :)
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            return roman.numerals[number-1];
            break;
        default:
            return "I was told to handle numbers out of the range of 1-10";
            break;
    }
}