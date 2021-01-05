#include <vector>
#include <iostream>

using namespace std;

void quickSort(vector<int> &data, int start, int end)
{
    if (start >= end)
        return;
    int pivot = start; // 기준 값
    int i = start + 1;
    int j = end;

    while (i <= j)
    {
        while (data[i] <= data[pivot])
            i++;
        while (data[j] >= data[pivot] && j > start)
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
    vector<int> data = {38, 27, 43, 9, 3, 82, 10};

    quickSort(data, 0, data.size() - 1);

    for (const auto &n : data)
        cout << n << '\n';

    return 0;
}