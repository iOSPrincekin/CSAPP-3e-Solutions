#include <stdio.h>

void inplace_swap(int *x, int *y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverse_array(int a[], int cnt)
{
    int first, last;
    for (first = 0, last = cnt - 1;first < last; first++,last--)
        inplace_swap(&a[first],&a[last]);
}
void check_array(int a[], int cnt)
{
    for (int i = 0; i < cnt; ++i)
      printf("%d\n",a[i]);
}
int main() {
    const int num = 5;
    int arr[num] = {1,2,3,4,5};
    reverse_array(arr,num);
    check_array(arr,num);
    return 0;
}