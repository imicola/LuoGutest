#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (size_t i = 0 ; i < n; i++)
    {
        cin >> arr[i];
    }
    int z;
    cin >> z;
    while (z--)
    {
        int a,b,ans = 0;
        cin >> a >> b;
        auto ita = arr.begin() + a;
        auto itb = arr.begin() + b;
        for(;ita != itb + 1; ita++) ans += *ita;
        cout << ans << endl;
    }
    
    return 0;
}