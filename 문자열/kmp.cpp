#include <iostream>
#include <vector>

using namespace std;

vector<int> getpartialmatch(const string &pattern)
{
    int size = pattern.size();
    vector<int> table(size);

    int j = 0;
    for (int i = 1; i < size; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
            j = table[j - 1];
        if (pattern[i] == pattern[j])
            table[i] = ++j;
    }
    return table;
}

void kmp(const string &parent, const string &pattern)
{
    vector<int> table = getpartialmatch(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();

    int j = 0;
    for (int i = 0; i < parentSize; i++)
    {
        while (j > 0 && parent[i] != pattern[j])
            j = table[j - 1];
        if (parent[i] == pattern[j])
        {
            if (j == patternSize - 1)
            {
                cout << i - patternSize + 1 << ' ';
                j = table[j];
            }
            else
                j++;
        }
    }
}

int main()
{
    string parent = "ababacabacaabacaaba";
    string pattern = "abacaaba";
    kmp(parent, pattern);
    return 0;
}