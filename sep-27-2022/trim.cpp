#include <iostream>

std::string trim(std::string&);

int main () 
{
    std::string str = "  hello  ";
    trim(str);
    std::cout << str;
}

std::string trim(std::string& str)
{
    std::string res = "";
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] != ' ') 
        {
            res += str[i];
        }
    }
    str = res;
    return str;
}
