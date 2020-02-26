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

void show_short(short x)
{
    printf("short类型的字长是----%d\n", sizeof(short));
    show_bytes((byte_pointer)&x, sizeof(short));
}
void show_int(int x)

{
    printf("int类型的字长是----%d\n", sizeof(int));
    show_bytes((byte_pointer)&x, sizeof(int));
}
void show_long(long x)
{
    printf("long类型的字长是----%d\n", sizeof(long));
    show_bytes((byte_pointer)&x, sizeof(long));
}
void show_double(double x)
{
    printf("double类型的字长是----%d\n", sizeof(double));
    show_bytes((byte_pointer)&x, sizeof(double));
}


int main() {
    printf("Hello, World!\n");
    short x = 7;
    show_short(7);
    long  y = 7;
    show_long(y);
    double z = 7.1;
    show_double(z);
    return 0;
}