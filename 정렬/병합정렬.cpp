/*
1. 분할정복 방식의 정렬
2. 재귀적으로 배열을 분할해준다
3. 각각의 파티션들을 합치며 정렬하는 방식
4. n*log(n)의 시간복잡도
*/
#include <iostream>
#include <vector>
using namespace std;

int sorted[7];
vector<int> arr = {38, 27, 43, 9, 3, 82, 10};

void merge(int left, int right)
{
    int mid = (left + right) / 2;

    int i = left;
    int j = mid + 1;
    int k = left;

    // 두 부분 수열을 오름차순으로 합치는 과정
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            sorted[k++] = arr[i++];
        else
            sorted[k++] = arr[j++];
    }
    // 남은 요소들을 합치는 과정
    int temp = i > mid ? j : i;
    while (k <= right)
        sorted[k++] = arr[temp++];

    for (int i = left; i <= right; i++)
        arr[i] = sorted[i];
}

void mergeSort(int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, right);
    }
}
int main()
{
    mergeSort(0, 6);
    for (int i = 0; i < 7; i++)
        printf("%d ", arr[i]);

    return 0;
}