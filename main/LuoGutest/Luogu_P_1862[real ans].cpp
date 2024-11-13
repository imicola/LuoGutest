//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<LL> loc(n);
    LL maxy_index = -1e8, miny_index = 1e8;
    for (auto &&i : loc) {
        int x;
        cin >> x >> i;
        if (i > maxy_index) maxy_index = i;
        if (i < miny_index) miny_index = i;
    }
    sort(loc.begin(), loc.end());
    LL minans = 1e8;
    for (LL i = miny_index; i <= maxy_index; i++) {
        LL tempans = 0;
        for (LL j = 0; j < loc.size(); j++) {
            tempans += abs(i - loc[j]);
        }
        if (tempans < minans) minans = tempans;
    }
    cout << minans;
    return 0;
}