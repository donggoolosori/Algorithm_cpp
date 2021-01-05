#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> array = {3, 7, 6, 4, 2, 1};
    int N = array.size();

    for (int i = 0; i < N - 1; i++)
    {
        // 옆에 있는 수를 비교하여 큰 수를 뒤로보내기
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    // 출력 : 1 2 3 4 6 7
    for (auto n : array)
        cout << n << ' ';
    return 0;
}