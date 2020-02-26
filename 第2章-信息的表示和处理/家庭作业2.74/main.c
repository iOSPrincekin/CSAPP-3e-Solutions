#include <stdio.h>
#include <assert.h>
#include <limits.h>

/*
 * 写出具有如下原型的函数的代码
 *
 * Determine whether arguments can be subtracted without overflow
 * int tsub_ok(int x,int y);
 *
 * 如果计算x-y 不溢出，这个函数就返回1
 *
 *
 * */
int tsub_ok(int x,int y){
    int sub = x - y;
    int w = sizeof(x) << 3;
    int x_first = (unsigned)x >> w-1;
    int sub_first = (unsigned)sub >> w-1;
    return !(x_first ^ sub_first);
}
int main() {
    printf("Hello, World!\n");
    assert(!tsub_ok(0x0, INT_MIN));
    assert(tsub_ok(0x00, 0x00));
    assert(!tsub_ok(INT_MAX, INT_MIN));
    return 0;
}
