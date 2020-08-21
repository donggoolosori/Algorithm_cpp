#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int number = 7;
int visit[8];
vector<int> a[8];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visit[start] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (int i = 0; i < a[cur].size(); i++)
        {
            int next = a[cur][i];
            if (!visit[next])
            {
                q.push(next);
                visit[next] = true;
            }
        }
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

    bfs(1);

    return 0;
}