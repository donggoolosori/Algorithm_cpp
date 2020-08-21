/*
1~n 인덱스를 순회하며 그 인덱스의 값이 왼쪽의 어느 위치에 들어가야 할지 탐색
왼쪽의 값들은 정렬돼있다는 특징이 있다.
정렬이 대부분 되어있는 경우 높은 속도를 보여줌. 
*/
#include <iostream>
using namespace std;

int main()
{
    int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
    for (int i = 1; i < 10; i++)
    {
        int j = i;
        while (array[j - 1] > array[j])
        {
            int temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
            j--;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d", array[i]);
    }
    return 0;
}