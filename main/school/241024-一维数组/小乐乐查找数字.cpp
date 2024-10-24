#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int p,ans = 0;
    cin >> p;
    for(auto &&i:a) if(p == i) ans++;
    cout << ans;
    return 0;
}