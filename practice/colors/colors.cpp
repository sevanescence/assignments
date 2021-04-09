#include <iostream>
#include <string>
#include <regex>

namespace colors {
    class ColoredText {
        private:
            std::string text;
        public:
            ColoredText(std::string text) {
                this->text = text;
            }
            std::string sanitize() const {
                std::regex match { "%([0-9]{1,2})" };
                std::string result;
                std::regex_replace(std::back_inserter(result), this->text.begin(), this->text.end(), match, "\033[1;$1m");
                return result;
            }
    };
    inline std::ostream& operator<<(std::ostream& os, colors::ColoredText const& obj) {
        os << obj.sanitize();
        return os;
    }
}
