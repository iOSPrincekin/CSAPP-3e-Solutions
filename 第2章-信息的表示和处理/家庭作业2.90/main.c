#include <stdio.h>
#include <assert.h>
#include <math.h>

float u2f(unsigned x) {
    return *(float*) &x;
}
/*
 *  分配给你一个任务，编写一个C函数来计算2^x的浮点表示。你意识到完成这个任务的最好办法是
 *  直接创建结果的IEEE单精度表示。当x太小时，你的程序将返回0.0。当x太大时，它会返回+无穷大。
 *  填写下列代码的空白部分，以计算正确的结果。假设函数u2f返回的浮点值与它的无符号
 *  参数有相同的位表示。
 *
 *
 * */
float u2f(unsigned x);

float fpwr2(int x) {
    /* Result exponent and fraction */
    unsigned exp, frac;
    unsigned u;
    int bias = pow(2,7)-1;

    if (x < 1-bias -23) {
     /* Too small. Return 0.0 */
        exp = 0;
        frac = 0;
    } else if (x < 1-bias)
    {
      /* Denormalized result */
        exp = 0;
        frac = 1 << (unsigned)(x - 2 + pow(2,7) + 23);
    }else if(x < pow(2,7))
    {
        /* Normalized result */
        exp = bias + x;




        frac = 0;

    }else
    {
        /* Too big. Return +无穷大 */
        exp = pow(2,8)-1;
        frac = 0;

    }

    /* Pack exp and frac into 32 bits */
    u = exp << 23 |frac;
    /* Return as float */
    return u2f(u);
}
int main() {
    printf("Hello, World!\n");
    assert(fpwr2(0) == powf(2,0));
    assert(fpwr2(100) == powf(2,100));
    assert(fpwr2(-100) == powf(2,-100));
    assert(fpwr2(10000) == powf(2,10000));
    assert(fpwr2(-10000) == powf(2,-10000));
    return 0;
}