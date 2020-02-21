#include <stdio.h>
#include <assert.h>
/*
 Return 1 when any odd bit of x equals 1; 0 otherwise
 Assume w=32
 int any_odd_one(unsigned x);
 函数应该遵循位级整数编码规则，不过你可以假设数据类型int 有 w=32位
 * */
/** 解题： 这题的意思应该是二进制中，任意一个奇数位为1，则返回1，如果奇数位全部为1，则返回0
 *
 *
 * */
int any_odd_one0(unsigned x){
    return !!(x & 0xAAAAAAAA);
}
int any_odd_one(unsigned x) {
    return !!(0xAAAAAAAA & x);
}

int main(int argc, char* argv[]) {
    assert(any_odd_one(0x2));
    assert(!any_odd_one(0x4));
    int x = any_odd_one(0x2);
    printf("x-----::%d\n",x);
    int y = any_odd_one(0x4);
    printf("y-----::%d\n",y);
    int z = any_odd_one(0x88888888);
    printf("z-----::%d\n",z);

    int d = 0x2;
    printf("d-----::%d\n",d);
    d >> 1;
    printf("d-----::%d\n",d);
    x = 2;
    int e = x^(x>>1);
    printf("e-----::%d\n",e);
    return 0;
}