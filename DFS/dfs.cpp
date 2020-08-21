#include <iostream>
#include <vector>

using namespace std;

int number = 7;
int visit[8];
vector<int> a[8];

void dfs(int L)
{
    if (visit[L])
        return;
    visit[L] = true;
    cout << L << ' ';
    for (int i = 0; i < a[L].size(); i++)
    {
        int next = a[L][i];
        dfs(next);
    }
}

int main()
{
    a[1].push_back(2);
    a[2].push_back(1);

    a[1].push_back(3);
    a[3].push_back(1);

    a[2].push_back(3);
    a[3].push_back(2);

    a[2].push_back(4);
    a[4].push_back(2);

    a[2].push_back(5);
    a[5].push_back(2);

    a[3].push_back(6);
    a[6].push_back(3);

    a[3].push_back(7);
    a[7].push_back(3);

    a[4].push_back(5);
    a[5].push_back(4);

    a[6].push_back(7);
    a[7].push_back(6);

    dfs(1);

    return 0;
}