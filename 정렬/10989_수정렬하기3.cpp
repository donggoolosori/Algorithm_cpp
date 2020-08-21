#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[10001];
    int MAX = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num > MAX)
            MAX = num;
        arr[num]++;
    }
    for (int i = 0; i <= MAX; i++)
    {
        if (arr[i] != 0)
        {
            for (int j = 0; j < arr[i]; j++)
            {
                cout << i << "\n";
            }
        }
    }
    return 0;
}