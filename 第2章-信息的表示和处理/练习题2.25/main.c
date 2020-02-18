#include <stdio.h>
#include <string.h>
typedef unsigned char *byte_pointer;
void print_2(int val2)
{
    unsigned char *p = (unsigned char*)&val2 + 3; //从低位到高位,低端字节计算机
    for(int k = 0; k <= 3; k++)
    {
        int val2 = *(p-k);
        for (int i = 7; i >= 0; i--)
        {
            if(val2 & (1 << i))
                printf("1");
            else
                printf("0");
        }
        printf(" ");
    }
}
void show_bytes(byte_pointer start,size_t len)
{
    size_t i;
    for (i = 0; i < len; i++) {
        printf(" %.2x",start[i]);
    }

    printf("\n");
}

void show_int(int x)
{
    int *y = &x;
    byte_pointer z = y;
    show_bytes(z, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer) &x, sizeof(void *));
}
void test_show_bytes(int val)
{
    int ival = val;
    printf("1-------%p\n",&val);
    printf("----------\n");
    printf("2-------%p\n",&ival);
    float fval = (float)ival;
    int *pval = &ival;
    show_int(ival);
 //   show_float(fval);
 //   show_pointer(pval);

}
int fun1(unsigned word)
{
  return (int) ((word << 24) >> 24);
}
int fun2(unsigned word)
{
   return ((int) (word << 24)) >> 24;
}
/* WARNING: This is buggy code */
float sum_elements(float a[],unsigned length)
{
   int i;
   float result = 0;
   printf("length -1 ::---------:%u\n",length - i);
   for (i = 0; i < length - 1; i++){
    result += a[i];
    printf("i---------:%d\n",i);
    }
    return result;
}
int main() {
  const unsigned num = 0;
  float a[num] = {1,2};
  float total_sum = sum_elements(a,num);
  printf("total_sum==:%f",total_sum);
  
  return 0;
}
