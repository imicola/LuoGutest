#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p, q;
    cout << "要转化的数" << endl;
    cin >> p;
    cout << "要转化的进制(<=36)" << endl;
    cin >> q;
    vector<char> out(1e7);
    int kp = 0;
    while (p != 0) {
        int temp = p % q;
        if (temp >= 10) {
            char t = temp + 55;
            out[kp] = t;
            kp++;
            p /= q;
            continue;
        }
        char k = temp + '0';
        out[kp] = k;
        kp++;
        p /= q;
    }
    for (size_t i = 0; i < kp; i++) {
        cout << out[i];
    }

    return 0;
}