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


/* Prototype for library function strlen */
size_t strlen(const char *s);

/* Determine whether string s longer than string t */
/* WARNING: This function is buggly */
int strlonger(char *s,char *t)
{
   return strlen(s) - strlen(t) > 0;
}

int main() {
  size_t a = 5;
  size_t b = 6;
  size_t c = a - b;
  printf("c====:: %u\n",c);
  
  unsigned d = 0;
  printf("e ====:: %u\n",d-1);
  return 0;
}
