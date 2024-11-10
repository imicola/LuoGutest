//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<pair<string, pair<int, int>>> arr(n);
    for (auto &&i : arr) {
        cin >> i.first >> i.second.first >> i.second.second;
    }
    sort(arr.begin(), arr.end(), [](pair<string, pair<int, int>> a, pair<string, pair<int, int>> b) {
        if (a.second.first == b.second.first && a.second.second == b.second.second) return a.first <= b.first;
        if (a.second.first == b.second.first) return a.second.second > b.second.second;
        return a.second.first > b.second.first;
    });
    for (auto &&i : arr) {
        cout << i.first<<" "<< i.second.first <<" "<< i.second.second << endl;
    }
    return 0;
}