#include <stdio.h>
/*
 *  遵循位级浮点编码规则，实现具有如下原型的函数：
 *  Compute -f. If f is NaN, then return f.
 *  float_bits float_negate(float_bits f);
 *
 *  对于浮点数f，这个函数计算-f。如果f是NaN，你的函数应该简单地返回f。
 *  测试你的函数，对参数f可以取的所有2^32个值求值，将结果与你使用机器的浮点运算
 *  得到的结果相比较
 *
 * */

typedef unsigned float_bits;
float_bits float_negate(float_bits f){
    /* Decompose bit representation into parts */
    unsigned sign = f>>31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f      & 0x7FFFFF;
    int is_NAN = (exp == 0xFF) && (frac != 0);
    if (is_NAN)
    {
        return f;
    }
    /* Reassemble bit */
    return ~sign << 31 | exp << 23 | frac;
}
int main() {
    printf("Hello, World!\n");
    return 0;
}