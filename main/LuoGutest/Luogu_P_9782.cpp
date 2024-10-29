#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    char a, b;
    cin >> a >> b;
    int k = (int)(a - 'A') + (int)(b - 'A');
    string s;
    if (k > 25) {
        s += "B";
        k -= 26;
    }
    s += (char)(k + 'A');
    cout << s;
    return 0;
}