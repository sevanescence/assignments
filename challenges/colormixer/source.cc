#include <iostream>
#include <string>
#include <map>
#include <locale> // toupper

// Makoto Miyamoto
// COSC 1436

bool stringArrayContains(std::string *strings, int arrSize, std::string value) {
    for (int i = 0; i < arrSize; i++) {
        if (value.compare(strings[i]) == 0)
	    return true;
    }
    return false;
}

std::string toUpperCase(std::string str) {
    std::locale loc;
    for (std::string::size_type i = 0; i < str.length(); i++) {
        str[i] = std::toupper(str[i], loc);
    }
    return str;
}

std::string queryStrictIgnoreCase(std::string prompt, std::string *options, int arrSize) {
    std::cout << prompt;
    std::string res;

    bool done = false;
    while (! done) {
	std::cin >> res;
	res = toUpperCase(res);

	if (! stringArrayContains(options, arrSize, res)) {
	    std::cout << res  << " not in list of options." << std::endl;
	    std::cout << prompt;
	} else done = true;
    }

    return res;
}

int main() {
    std::map<std::string, int> primaryColorCodes {{"RED", 1}, {"YELLOW", 3}, {"BLUE", 5}};
    std::map<int, std::string> secondaryColors {{4, "Orange"}, {6, "Violet"}, {8, "Green"}};

    std::string firstColor, secondColor;
    std::string options[3] = {"RED", "YELLOW", "BLUE"};

    firstColor = queryStrictIgnoreCase("Pick a color (RED, YELLOW, BLUE): ", options, 3);
    secondColor = queryStrictIgnoreCase("Pick another color (RED, YELLOW, BLUE): ", options, 3);

    int firstCode(primaryColorCodes.at(firstColor));
    int secondCode(primaryColorCodes.at(secondColor));

    std::string secondaryColor = secondaryColors.at(firstCode + secondCode);

    std::cout << "Your color is: " << secondaryColor << "!" << std::endl;
}
