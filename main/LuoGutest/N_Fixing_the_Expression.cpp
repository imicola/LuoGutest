//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef pair<int, int> pii;

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s[1] == '=') {
            if (s[0] == s[2])
                cout << s << endl;
            else {
                s[0] = s[2];
                cout << s << endl;
            }
        }
        else if (s[1] == '>') {
            if (s[0] > s[2])
                cout << s << endl;
            else {
                if (s[0] == s[2])
                    s[1] = '=';
                else
                    s[1] = '<';
                cout << s << endl;
            }
        }
        else {
            if (s[0] < s[2])
                cout << s << endl;
            else {
                if (s[0] == s[2])
                    s[1] = '=';
                else
                    s[1] = '>';
                cout << s << endl;
            }
        }
    }

    return 0;
}