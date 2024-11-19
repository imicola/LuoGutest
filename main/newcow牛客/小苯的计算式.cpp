//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    string c;
    cin >> n >> c;
    int len = n - c.size() - 2;
    int ans = 0;
    int c1 = stoi(c);
    for (int i = stoi(c); i >= 0; i--) {
        int temp = stoi(c) - i;
        if (to_string(temp).size() + to_string(i).size() == len) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}

// 5 7 --> 8
// 0+7 1+6 2+5 3+4

// 7 10 --> 2
// 6 100

// len -->  len/2 len/2  \\  len/2 + 1 len/2
//               1
// 10 200
// 98+102=200 99+101=200 ... 10+190 --> 89
//
