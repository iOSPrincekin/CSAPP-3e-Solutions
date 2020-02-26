#include <stdio.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>
/*
 *  我们在一个int类型值为32位的机器上运行程序。这些值以补码形式表示，而且它们都是算术右移的。
 *  unsigned类型的值也是32位的
 *
 *  我们产生随机数x和y，并且把它们转换成无符号数，显示如下：
 *
 *  Create some arbitrary values
 *  int x = random();
 *  int y = random();
 *  Convert to unsigned
 *  unsigned ux = (unsigned)x;
 *  unsigned uy = (unsigned)y;
 *
 *  对于下列每个C表达式，你要指出表达式是否总是为1.如果它总是为1，那么请描述其中的
 *  数学原理。否则，列举出一个使它为0的参数示例
 *
 *  A. (x<y) == (-x>-y);    wrong,when x is INT_MIN
 *  B. ((x+y)<<4)+y-x==17*y+15*x;  right
 *  C. ~x+~y+1 == ~(x+y);        right
 *  D. (ux-uy) == -(unsigned)(y-x);   right
 *  E. ((x>>2)<<2) <= x;       right
 *
 * */

/* broken when x is INT_MIN */
int A(int x, int y) {
    return (x < y) == (-x > -y);
}

/*
 *  right
 *
 *  ((x+y) << 4) + y - x
 *  =>
 *  x<<4 - x +y << 4 + y
 *  => x *16 -x +y *16 + y
 *   whether overflow or not, =>
 *   x * 15 + y *17
 *
 * */
int B(int x, int y) {
    return ((x + y) << 4) + y - x == 17 * y + 15 * x;
}
/*
 * right
 *
 * ~x + ~y + 1   =>
 * -x - 1 -y - 1 + 1   =>
 * -(x+y)-1            =>
 * ~(x+y)
 *
 *
 * */
int C(int x, int y) {
    return ~x + ~y + 1 == ~(x + y);
}

/*
 *  right
 *
 *  (ux-uy) == -(unsigned)(y-x)
 *  =>
 *  -(ux-uy) == (unsigned)(y-x)
 *  =>
 *  (ux-uy) == (unsigned)(x-y)
 *
 * */

int D(int x, int y) {
    unsigned ux = (unsigned) x;
    unsigned uy = (unsigned) y;

    return (ux - uy) == -(unsigned) (y - x);
}

/*
 * right
 *
 * x >> 2 << 2
 *   =>
 * x & ~0x3
 *   =>
 * x - num(00/01/10/11)
 *   =>
 * ((x >> 2) << 2) <= x
 */
int E(int x, int y) {
    return ((x >> 2) << 2) <= x;
}



int main() {
    printf("Hello, World!\n");
    assert(D(3, 2));
    return 0;
}

