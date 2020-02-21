#include <stdio.h>

/* Generate mask indicating leftmost 1 in x. Assume w=32.
 * For example, 0xFF00 -> 0x8000, and 0x6600 -> 0x4000.
 * If x = 0, then return 0.
 * 函数应该遵循位级整数编码规则，不过你可以假设数据类型int有w=32位。
 * 你的代码最多只能包含15个算术运算、位运算和逻辑运算。
 * 提示：先将x转换为形如[0...011...1]的位向量
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
int leftmost_one(unsigned x)
{
    // 首先将最左侧的1后面的位全部置为1，例如0x6600 -> 0x7FFF
    x |= x>>1;
    x |= x>>2;
    x |= x>>4;
    x |= x>>8;
    x |= x>>16;

    return (x >> 1) + (x && 1);
}


int main() {
    printf("Hello, World!\n");
    int x = 0x0;
    show_bytes((byte_pointer)&x, sizeof(int));
    int y = leftmost_one(x);
    show_bytes((byte_pointer)&y, sizeof(int));
    return 0;
}