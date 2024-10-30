#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    for (int i = 1; i <= d; i++) {
        int temp;
        cin >> temp;
        arr[temp] += i;
    }
    for (auto&& i : arr) {
        cout << i << " ";
    }

    return 0;
}