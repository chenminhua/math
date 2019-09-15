#include <stdio.h>
int add(int n1, int n2)
{
    if (n2 == 0)
        return n1;
    int t = n1 ^ n2;
    int ca = (n1 & n2) << 1;
    return add(t, ca);
}

int main()
{
    printf("%d + %d = %d\n", 15, 28, add(15, 28));
}