#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    vector<string> arr(11);
    int t = 10;
    while (t--)
    {
        cin >> arr[t];
    }
    for (auto &&i : arr)
    {
        cout << i << " ";
    }
    return 0;
}