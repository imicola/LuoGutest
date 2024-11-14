#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, m;
    cin >> i >> m;
    if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
            cout << 31;
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11) {
            cout << 30;
        }
        else {
            cout << 29;
        }
    }
    else {
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
            cout << 31;
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11) {
            cout << 30;
        }
        else {
            cout << 28;
        }
    }

    return 0;
}