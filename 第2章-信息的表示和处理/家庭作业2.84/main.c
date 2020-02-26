#include <stdio.h>
#include <assert.h>

/*
 * 填写下列程序的返回值，这个程序测试它的第一个参数是否小于或者等于第二个参数。假定函数
 * f2u 返回一个无符号32位数字，其位表示与它的浮点参数相同。你可以假设两个参数都不是
 * NaN。两种0，+0和-0被认为是相等的。
 *
 * */
unsigned f2u(float x)
{

}
int float_le(float x, float y)
{
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    /* Get the sign bits */
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    /* Give an expression using only ux,uy,sx, and sy */
    int is_le = 0;
    // 如果 x 是负数
    if (sx == 1 && sy == 0){
       is_le = 1;
    }
        // 如果 y 是负数
    else if (sx == 0 && sy == 1)
    {
        is_le = 0;
    } else if(sx == 0 && sy == 0)
    {
        is_le = ux <= uy;
    } else if(sx == 1 && sy == 1)
    {
        is_le = ux >= uy;
    }


    return is_le;
}
int main() {
    printf("Hello, World!\n");
    assert(float_le(-0, +0));
    assert(float_le(+0, -0));
    assert(float_le(0, 3));
    assert(float_le(-4, -0));
    assert(float_le(-4, 4));
    return 0;
}