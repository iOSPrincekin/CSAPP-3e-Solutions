#include <stdio.h>
#include <limits.h>
#include <assert.h>

/*
 *  写出具有如下原型的函数的代码：
 *   Addition that saturates to TMin or TMax
 *   int saturating_add(int x,int y);
 *
 *   同正常的补码加法溢出的方式不同，当正溢出时，饱和加法返回TMax，负溢出时，
 *   返回Tmin。饱和运算常常用在执行数字信号处理的程序中。
 *   你的函数应该遵循位级整数编码规则
 *
 * */
int saturating_add(int x,int y){
    int sum = x + y;
    int sig_mask = INT_MIN;

    /*
     * if x > 0, y > 0 but sum < 0, it's a positive overflow
     *
     * if x < 0, y < 0 but sum >= 0, it's a negetive overflow
     * */

    int w = sizeof(int)  << 3;
    // 正溢出，x,y 最高位都应该为0，溢出后，最高为1
    int pos_over = !((unsigned)x >> (w-1)) && !((unsigned)y >> (w-1)) && ((unsigned)sum >> (w-1));
    // 负溢出，x,y 最高位都应该为1，溢出后，最高为0


    int neg_over = ((unsigned)x >> (w-1)) && ((unsigned)y >> (w-1)) && !((unsigned)sum >> (w-1));

    (pos_over && (sum = INT_MAX)) || (neg_over && (sum = INT_MIN));

    return sum;
}
int main() {
    printf("Hello, World!\n");
    assert(INT_MAX == saturating_add(INT_MAX, 0x1234));
    assert(INT_MIN == saturating_add(INT_MIN, -0x1234));
    assert(0x11 + 0x22 == saturating_add(0x11, 0x22));
    return 0;
}