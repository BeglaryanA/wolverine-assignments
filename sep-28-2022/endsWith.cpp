#include <iostream>
#include <string>

bool endsWith(std::string&, std::string);

int main() 
{

    std::string str = "hello, world";
    std::string  del = "rld";
    std::cout << std::boolalpha << endsWith(str, del);
    return 0;
}

bool endsWith(std::string& str, std::string del)
{
    return ((str.substr(str.size() - del.size(),str.size() - 1)) == del);
}