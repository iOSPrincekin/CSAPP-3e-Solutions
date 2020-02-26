#include <stdio.h>
#include <assert.h>

/*
 * 编写C表达式产生如下位模式，其中a^k表示符号a重复k次。假设一个w位的数据类型。代码可以
 * 包含对参数j和k的引用，它们分别表示j和k的值，但是不能使用表示w的参数
 *
 *  A. 1^(w-k)0^k
 *
 *  B. 0^(w-k-j)1^k0^j
 * */
int A(int k,int j)
{
    return -1 << k;
}
int B(int k,int j)
{
    return (-1 << j) ^ (-1 << k+j);
}
int main() {

    assert(A(8,0) == 0xFFFFFF00);
    assert(B(16, 8) == 0x00FFFF00);
    return 0;
}