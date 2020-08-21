/*
왼쪽과 오른쪽 부터 각각 탐색하여 왼쪽은 pivot(key) 값보다 큰 값 탐색,
오른쪽은 작은 값 탐색하여 두 인덱스가 엇갈리지 않으면 두 인덱스의 값을 교환
엇갈린다면 두 인덱스 중 작은 인덱스 값이 pivot 값이 들어갈 위치이므로 pivot 값과 교체해준다
*/
#include <iostream>
using namespace std;

void quickSort(int *data, int start, int end)
{
    if (start >= end)
    { // 원소가 1개인 경우
        return;
    }
    int key = start;
    int i = start + 1;
    int j = end;
    int temp;
    // 엇갈릴 때까지 반복
    while (i <= j)
    {
        while (data[i] <= data[key]) //키 값보다 큰 값 만날때까지 오른쪽으로 이동
        {
            i++;
        }
        while (data[j] >= data[key] && j > start) // 키 값보다 작은 값 만날때까지 왼쪽으로
        {
            j--;
        }
        if (i > j) //현재 엇갈린 상태면 키 값 교체
        {
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        }
        else
        {
            temp = data[j];
            data[j] = data[i];
            data[i] = temp;
        }
        quickSort(data, start, j - 1);
        quickSort(data, j + 1, end);
    }
}
int main()
{
    int data[10] = {3, 7, 8, 1, 5, 9, 6, 10, 2, 4};
    int number = 10;
    quickSort(data, 0, number - 1);
    for (int i = 0; i < number; i++)
    {
        printf("%d", data[i]);
    }
    return 0;
}