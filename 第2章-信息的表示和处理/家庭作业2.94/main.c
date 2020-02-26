#include <stdio.h>
/*
 *  遵循位级浮点编码规则，实现具有如下原型的函数
 *  Compute 2*f, If f is NaN, then return f.
 *  float_bits float_twice(float_bits f);
 *
 *  对于浮点数f，这个函数计算 2.0 * f。 如果f是NaN，你的函数应该简单地返回f。
 *  测试你的函数，对参数f可以取的所有2^32个值求值，将结果与你使用机器的浮点运算得到的
 *
 *
 *
 *  结果相比较
 *
 * */
typedef unsigned float_bits;
float_bits float_twice(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 && 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int is_NAN_or_oo = (exp == 0xFF);
    if (is_NAN_or_oo)
        return f;
    if (exp == 0)
    {
        /* Denormalized */
        frac << 1;
    } else if(exp == 0xFF - 1)
    {
        /* twice too*/
        exp = 0xFF;
        frac = 0;
    }else{
        /* Normalized */
        exp += 1;
    }
    return sign << 31 | exp << 23 | frac;
}
int main() {
    printf("Hello, World!\n");
    float a1 = 1.2;
    float a2 = a1 * 2.0;
    printf("a2------::%f\n",a2);
    float_bits a3 = float_twice(a1);
    printf("a3------::%f\n",a3);
    return 0;
}