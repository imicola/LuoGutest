#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int a;
    cin >> a;
    vector<int> arr;
    for (int k = 31; k >= 0;k--)
        arr.push_back((a >> k & 1));
    while(*arr.begin() == 0)
        arr.erase(arr.begin());
    for(auto &&i : arr)
        cout << i;
    return 0;
}