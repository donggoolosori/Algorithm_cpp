#include <iostream>
#include <cmath>
using namespace std;

int number = 120;
int a[121];

void primeNumberSieve()
{
    for (int i = 2; i <= number; i++)
    {
        a[i] = i;
    }
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (a[i] == 0)
            continue;
        for (int j = i * i; j <= number; j += i)
            a[j] = 0;
    }
    for (int i = 2; i <= number; i++)
    {
        if (a[i] != 0)
            printf("%d\n", a[i]);
    }
}
int main()
{
    primeNumberSieve();
}