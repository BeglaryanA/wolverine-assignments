#include <iostream>
#include <string>

void toUpperCase(std::string&);

int main() 
{
    std::string str = "Hello";
    toUpperCase(str);
    std::cout << str;

    return 0;
}

void toUpperCase(std::string& str) 
{
    int size = str.size();
    for (int i = 0; i < size; ++i) 
    {
        if (str[i] >= 'a' && str[i] <= 'z') 
        {
            str[i] -= 32;
        }
    }
}