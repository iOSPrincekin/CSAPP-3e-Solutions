#include <stdio.h>
#include <assert.h>

/* 你刚刚开始在一家公司工作，他们要实现一组过程来操作一个数据结构，要将4个有符号字节封装
 * 成一个32位unsigned。一个字中的字节从0（最低有效字节）编号到3（最高有效字节）。分配给你
 * 的任务是：为一个使用补码运算和算术右移的机器编写一个具有如下原型的函数：
 *
 * Declaration of data type where 4 bytes are packed
 * into an unsigned
 * typedef unsigned packed_t
 *
 * Exatract byte from word. Return as signed integer
 * int xbyte(packed_t word,int bytenum);
 *
 * 也就是说，函数会抽取出指定的字节，再把它符号扩展为一个32位int.
 * 你的前任（因为水平不够高而被解雇了）编写了下面的代码
 * */

typedef unsigned packed_t;
/* Failed attempt at xbyte */
int xbyte(packed_t word,int bytenum){
    return (word >> (bytenum << 3)) & 0xFF;
}
/* .这段代码错在哪里？
 * B.给出函数的正确实现，只能A使用左右移位和一个减法
 *
 * */
int xbyte_ok(packed_t word,int bytenum){
    /*
   * pay attention when byte we want is negetive
   *
   * Assume sizeof(unsigned) is 4
   * first shift left 8 * (4 - 1 - bytenum)
   * then arthemetic shift right 8 * (4 - 1) reserve signficant bit
   */
    int size = sizeof(unsigned);
    int shift_left_val = (size - 1 - bytenum) << 3;
    int shift_right_val = (size - 1) << 3;
    return (int) word << shift_left_val >> shift_right_val;
}

int main() {
    printf("Hello, World!\n");
    int x = sizeof(unsigned);
    printf("x---------::%d\n",x);
   // assert(xbyte(0xAABBCCDD, 1) == 0xFFFFFFCC);
    assert(xbyte(0xA0112233, 1) == 0x22);
    assert(xbyte(0x11112233, 3) == 0x11);

    assert(xbyte_ok(0xAABBCCDD, 1) == 0xFFFFFFCC);
    assert(xbyte_ok(0xAABB11DD, 1) == 0x


                   11);
    assert(xbyte_ok(0x00112233, 2) == 0x11);
    return 0;
}