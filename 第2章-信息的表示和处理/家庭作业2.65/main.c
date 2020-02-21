#include <stdio.h>

/*
  Return 1 when x contains an odd number of 1s; 0 otherwise.
  Assume w = 32
  int odd_ones(unsigned x);

  函数应该遵循位级整数编码规则，不过你可以假设数据类型int 有 w=32位。
  你的代码最多只能包含12个算术运算、位运算和逻辑运算。
 * */

/** 解题：这题意思是：如果二进制数x包含奇数个1则返回1，包含偶数个1则返0
 *  解题思路：把二进制数x当做一个包含0和1的集合，因为要求的是1的个数是奇数还是偶数，而不是具体的个数，所以拿集合中的任意2个1配对，则抵消，如果找不到
 *  配对的1，则记为1，对应的运算是EXCLUSIVE-OR
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
int odd_number(unsigned x) {
    show_bytes((byte_pointer)&x, sizeof(int));
    unsigned y = (x >> 16);
    show_bytes((byte_pointer)&y, sizeof(int));
    x = x ^ (x >> 16);
    show_bytes((byte_pointer)&x, sizeof(int));
    x = x ^ (x >> 8);
    show_bytes((byte_pointer)&x, sizeof(int));
    x = x ^ (x >> 4);
    show_bytes((byte_pointer)&x, sizeof(int));
    x = x ^ (x >> 2);
    show_bytes((byte_pointer)&x, sizeof(int));
    x = x ^ (x >> 1);
    show_bytes((byte_pointer)&x, sizeof(int));

    return x & 0x1;
}
int main() {
    printf("Hello, World!\n");
    int x = 0xAAAAAAAA;
    int y = odd_number(x);
    printf("y------::%d\n",y);
    return 0;
}