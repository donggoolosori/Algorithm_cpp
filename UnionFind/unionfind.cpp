/*
두 값이 서로 동일한 트리에 연결돼있는지 판별
합집합 찾기, 서로소 찾기
*/
#include <iostream>
using namespace std;

// 부모 노드를 찾는 함수
int getParent(int *parent, int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = getParent(parent, parent[x]);
}
// 두 부모 노드를 합치는 함수
int unionParent(int *parent, int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}
// 같은 부모를 가지는지 확인
int findParent(int *parent, int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b)
        return 1;
    return 0;
}
int main()
{
    int parent[11];
    for (int i = 0; i <= 10; i++)
    {
        parent[i] = i;
    }
    unionParent(parent, 1, 2);
    unionParent(parent, 2, 3);
    unionParent(parent, 3, 4);
    unionParent(parent, 5, 6);
    unionParent(parent, 6, 7);
    unionParent(parent, 7, 8);
    cout << findParent(parent, 1, 5);
}