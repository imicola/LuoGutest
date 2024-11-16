//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &&i : a) {
        cin >> i;
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        int temp = 0;
        int k = 0;
        for (int j = n - 1; j > i; j--) {
            if (a[i] > a[j]) temp++;
            k++;
        }
        if (temp == k) ans++;
    }
    cout << ans;
    return 0;
}