#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int getSum(string a)
{
    int sum = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] - '0' >= 0 && a[i] - '0' <= 9)
        {
            sum += a[i] - '0';
        }
    }
    return sum;
}
bool compare(string a, string b)
{
    if (a.length() < b.length())
    {
        return 1;
    }
    else if (a.length() > b.length())
    {
        return 0;
    }
    else
    {
        if (getSum(a) != getSum(b))
        {
            return getSum(a) < getSum(b);
        }
        else
        {
            return a < b;
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string guitar[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> guitar[i];
    }
    sort(guitar, guitar + n, compare);
    for (int i = 0; i < n; i++)
    {
        cout << guitar[i] << "\n";
    }
    return 0;
}
