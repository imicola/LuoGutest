//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    priority_queue<int, vector<int>, greater<int>> arr;
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push(temp);
    }
    int k;
    cin >> k;
    arr.push(k);
    while (!empty(arr)) {
        int temp = arr.top();
        cout << temp << " ";
        arr.pop();
    }

    return 0;
}