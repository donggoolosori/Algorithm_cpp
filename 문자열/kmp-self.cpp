#include <iostream>
#include <vector>

using namespace std;

vector<int> getPartialMatch(const string &s)
{
    int len = s.length();
    vector<int> pi(len);

    int j = 0;
    for (int i = 1; i < len; i++)
    {
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            pi[i] = ++j;
    }
    return pi;
}

void kmp(const string &parent, const string &pattern)
{
    vector<int> pi = getPartialMatch(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();

    int j = 0;
    for (int i = 0; i < parentSize; i++)
    {
        while (j > 0 && parent[i] != pattern[j])
            j = pi[j - 1];
        if (parent[i] == pattern[j])
        {
            if (j == patternSize - 1)
            {
                cout << i - patternSize + 1 << ' ';
                j = pi[j];
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