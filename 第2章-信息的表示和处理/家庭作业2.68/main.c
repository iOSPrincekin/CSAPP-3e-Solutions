#include <stdio.h>
#include <assert.h>

/* 写出具有以下原型的函数的代码：
 *
 *  Mask with least signficant n bits set to 1
 *  Examples: n = 6 --> 0x3F, n = 17 --> 0x1FFFF
 *  Assume 1 <= n <= w
 *  int lower_one_mask(int n)
 *  函数应该遵循位级整数编码规则。要注意 n=w 的情况
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









int lower_one_mask(int n){
    int w = sizeof(int) << 3;
    unsigned x = -1;
    return x >> (w - n);
}
int main() {
    printf("Hello, World!\n");
    int x1 = lower_one_mask(6);
    show_bytes((byte_pointer)&x1, sizeof(int));
    int x2 = lower_one_mask(17);
    show_bytes((byte_pointer)&x2, sizeof(int));
    int x3 = lower_one_mask(32);
    show_bytes((byte_pointer)&x3, sizeof(int));
    assert(lower_one_mask(6) == 0x3F);
    assert(lower_one_mask(17) == 0x1FFFF);
    assert(lower_one_mask(32) == 0xFFFFFFFF);
    return 0;
}