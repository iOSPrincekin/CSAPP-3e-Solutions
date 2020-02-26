#include <stdio.h>
#include <assert.h>

/* 写出具有如下原型的函数的代码
 * Do rotating left shift. Assume 0 <= n < w
 * Example when x = 0x12345678 and w = 32:
 *   n=4 -> 0x23456781, n=20 -> 0x67812345
 *
 * unsigned rotate_left(unsigned x,int n);
 * 函数应该遵循位级整数编码规则。要注意 n=0 的情况
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

unsigned rotate_left(unsigned x,int n){
    int w = sizeof(int) << 3;
    int y = x << n;
    /* pay attention when n == 0 */
    x >>= w - n -1;
    x >>= 1;
    return x | y;
}



int main() {

    printf("Hello, World!\n");
    assert(rotate_left(0x12345678, 4) == 0x23456781);
    assert(rotate_left(0x12345678, 20) == 0x67812345);
    int x = 1 << 32;
    show_bytes((byte_pointer)&x, sizeof(int));

    return 0;
}