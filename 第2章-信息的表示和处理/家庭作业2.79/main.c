#include <stdio.h>
#include <assert.h>
#include <limits.h>

/*
 * 写出函数mul3div4的代码，对于整数参数x，计算 3*x/4，但是要遵循位级整数编码规则。
 * 你的代码计算3*x也会产生溢出
 *
 * */
int divide_power2(int x, int k){
    int is_neg = x & INT_MIN;
    int bias = 0;
    is_neg && (bias = (1 << k) -1);
    return (x+bias) >> k;

}
int mul3div4(int x){
    int y = (x << 1) + x;
    printf("y--------::%d\n",y);
    return divide_power2(y,2);


}
int mul3div4_new(int x){
    int y = divide_power2(x,2);
    return (y << 1) + y;
}
int main() {
    int x = 0x87654321;
  //  int x = 0xffffffff;
    int y1 = mul3div4(x);
    printf("y1-------::%d\n",y1);
    int y2 = mul3div4_new(x);
    printf("y2-------::%d\n",y2);
    assert(mul3div4(x) == x * 3 / 4);
    assert(mul3div4_new(x) == x * 3 / 4);
    printf("Hello, World!\n");
    return 0;
}