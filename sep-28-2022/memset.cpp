#include <iostream>

void memset(void*, char, size_t);

int main() {
    char arr[] = "hello world, i said hello wolrd";
    memset(arr + 5, '1', 5);
    std::cout << arr;
    return 0;
}

void memset(void* ptr, char val, size_t count) {
    char* p = (char*) ptr;
    for (int i = 0; i <= count; ++i) {
            *(p + i) = val; 
    }
}   