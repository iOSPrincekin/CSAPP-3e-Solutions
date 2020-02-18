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
        printf(" \n");
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
int main() {
 //   int val = 0x87654321;
    int val = 0x5;
 //   int val = 260;
    show_int(val);
    print_2(val);
    byte_pointer valp = (byte_pointer) &val;
    show_bytes(valp,1);
    show_bytes(valp,2);
    show_bytes(valp,3);


//    const char *s = "abcdef";
    const char *s = "1234567";
    show_bytes((byte_pointer) s,strlen(s));
  
  
  
  
  
  short x = 12345;
  short mx = -x;
  
  show_bytes((byte_pointer) &x,sizeof(short));
  show_bytes((byte_pointer) &mx,sizeof(short));
  
  printf("=================================\n");
  short int v = -12345;
  unsigned short uv = (unsigned short) v;
  printf("v = %d, uv = %lu\n",v,uv);
  
  printf("=================================\n");
  unsigned u = 4294967295u;    /* UMax */
  int tu = (int) u;
  printf("u = %u, tu = %d\n",u,tu);


    return 0;
}
