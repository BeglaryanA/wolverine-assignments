#include <iostream>
#include <string>

void replaceAll(std::string &,const std::string&, std::string);

int main()
{
    std::string str = "hello encaps example";
    std::string dest = "le";
    std::string t = "cj";
    int i = 0;
    replaceAll(str, dest, t);
    std::cout << str;
    return 0;
}

void replaceAll(std::string& str, const std::string& dest, std::string src)
{
    int i = 0;
    while (i != str.size())
    {
        int pos = str.find(dest, i);
        if (pos != -1) 
        {
            str.erase(str.begin() + pos,str.begin() + pos + dest.size());
            str.insert(pos, src);
            i = pos;
        }
        ++i;
    }
}