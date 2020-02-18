#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


#define M           /* Mystery number 1 */
#define N           /* Mystery number 2 */
int arith(int x,int y)
{
    int result = 0;
    result = x * M + y/N;   /* M and N are mystery numbers. */
    return result;
}

/* Translation of assembly code for arith */
int optarith(int x, int y)
{
    int t = x;
    x << 5;
    x -= t;
    if (y < 0) y += 7;
    y >> 3;  /* Arithmetic shift */
    return x + y;
}