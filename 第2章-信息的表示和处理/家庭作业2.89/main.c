#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <stdlib.h>
/*
 * 我们在一个int类型为32补码表示的机器上运行程序。float类型的值使用32位IEEE格式
 * 而double类型的值使用64位IEEE格式。
 *   我们产生随机整数x、y和z，并且把它们转换成double类型的值：
 *
 *   Create some arbitrary values
 *   int x = random();
 *   int y = random();
 *   int z = random();
 *   Convert to double
 *   double dx = (double) x;
 *   double dy = (double) y;
 *   double dz = (double) z;
 *
 *   对于下列的每个C表达式，你要指出表达式是否总为1.如果它总是为1，描述其中的数学
 *   原理。否则，列举出使它为0的参数的例子。请注意，不能使用IA32机器运行GCC来测试你的答案，
 *   因为对于float和double，它使用的都是80位的扩展精度表示。
 *   A. (float) x == (float)dx;
 *   B. dx-dy == (double)(x-y);
 *   C. (dx+dy)+dz == dz+(dy+dz);
 *   D. (dx*dy)*dz==dx*(dy*dz);
 *   E. dx/dx == dz/dz;
 *
 *
 *
 *
 * */
/*
 * most important thing is that all double number come from ints
 */

/* right */
int A(int x, double dx) {
    return (float)x == (float)dx;
}

/* wrong when y is INT_MIN */
int B(int x, double dx, int y, double dy) {
    return dx-dy == (double)(x-y);
}

/* right */
int C(double dx, double dy, double dz) {
    return (dx+dy)+dz == dx+(dy+dz);
}

/*
 * wrong
 *
 * FIXME I don't know what conditions cause false
 */
int D(double dx, double dy, double dz) {
    return (dx*dy)*dz == dx*(dy*dz);
}

/* wrong when dx != 0 and dz == 0 */
int E(double dx, double dz) {
    return dx/dx == dz/dz;
}

int main(int argc, char* argv[]) {

    int x = random();
    int y = random();
    int z = random



            ();
    double dx = (double)x;
    double dy = (double)y;
    double dz = (double)z;

    printf("%x %x %x\n", x, y, z);

    assert(A(x, dx));
    assert(!B(0, (double)(int)0, INT_MIN, (double)(int)INT_MIN));
    assert(C(dx, dy, dz));
    /* magic number, brute force attack */
    assert(!D((double)(int)0x64e73387, (double)(int)0xd31cb264, (double)(int)0xd22f1fcd));
    assert(!E(dx, (double)(int)0));
    return 0;
}