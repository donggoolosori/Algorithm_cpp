#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int, string>> v;
    v.push_back(pair<int, string>(90, "ab"));
    v.push_back(pair<int, string>(85, "bc"));
    v.push_back(pair<int, string>(82, "ce"));
    v.push_back(pair<int, string>(98, "dqd"));
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].second << " ";
    }
    return 0;
}