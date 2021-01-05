#include <vector>
#include <iostream>

using namespace std;

void quickSort(int *data, int start, int end)
{
    if (start >= end)
        return;
    int pivot = start; // 기준 값
    int i = start + 1;
    int j = end;

    while (i <= j)
    {
        while (data[i] <= data[pivot]) // 키 값보다 큰 값 만날때까지 오른쪽으로 이동
            i++;
        while (data[j] >= data[pivot] && j > start) // 키 값보다 작은 값 만날 때까지 왼쪽으로 이동
            j--;
        if (i > j) //현재 엇갈린 상태면 pivot 값 교체
        {
            int temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        }
        else
        {
            int temp = data[j];
            data[j] = data[i];
            data[i] = temp;
        }
        // 재귀 호출
        quickSort(data, start, j - 1);
        quickSort(data, j + 1, end);
    }
}

int main()
{
    int data[7] = {38, 27, 43, 9, 3, 82, 10};
    int len = 7;
    quickSort(data, 0, len - 1);

    for (int i = 0; i < len; i++)
        cout << data[i] << ' ';

    return 0;
}