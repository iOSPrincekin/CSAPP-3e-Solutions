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
bool is_little_endian(){
    short x = 1;
    byte_pointer start = &x;
    size_t len = sizeof(short);
    size_t i;

    for (i = 0; i < len; i++) {
        printf(" %.2x",start[i]);
    }
    printf("\n");

    //printf("start[1]=====：：%d",start[1]);
    size_t j;
for (j = 0; j < len; j++) {
    printf(" %d\n",start[j]);
}
return *start == 1;

};
int main() {
printf("是不是小端法------：：%d\n", is_little_endian());
printf("Hello, World!\n");
return 0;
}