#include <iostream>
#include <vector>
#include <string.h>

class Answers {
    public:
        std::vector<std::string> yes;
        std::vector<std::string> no;
        std::vector<std::string> maybe;
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

};