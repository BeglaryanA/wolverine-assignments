#include <iostream>
#include <vector>

std::vector<std::string> split(std::string& str, std::string del);

int main()
{
    std::string str = "he ,ll:o world,vui";
    std::string del = ",:";
    std::vector<std::string> vec = split(str,del);
    for (auto it : vec) 
    {
        std::cout << it << std::endl;
    }
}

std::vector<std::string> split(std::string& str, std::string del) 
{
    std::vector<std::string> vec;
    int j = 0;
    int pos = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if ((pos = del.find(str[i], j)) >= 0)
        {
            j = i;
            vec.push_back(str.substr(0, j));
            str.erase(str.begin(), str.begin() + j + 1);
            i = 0;
            j = 0;
        }
    }
    vec.push_back(str);
    return vec;
}