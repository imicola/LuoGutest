//#pragma GCC optimize(2)
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
    for (size_t i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp - arr[i] < 0)
            cout << 0 << " ";
        else
            cout << temp - arr[i] <<" ";
    }

    return 0;
}