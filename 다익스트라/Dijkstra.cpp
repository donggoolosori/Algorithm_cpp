#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 1000000000;
// 간선 정보
vector<pair<int, int>> edge[7];
//최소비용
int d[7];

void dijkstra(int start)
{
    d[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(start, 0));
    // 가까운 순서대로 처리하므로 큐를사용
    while (!pq.empty())
    {
        int cur = pq.top().first;
        // 짧은 것이 먼저 오도록 음수화
        int distance = -pq.top().second;
        pq.pop();
        // 최단 거리가 아닌 경우 스킵
        if (d[cur] < distance)
            continue;
        for (int i = 0; i < edge[cur].size(); i++)
        {
            // 선택 된 노드의 인접 노드
            int next = edge[cur][i].first;
            // 선택 된 노드 거쳐서 인접 노드로 가는 비용
            int nextDistance = distance + edge[cur][i].second;
            // 기존의 최소 비용보다 저렴하다면 교체
            if (nextDistance < d[next])
            {
                d[next] = nextDistance;
                pq.push(make_pair(next, -nextDistance));
            }
        }
    }
}
int main()
{
    for (int i = 1; i <= number; i++)
    {
        d[i] = INF;
    }
    edge[1].push_back(make_pair(2, 2));
    edge[1].push_back(make_pair(3, 5));
    edge[1].push_back(make_pair(4, 1));

    edge[2].push_back(make_pair(1, 2));
    edge[2].push_back(make_pair(3, 3));
    edge[2].push_back(make_pair(4, 2));

    edge[3].push_back(make_pair(1, 5));
    edge[3].push_back(make_pair(2, 3));
    edge[3].push_back(make_pair(4, 3));
    edge[3].push_back(make_pair(5, 1));
    edge[3].push_back(make_pair(6, 5));

    edge[4].push_back(make_pair(1, 1));
    edge[4].push_back(make_pair(2, 2));
    edge[4].push_back(make_pair(3, 3));
    edge[4].push_back(make_pair(5, 1));

    edge[5].push_back(make_pair(3, 1));
    edge[5].push_back(make_pair(4, 1));
    edge[5].push_back(make_pair(6, 2));

    edge[6].push_back(make_pair(3, 5));
    edge[6].push_back(make_pair(5, 2));

    dijkstra(1);

    for (int i = 1; i <= number; i++)
    {
        printf("%d ", d[i]);
    }
}