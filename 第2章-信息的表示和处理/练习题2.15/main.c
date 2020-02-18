#include <stdio.h>
#include <MacTypes.h>

bool compare(int x, int y){
    return !(x ^ y);
}
int main() {
    printf("Hello, World!\n");
    if (compare(0,5)) printf("相等");
    else printf("不相等");
    return 0;
}