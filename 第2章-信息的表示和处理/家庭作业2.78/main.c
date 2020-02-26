#include <stdio.h>
#include <assert.h>
#include <limits.h>

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
/*
 *  写出具有如下原型的函数的代码：
 *
 *  Divide by power of 2. Assume 0 <= k < w-1
 *  int divide_power2(int x, int k);
 *
 *  改函数要用正确的舍入方式计算x/2^k,并且应该遵循位级整数编码规则
 *
 *
 * */
int divide_power2(int x, int k){
    int w = sizeof(int) << 3;
    int bias = (x >> w-1) & ((1 << k) - 1);
    printf("1------::%d\n",(x >> w-1));
    show_int((x >> w-1));
    printf("2------::%d\n",((1 << k)));
    printf("bia"
                   ""
                   ""
                   ""
                   ""
                   "s------::%d\n",bias);
    return (x+bias) >> k;
}
int divide_power2_new(int x, int k){
    int is_neg = x & INT_MIN;
    int bias = 0;
    is_neg && (bias = (1 << k) -1);
    return (x+bias) >> k;

}

int main() {
    int x = 0x80000007;

    int a1 = divide_power2(x, 1);
    printf("a1========::%d\n",a1);
    int a2 = x / 2;
    printf("a2========::%d\n",a2);

    assert(divide_power2(x, 1) == x / 2);
    assert(divide_power2(x, 2) == x / 4);
    assert(divide_power2_new(x, 1) == x / 2);
    assert(divide_power2_new(x, 2) == x / 4);
    divide_power2(x, 5);
    return 0;
    return 0;
}