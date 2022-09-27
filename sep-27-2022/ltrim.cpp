#include <iostream>

std::string ltrim(std::string&);

int main() 
{
    std::string str = " hello";
    ltrim(str);
    std::cout << str;
    return 0;
}

std::string ltrim(std::string& str)
{
    int i = 0;
    for (int i = 0; str[i] == ' '; ++i) 
    {
        str.erase(str.begin() + i);
        --i;
    }
    return str;
}