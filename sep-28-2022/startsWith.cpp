#include <iostream>

bool startsWith(std::string&, std::string);

int main() 
{
    std::string str = "hello, world!";
    std::string del = "he";
    std::cout << std::boolalpha << startsWith(str, del);
    return 0;
}

bool startsWith(std::string& str, std::string del) 
{
    return ((str.substr(0,del.size())) == del);
}