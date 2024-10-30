#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    int a = 0;
    vector<int> arr(5);
    while (1) {
        cin >> a;
        if (a == -1) break;
        arr[a]++;
    }
    int k = 0;
    for (auto&& i : arr) {
        cout << k++ << "-" << i << endl;
    }
    return 0;
}