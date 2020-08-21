/*
1. 분할정복 방식의 정렬
2. 재귀적으로 배열을 분할해준다
3. 각각의 파티션들을 합치며 정렬하는 방식
4. n*log(n)의 시간복잡도
*/
#include <iostream>
using namespace std;

int sorted[8];

void merge(int *a, int n, int middle, int m)
{
    int i = n;
    int j = middle + 1;
    int k = n;
    while (i <= middle && j <= m)
    {
        if (a[i] < a[j])
        {
            sorted[k] = a[i];
            i++;
        }
        else
        {
            sorted[k] = a[j];
            j++;
        }
        k++;
    }
    if (i > middle)
    {
        while (j <= m)
        {
            sorted[k] = a[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= middle)
        {
            sorted[k] = a[i];
            i++;
            k++;
        }
    }
    for (int t = n; t <= m; t++)
    {
        a[t] = sorted[t];
    }
}

void mergeSort(int *a, int n, int m)
{
    if (n < m)
    {
        int middle = (n + m) / 2;
        mergeSort(a, n, middle);
        mergeSort(a, middle + 1, m);
        merge(a, n, middle, m);
    }
}
int main()
{
    int array[8] = {3, 5, 6, 2, 4, 1, 8, 7};
    mergeSort(array, 0, 7);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}