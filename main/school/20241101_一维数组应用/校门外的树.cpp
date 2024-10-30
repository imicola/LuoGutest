#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l, m, p = 0;
    cin >> l >> m;
    int arr[l + 1];
    for (size_t i = 0; i <= l; i++) {
        arr[i] = 0;
    }
    for (size_t j = 0; j < m; j++) {
        int r, q;
        cin >> r >> q;
        for (size_t t = r; t <= q; t++) {
            arr[t] = 1;
        }
    }
    for (size_t e = 0; e <= l; e++) {
        if (arr[e] == 0) {
            p++;
        }
    }
    cout << p;

    return 0;
}