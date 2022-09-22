#include <iostream>

void cycl(int,int);

int main() 
{
    int n;
    std::cin >> n;
    int i = 0;
    cycl(n,i);
}

void cycl(int n,int i) 
{
    if (i == n) 
    {
        return;
    }
    std::cout << i << " "; 
    cycl(n,i + 1);
}
