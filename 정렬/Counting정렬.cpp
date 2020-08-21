/*
1. 탐색해야할 수의 범위가 존재할 때 매우 효율적인 알고리즘 O(n)
2. 카운팅 배열에 정렬할 배열에서 카운팅 한 수들을 저장
*/
#include <iostream>
using namespace std;

int main()
{
    int cnt[5] = {0};
    int array[] = {1, 3, 2, 4, 3, 5, 4, 3, 2, 3, 4, 4, 3, 3, 3, 4, 3, 2, 3, 2, 1, 3, 2, 3, 3, 4, 5, 5, 3, 4, 5, 1, 5, 3};

    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        int val = array[i];
        cnt[val - 1]++;
    }
    for (int i = 0; i < 5; i++)
    {
        if (cnt[i] != 0)
        {
            for (int j = 0; j < cnt[i]; j++)
            {
                printf("%d ", i + 1);
            }
        }
    }
    return 0;
}