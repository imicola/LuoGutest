#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p1 = 0;
    int p2 = 0;
    for (size_t i = 0; i < 10; i++) {
        int temp = 0;
        cin >> temp;
        if (temp > 0) {
            p1++;
        } else if (temp < 0) {
            p2++;
        }
    }
    cout << "positive:" << p1 << endl;
    cout << "negative:" << p2;
}