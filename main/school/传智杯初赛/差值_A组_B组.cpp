#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &&i : arr) {
        cin >> i;
    }
    int omin = 100000;
    sort(arr.begin(), arr.end());
    for (size_t i = 0; i < n - 1; i++) {
        if (omin > arr[i + 1] - arr[i]) {
            omin = arr[i + 1] - arr[i];
        }
    }
    cout << omin;
    return 0;
}