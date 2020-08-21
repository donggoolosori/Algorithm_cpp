#include <iostream>
using namespace std;

int d[1001];

int dp(int x)
{
    if (x == 0)
        return 1;
    if (x == 1)
        return 0;
    if (x == 2)
        return 3;
    int res = 3 * dp(x - 2);
    for (int i = 3; i <= x; i++)
    {
        if (i % 2 == 0)
        {
            res += 2 * dp(x - i);
        }
    }
    return d[x] = res;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", dp(n));
    return 0;
}