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
unsigned replace_byte(unsigned x,int i, unsigned char b)
{
    int x1 = x & (0xFFFFFFFF ^ 0xFF << i * 8);
    show_bytes((byte_pointer)&x1, sizeof(int));
    int b1 = b << i * 8;
    return x1 | b1;
}
unsigned replace_byte1(unsigned x,int i, unsigned char b)
{
    int x1 = x &  ~(0xFF << (i << 3));
    show_bytes((byte_pointer)&x1, sizeof(int));
    int b1 = b << (i << 3);
    return x1 | b1;
}
int main() {
    printf("Hello, World!\n");
    int y = replace_byte1(0x12345678,2,0xAB);
    show_bytes((byte_pointer)&y, sizeof(int));

    int z = replace_byte1(0x12345678,0,0xAB);
    show_bytes((byte_pointer)&z, sizeof(int));

    int d = replace_byte1(0x12345678,3,0xAB);
    show_bytes((byte_pointer)&d, sizeof(int));

    return 0;
}