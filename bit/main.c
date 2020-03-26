#include <stdio.h>
int add(int n1, int n2)
{
    if (n2 == 0)
        return n1;
    // 异或位的直接都算上，都为1的位都要算两倍。
    int t = n1 ^ n2;
    int ca = (n1 & n2) << 1;
    return add(t, ca);
}

int findOnlyOnce(int *arr, int n)
{
    // 找出数组中只出现过一次的数，其他数都出现过两次
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res ^= arr[i];
    }
    return res;
}

int main()
{
    printf("%d + %d = %d\n", 15, 28, add(15, 28));
    int arr[9] = {1, 1, 255, 432, 65, 12, 12, 432, 255};
    printf("[1,1,255,432,65,12,12,432,255] only once number %d\n", findOnlyOnce(arr, 9));
}