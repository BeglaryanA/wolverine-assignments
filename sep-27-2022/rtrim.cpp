#include <iostream>

std::string rtrim(std::string& );

int main()
{
    std::string str = "hello   ";
    rtrim(str);
    std::cout << str;
    return 0;
}

std::string rtrim(std::string& str)
{
    int i = str.size() - 1;
    while (str[i] == ' ') 
    {
        str.erase(i,1);
        --i;
    }
    return str;
}