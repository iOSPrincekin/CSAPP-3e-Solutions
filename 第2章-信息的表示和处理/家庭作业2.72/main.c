#include <stdio.h>
#include <string.h>

/* 给你一个任务，写一个函数，将整数val复制到缓冲区buf中，但是只有当缓冲区中有足够可用
 * 的空间时，才执行复制
 *
 * 你写的代码如下
 *
 * */
/* Copy integer into buffer if space is available */
/* WARNING: The following code is buggy*/
void copy_in(int val,void *buf,int maxbytes)
{
    if (maxbytes- sizeof(val) >= 0) {
        printf("条件成立-----1\n");
        memcpy(buf, (void *) &val, sizeof(val));
    }
}
void copy_in_ok(int val,void *buf,int maxbytes)
{
    if (maxbytes >= sizeof(val)) {
        printf("条件成立-----2\n");
        memcpy(buf, (void *) &val, sizeof(val));
    }
}
/* 这段代码使用了库函数memcpy。虽然在这里使用这个函数有点刻意，因为我们只是想复制一个
 * int，但是它说明了一种复制较大数据结构的常见方法
 *  你仔细地测试了这段代码后发现，哪怕maxbytes很小的时候，它也能把值复制到缓冲区中。
 *  A.解释为什么代码中的条件测试总是成功。提示：sizeof运算符返回类型为size_t的值。::因为当 maxbytes < sizeof(val) 时，maxbytes- sizeof(val)为负的无符号数，是 > 0 的
 *  B.你该如何重写这个条件测试，使之工作正确。
 * */
int main() {
    printf("Hello, World!\n");

    void *p = 0;
    copy_in(5,p,1);

    return 0;
}