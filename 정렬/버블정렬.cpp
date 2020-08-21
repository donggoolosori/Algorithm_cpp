// 바로 옆 값과 비교하여 오른쪽으로 큰 값을 보내는 정렬 방식 //
#include <iostream>
using namespace std;

int main()
{
    int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}