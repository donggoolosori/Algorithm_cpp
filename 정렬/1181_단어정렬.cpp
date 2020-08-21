#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

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
        return a < b; // 사전 순 정렬
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a[20000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, compare);
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << a[i] << "\n";
        else if (a[i] == a[i + 1])
            continue;
        else
        {
            cout << a[i] << "\n";
        }
    }
    return 0;
}