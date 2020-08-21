/*
1. n*log(n) 의 시간복잡도
2. 힙구조(큰 수 부터 트리 최상단에 배치한 구조)로 변환
3. 최상단의 노드(최대값)와 최하단 노드를 바꿔줌
4. 배치 된 최대값을 제외하고 2,3 반복
*/
#include <iostream>
using namespace std;

int number = 9;
int heap[9] = {7, 6, 5, 8, 3, 5, 9, 1, 6};

int main()
{
    // 먼저 전체 트리 구조를 힙 구조로 바꾼다.
    for (int i = 1; i < number; i++)
    { // 아래에서 위로 올라가는 형식
        int c = i;
        do
        {
            int root = (c - 1) / 2;
            if (heap[root] < heap[c])
            {
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
    // 크기를 줄여가며 반복적으로 힙을 구성
    for (int i = number - 1; i >= 0; i--)
    {
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        int root = 0;
        int c = 1;
        do
        {
            c = 2 * root + 1;
            // 자식 중에 더 큰 값을 찾기
            if (heap[c] < heap[c + 1] && c < i - 1)
            {
                c++;
            }
            // 루트보다 자식이 더 크다면 교환
            if (heap[root] < heap[c] && c < i)
            {
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while (c < i);
    }
    for (int i = 0; i < number; i++)
    {
        cout << heap[i] << " ";
    }
    return 0;
}