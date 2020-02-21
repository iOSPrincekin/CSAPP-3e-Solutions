#include <stdio.h>

/*
 将下面的C函数代码补充完整。函数srl用算术右移(由值xsra给出)来完成逻辑右移，后面的其
 他操作不包含右移或者除法。函数sra用逻辑右移(由值xsrl给出)来完成算术右移，后面的其他
 操作不包含右移或者除法。可以通过计算8*sizeof(int)来确定数据类型int中的位数w。位移
 量k的取值范围为0~w-1。
 */
unsigned srl(unsigned x,int k)
{
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;
    int w = sizeof(int) << 3;
    int y = -1 << (w-k);
    return xsra & (~y);
}
int sra(int x,int k)
{

    /* Preform shift logically */
    int w = sizeof(int) << 3;
    int xsrl = (unsigned)x >> k;
    int mask = x << (w - k);
    mask &= !(x >> (w-1)) - 1;
    return xsrl | mask;
}
int main() {
    printf("Hello, World!\n");
    return 0;
}