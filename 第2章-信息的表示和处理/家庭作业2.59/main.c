#include <stdio.h>
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start,size_t len)
{
    size_t i;
    for (i = 0; i < len; i++) {
        printf(" %.2x",start[i]);
    }

    printf("\n");
}

int getLow(int x)
{
    return x & 0xFF;
}
int getHigh(int y)
{
    return (y>>8) << 8;
}
int combine(int x,int y)
{
    return x | y;
}
int main() {
    printf("Hello, World!\n");
    int x = 0x89ABCDEF;
    show_bytes((byte_pointer)&x, sizeof(int));
    int y = 0x76543210;
    show_bytes((byte_pointer)&y, sizeof(int));
    int x1 = getLow(x);
    int y1 = getHigh(y);
    int z = combine(x1,y1);
    show_bytes((byte_pointer)&z, sizeof(int));
    return 0;
}