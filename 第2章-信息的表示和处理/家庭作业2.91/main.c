#include <stdio.h>
/*
 *  大约公元前250年，希腊数学家阿基米德证明了 223/71 < π < 22/7。如果当时有一台计算机和标准库
 *  <math.h>,他就能确定π的单精度浮点近似值的十六进制表示为0x40490FDB。当然，所有的这些都只是
 *  近似值，因为π不是有理数
 *  A.这个浮点值表示的二进制小数是多少？
 *  B.22/7的二进制小数表示是什么？提示：参见家庭作业2.83
 *  C.这两个π的近似值从哪一位(相对于二进制小数点)开始不同的？
 *
 *
 * */
/*
 *  A.这个浮点值表示的二进制小数是多少？
 *  0b01000000010010010000111111011011
 *
 *  ob11.0010010000111111011011
 *
 *
 * */

/*
 *  B.22/7的二进制小数表示是什么？提示：参见家庭作业2.83
 *  3(1/7) =>
 *  11.001001001001...
 *
 * */

/*
 *  C.这两个π的近似值从哪一位(相对于二进制小数点)开始不同的？
 *
 *  9th
 *
 *
 *
 * */


/*
 *
 *   位级浮点编码规则
 *   在接下来的题目中，你所写的代码要实现浮点函数在浮点数的位级表示上直接运算。你的代码应该
 *   完全遵循IEEE浮点运算的规则。包括当需要舍入时，要使用向偶数舍入的方式。
 *   为此，我们把数据类型float-bits等价于unsigned：
 *
 *   Access bits-level representation floating-point number
 *
 *   typedef unsigned float_bits;
 *
 *   你的代码中不使用数据类型float，而要使用float_bits。你可以使用数据类型int和unsigned，
 *   包括无符号和整数常数和运算。你不可以使用任何联合、结构和数组。更重要的是，你不能使用任何浮点
 *   数据类型、运算或者常数。取而代之，你的代码应该执行实现这些指定的浮点运算的位操作。
 *   下面的函数说明了对这些规则的使用。对于参数f，如果f是非规格化的，你的函数返回+-0(保持f的符号)，
 *   否则返回f。
 *
 *
 *
 *
 * */

typedef unsigned float_bits;

/* If f is denorm, return 0, Otherwise, return f */
float_bits float_denorm_zero(float_bits f)
{
    /* Decompose bit representation into parts */
    unsigned sign = f>>31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f      & 0x7FFFFF;
    if (exp == 0)
    {
        /* Denormalized. set fraction to 0 */
        frac = 0;
    }
    /* Reassemble bit */
    return (sign << 31) | (exp << 23) | frac;
}
int main() {
    printf("Hello, World!\n");
    return 0;
}