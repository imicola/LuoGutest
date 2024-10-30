#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return a.second > b.second;
}

int main()
{
    int a = 0;
    cin >> a;
    map<int, int> arr;
    while (a--) {
        int temp;
        cin >> temp;
        arr[temp]++;
    }
    int k = 0;
    vector<pair<int, int>> temp(arr.begin(), arr.end());
    sort(temp.begin(), temp.end(), cmp);
    cout << temp[0].first << " " << temp[0].second;
    return 0;
}