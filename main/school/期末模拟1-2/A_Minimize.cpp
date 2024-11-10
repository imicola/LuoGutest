//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int min_c = 1e5;
        for (int c = a; c <= b; c++) {
            if ((c - a) + (b - c) < min_c) min_c = (c - a) + (b - c);
        }
        cout << min_c << endl;
    }

    return 0;
}