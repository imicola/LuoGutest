#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& i : a) {
        cin >> i;
    }
    for (size_t i = 1; i < n; i++)
    {
        if (i == n - 1){
            cout << a[n - 1] << " ";
            cout << a[0];
            break;
        }
        cout << a[i] <<" ";
    }
    
    return 0;
}