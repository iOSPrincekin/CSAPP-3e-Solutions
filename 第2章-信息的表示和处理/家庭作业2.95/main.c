#include <stdio.h>
/*
 * 遵循位级浮点编码规则，实现具有如下原型的函数
 * Compute 0.5*f. If f is NaN, then return f.
 * float_bits float_half(float_bits f);
 * 对于浮点数f，这个函数计算0.5 *f。如果f是NaN，你的函数应该简单返回f。
 * 测试你的函数，对参数f可以简单取的所有2^32个值求值，将结果与你使用机器的浮点运算得到的结果
 * 相比较
 *
 *
 * */

typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start,size_t len)
{
    size_t i;
    for (i = 0; i < len; i++) {
        printf(" %.2x",start[i]);
    }

    printf("\n");
}
void show_float(int x)
{
    printf("float类型的字长是----%d\n", sizeof(float));
    show_bytes((byte_pointer)&x, sizeof(float));
}


typedef unsigned float_bits;
float_bits float_half(float_bits f){
    unsigned sign = f >> 31;
    unsigned rest = f & 0x7FFFFFFF;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int is_NaN_or_oo = (exp == 0xFF);
    if (is_NaN_or_oo)
    {
        return f;
    }
    /*
     *  为了遵循位级浮点编码规则，我们应该向偶数舍入，0.5 相当于将小数位frac右移1位，有些情况会产生精度损失，应该按照向偶数舍入的规则舍入
     *
     *   我们只看frac的最后两位，即可概括所有情况
     *   我们将frac的值即为v，frac的1-22的值记为y，末尾位的值记为 x
     *   则 v = y + x；
     *   v / 2 = y / 2 + x / 2;
     *
     *   00    v = y + 0;    v/2 = y/2+0 = y/2 向右移动1位没有精度损失，不需要向偶数舍入
     *   01    v = y + 1;    v/2 = y/2+1/2     向右移动1位后有精度损失，为 1/2，因为此时末尾位为0，为偶数，不需要再向偶数舍入
     *   10    v = y + 0;    v/2 = y/2+0 = y/2 向右移动1位没有精度损失，不需要向偶数舍入
     *   11    v = y + 1;    v/2 = y/2+1/2     向右移动1位后有精度损失，为 1/2，因为此时末尾位为1，为奇数，需要再向偶数舍入，需要>>1后+1
     * */
    int addition = (frac & 0x3) == 0x3;
    if (exp == 0)
    {
        /* Denormalized */
        frac >>= 1;
        frac += addition;
    }else if(exp == 1)
    {
        /* Normalized to denormalized */
        rest >>= 1;
        rest += 1;
        exp = rest >> 23 & 0xFF;
        frac = rest & 0x7FFFFF;
    }else{
        /* Normalized */
        exp -= 1;

    }
    return  sign << 31 | exp << 23 | frac;
}
int main() {
    printf("Hello, World!\n");
    float a1 = 000.000111;
    show_float(a1);
    float a2 = a1 * 0.5;
    printf("a2------::%f\n",a2);
    float_bits a3 = float_half(a1);
    printf("a3------::%f\n",a3);
    return 0;
}