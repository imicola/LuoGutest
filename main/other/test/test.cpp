#include <bits/stdc++.h>
using namespace std;

bool succeed(string str, int l, int r)
{
    int left = l, right = r;
    while (left <= right) {
        if (str[left++] != str[right--]) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        if (str.size() < 4) {
            cout << "No" << endl;
            continue;
        }
        bool found = 0;
        for (int i = 1; i + 2 < str.size(); i++) {
            if (succeed(str, 0, i) && succeed(str, i + 1, str.size() - 1)) {
                found = 1;
                break;
            }
        }
        cout << (found ? "Yes" : "No") << endl;
    }
}