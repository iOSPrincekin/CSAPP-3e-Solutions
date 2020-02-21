#include <stdio.h>
#include <stdbool.h>
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start,size_t len)
{
    size_t i;
    for (i = 0; i < len; i++) {
        printf(" %.2x",start[i]);
    }

    printf("\n");
}
bool int_shifts_are_arithmetic()
{
    int x = -1;
    return  !(~(x >> ((sizeof(int)-1) << 3)));
}
int main() {
    printf("Hello, World!\n");
    printf("int_shifts_are_arithmetic------::%d",int_shifts_are_arithmetic());
    return 0;
}