#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
/*
 *  库函数有如下声明
 *  void *calloc(size_t nmemb,size_t size);
 *  根据库文档："函数calloc为一个数组分配内存，该数组有nmemb个元素，每个元素为size字节。
 *  内存设置为0.如果nmemb或size为0，则calloc返回NULL。"
 *
 *  编写calloc的实现，通过调用mallod执行分配，调用memset将内存设置为0。你的代码应
 *  该没有任何由算术溢出引起的漏洞，且无论数据类型size_t 用多少位表示，代码都应该正常
 *  工作。
 *  作为参考，函数malloc 和 memset声明如下：
 *
 *
 *
 *
 *  void *malloc(size_t size);
 *  void *memset(void *s,int c,size_t n);
 *
 * */

/* rename to avoid conflict */





void *another_calloc(size_t nmemb,size_t size){
    if (nmemb == 0 || size == 0)
        return NULL;
    size_t  total_size = nmemb * size;
    /* a good way to check overflow or not */
    if (nmemb == total_size / size)
    {
        void * ptr = malloc(total_size);
        if (ptr) {
            memset(ptr, 0, total_size);
            return ptr;
        }

    }
    return NULL;
}
int main() {
    void* p;
    p = another_calloc(0x1234, 1);
    assert(p != NULL);
    free(p);

    p = another_calloc(SIZE_MAX, 2);
    assert(p == NULL);
    free(p);
    return 0;
    return 0;
}