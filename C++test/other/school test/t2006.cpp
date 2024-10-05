#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    cin >> a;
    vector<pair<int,int>> a1;
    pair<int,int> t;
    for (size_t i = 0; i < a; i++)
    {
        int b;
        cin >> b;
        t.first = b;
        t.second = b*2;
        a1.push_back(t);
    }
    for (size_t i = 0; i < a; i++)
    {
        cout << a1[i].first << " " << a1[i].second <<endl;
    }
    return 0;
}