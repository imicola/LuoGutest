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
    sort(a.begin(), a.end());
    for (auto&& i : a) {
        cout << i << " ";
    }

    return 0;
}