#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a1(n),a2(m),a3(m+n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a1[i];
    }
    for (size_t i = 0; i < m; i++)
    {
        cin >> a2[i];
    }    
    merge(a1.begin(),a1.end(),a2.begin(),a2.end(),a3.begin());
    sort(a3.begin(),a3.end());
    for (auto &&i : a3)
    {
        cout << i <<" ";
    }
    
    return 0;
}