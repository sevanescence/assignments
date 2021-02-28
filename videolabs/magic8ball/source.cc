#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <vector>
#include <string.h>

class Answers {
    public:
        std::vector<std::string> yes, no, maybe;
        Answers() {
            yes.push_back("It is certain.");
            yes.push_back("It is decidedly so.");
            yes.push_back("Without a doubt");
            yes.push_back("Yes, definitely.");
            yes.push_back("You may rely on it.");
            yes.push_back("As I see it, yes");
            yes.push_back("Most likely");
            yes.push_back("Outlook good.");
            yes.push_back("Yes.");
            yes.push_back("Signs point to yes.");

            no.push_back("Reply hazy, try again.");
            no.push_back("Ask again later.");
            no.push_back("Better not tell you now.");
            no.push_back("Cannot predict now.");
            no.push_back("Concentrate and ask again.");

            maybe.push_back("Don't count on it.");
            maybe.push_back("My reply is no.");
            maybe.push_back("My sources say no.");
            maybe.push_back("Outlook not so good.");
            maybe.push_back("Very doubtful.");
        }

}; // dont judge me, i cant figure out header files

int random(int max);

int main() {
    Answers answers;
    std::srand(std::time(nullptr));
    
    std::cout << "Ask a question: ";
    std::cin.get();
    
    int roll (random(4));
    switch (roll) { // i absolutely refuse to do 20 switch cases, so instead ill spend just as much time doing it a different way.
        case 0:
        case 1:
            std::cout << answers.yes.at(random(answers.yes.size())) << std::endl;
            break;
        case 2:
            std::cout << answers.no.at(random(answers.no.size())) << std::endl;
            break;
        default:
            std::cout << answers.maybe.at(random(answers.maybe.size())) << std::endl;
            break;
    }
    std::cin.clear();
    std::cin.ignore(123, '\n');
    main();
}

int random(int max) {
    return std::rand() % max;
}