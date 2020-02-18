#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

/* Determine whether the arguments can be multiplied without overflow */
int tmult_ok(int x, int y)
{
    /* Compute product without overflow */
    int64_t pll = (int64_t) x*y;
    /* See if casting to int preserves value */
    return pll == (int) pll;
}