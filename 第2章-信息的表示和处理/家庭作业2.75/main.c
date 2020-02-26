#include <stdio.h>
/*
 * 假设我们想要计算x•y的完整的2w位表示，其中，x和y都是无符号数，并且运行在数据类型
 * unsigned是w位的机器上。乘积的低w位能够用表达式x*y计算，所以，我们只需要一个具有下列原型的函数：
 * unsigned unsigned_high_prod(unsigned x,unsigned y);
 *
 * 这个函数计算无符号变量x•y的高w位。
 * 我们使用一个具有下面原型的库函数
 *
 * int signed_high_prod(int x,int y);
 *
 * 它计算在x和y采用补码形式的情况下，x•y的高w位。编写代码调用这个过程，以实现用无符号数
 * 为参数的函数。验证你的解答的正确性
 *
 * 提示：看看等式(2.18)的推导中，有符号乘积x•y和无符号乘积x'•y'之间的关系。
 *
 * */

#include <assert.h>




#include <inttypes.h>

int signed_high_prod(int x, int y) {
    int64_t mul = (int64_t) x * y;
    return mul >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
    /* TODO calculations */
    int sig_x = x >> 31;
    int sig_y = y >> 31;
    int signed_prod = signed_high_prod(x, y);
    return signed_prod + x * sig_y + y * sig_x;
}

/* a theorically correct version to test unsigned_high_prod func */
unsigned another_unsigned_high_prod(unsigned x, unsigned y) {
    uint64_t mul = (uint64_t) x * y;
    return mul >> 32;
}

int main(int argc, char* argv[]) {
    unsigned x = 0x12345678;
    unsigned y = 0xFFFFFFFF;

    assert(another_unsigned_high_prod(x, y) == unsigned_high_prod(x, y));
    return 0;
}