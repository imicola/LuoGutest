#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> p;
    for (size_t i = 1; i <= n; i++) {
        p.push_back(i);
    }
    for (size_t i = 0; i < k; i++) {
        vector<int> out(p);
        cout << i + 1 << ": ";
        for (size_t j = 0; j < n; j++) {
            cout << out[j] << " ";
        }
        int temp = *p.begin();
        p.erase(p.begin());
        p.push_back(temp);
        cout << endl;
    }

    return 0;
}