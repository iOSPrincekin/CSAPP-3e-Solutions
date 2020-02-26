#include <stdio.h>
/*  给你一个任务，编写一个过程int_size_is_32(),当在一个int是32位的机器上运行时，该程序
 * 产生1，而其他情况则产生0。不允许使用sizeof运算符。下面是开始时的尝试
 * */
/* The following code dose not run properly on some machines */
int bad_int_size_is_32(){
    /* Set most of significant bit (msb) of 32-bit machine */
    int set_msb = 1 << 31;
    /* Shift past msb of 32-bit word */
    int beyond_msb = 1 << 32;

    /* set_msb is nonzero when word size >= 32
       beyond_msb is zero when word size <= 32 */
    return set_msb && !beyond_msb;
}

int int_size_is_32(){
    /* Set most of significant bit (msb) of 32-bit machine */
    int mask = 0xFFFF;
    int x = -1;
    x ^= mask;
    x ^= mask << 16;
    /* set_msb is nonzero when word size >= 32
       beyond_msb is zero when word size <= 32 */
    return !(x);
}

int int_size_is_32_new() {
    int set_msb = 1 << 31;
    int beyond_msb = set_msb << 1;

    return set_msb && !beyond_msb;
}

int int_size_is_32_for_16bit() {
    int set_msb = 1 << 15 << 15 << 1;
    int beyond_msb = set_msb << 1;

    return set_msb && !beyond_msb;
}

/* 当在SUN SPARC 这样的32位机器上编译并运行时，这个过程返回的却是0。下面的编译器给了我们一个问题的指示
 * warning: left shift count >= width of type
 *
 * A.我们的代码在哪个地方没有遵循C语言标准 : 移位量应该是一个0~w-1的值（If the value of the right operand is negative or is greater than or
 * equal to the width of the promoted left operand, the behavior it undefined.）
 *
 * B.修改代码，使得它在int至少为32位的任何机器上都能正确地运行
 * C.修改代码，使得它在int至少为16位的任何机器上都能正确地运行
 * */

int main() {
    printf("Hello, World!\n");
    int bad = bad_int_size_is_32();
    printf("bad----------::%d\n",bad);
    int good = int_size_is_32();
    printf("good----------::%d\n",good);
    return 0;

}