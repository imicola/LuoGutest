#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int k;
    cin >> k;
    int arr[k];
    int ans = 0;
    for (size_t i = 0; i < k; i++) cin >> arr[i];
    for (auto &&i : arr) ans += i;
    cout << ans;
    return 0;
}