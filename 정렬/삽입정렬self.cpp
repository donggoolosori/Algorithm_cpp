#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> array = {3, 7, 6, 4, 2, 1};
    int N = array.size();

    for (int i = 1; i < N; i++)
    {
        int j = i;
        while (j > 0 && array[j - 1] > array[j])
        {
            int temp = array[j - 1];
            array[j - 1] = array[j];
            array[j] = temp;
            j--;
        }
    }

    for (auto n : array)
        cout << n << ' ';

    return 0;
}