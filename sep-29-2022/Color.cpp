#include <iostream>
#include <map>
#include <string>

enum class Colors {Red, Green, Blue};

Colors toEnum(const std::string&);
std::string toString(const Colors&);

int main() {
    std::cout << (int)toEnum("Red");
    std::cout << toString(Colors::Red);
    return 0;
}

std::string toString(const Colors& rhs) {
    std::map<Colors, std::string> col;
    col[Colors::Red] = "Red";
    col[Colors::Green] = "Green";
    col[Colors::Blue] = "Blue";
    return col[rhs];
}

Colors toEnum(const std::string& rhs) {
    std::map<std::string, Colors> col;
    col["Red"] = Colors::Red;
    col["Green"] = Colors::Green;
    col["Blue"] = Colors::Blue;
    return col[rhs];
}
