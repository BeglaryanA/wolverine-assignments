#include <iostream>
#include <map>

double plus(double, double);
double minus(double, double);
double mul(double, double);
double div(double, double);

int main()
{
    std::map<char, double (*) (double,double)> operation;
    double num_1;
    double num_2;
    std::cin >> num_1;
    std::cin >> num_2;
    char c;
    std::cin >> c;
    operation['+'] = plus;
    operation['-'] = minus;
    operation['*'] = mul;
    operation['/'] = div;
    std::cout << operation[c](num_1,num_2);
}

double plus(double num_1, double num_2)
{
    return num_1 + num_2;
}

double minus(double num_1, double num_2)
{
    return num_1 - num_2;
}

double mul(double num_1, double num_2)
{
    return num_1 * num_2;
}

double div(double num_1, double num_2)
{
    if (num_2 == 0)
    {
        std::cout << "Error! Can't divide number in 0!!" << std::endl;
        return 0;
    }
    return num_1 / num_2;
}
