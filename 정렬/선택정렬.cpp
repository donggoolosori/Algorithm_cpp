// 이중 for문을 통해 최소값을 탐색 후 채워나가는 정렬 방식
#include <iostream>
using namespace std;

int main()
{
    int min, idx, tmp;
    int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
    for (int i = 0; i < 10; i++)
    {
        min = 9999;
        for (int j = i; j < 10; j++)
        {
            if (array[j] < min)
            {
                min = array[j];
                idx = j;
            }
        }
        if (idx == i)
            continue;
        tmp = array[i];
        array[i] = array[idx];
        array[idx] = tmp;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}