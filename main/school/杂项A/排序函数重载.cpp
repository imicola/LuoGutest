//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<double> b(n);
    for (auto &&i : a) {
        cin >> i;
    }
    for (auto &&i : b) {
        cin >> i;
    }
    sort(all(a));
    sort(all(b));
    for (auto &&i : a) {
        cout << i << " ";
    }
    cout << endl;
    for (auto &&i : b) {
        cout << i << " ";
    }
    return 0;
}