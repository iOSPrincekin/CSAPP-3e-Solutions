#include <stdio.h>
#include <stdbool.h>
/**
 写出一个C表达式，在下列描述的条件下产生1，而在其他情况下得到0。假设x是int类型
 A.x的任何位都等于1.
 B.x的任何位都等于0.
 C.x的最低有效字节中的位都等于1.
 D.x的最高有效字节中的位都等于0.
 代码应该遵循位级整数编码规则，另外还有一个限制，你不能使用(==)和不相等(!=)测试
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
void show_int(int x)
{
    printf("int类型的字长是----%d\n", sizeof(int));
    show_bytes((byte_pointer)&x, sizeof(int));
}
bool A(int x){
    return !(~x);
}
bool B(int x){
    int y = -1;
    return !(y & x);
}
bool C(int x){
    byte_pointer start = &x;
    show_int(*start ^ 0xFF);
    return !(*start ^ 0xFF);
}
bool D(int x){
    byte_pointer start = &x;
    int w = sizeof(int);
    show_int(start[w-1]);
    return !(start[w-1] ^ 0xFF);
}
bool D1(int x){
    int w = sizeof(int);
    show_int(x >> ((w-1) << 3));
    return !(~(x >> ((w-1) << 3)));
}
int main() {
    printf("Hello, World!\n");
    int x = -1;
    show_int(x);
    printf("x的值是：：%d,x的所有位都是1：：%d\n",x,A(x));
    x = 0x01;
    show_int(x);
    printf("x的值是：：%d,x的所有位都是0：：%d\n",x,B(x));
    x = 0xeeeff;
    show_int(x);
    printf("x的值是：：%d,x的最低有效字节中的位都等于1：：%d\n",x,C(x));
    x = 0xffff0000;
    show_int(x);
    printf("x的值是：：%d,x的最高有效字节中的位都等于1：：%d\n",x,D1(x));
    return 0;
}