#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


int div16(int x)
{
    /* Compute bias to be better either 0 (x >= 0) or 15 (x < 0) */
    int bias = (x>>31) & 0xF;
    return (x + bias) >> 4;
}