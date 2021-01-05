#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> numbers = {3, 7, 6, 4, 2, 1};
    int len = numbers.size();
    int index = 0;
    for (int i = 0; i < len; i++)
    {
        int minval = 1000; // 최소값 갱신을 위해 큰 수로 초기화
        // 최소값의 인덱스 찾기
        for (int j = i; j < len; j++)
        {
            if (numbers[j] < minval)
            {
                minval = numbers[j];
                index = j;
            }
        }
        // 최소값이 자신이라면 continue
        if (i == index)
            continue;
        // 값 바꿔주기
        int temp = numbers[i];
        numbers[i] = numbers[index];
        numbers[index] = temp;
    }
    // 출력
    for (auto n : numbers)
        cout << n << ' ';

    return 0;
}