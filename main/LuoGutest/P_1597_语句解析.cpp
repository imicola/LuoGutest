//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s1, s2, s3;
    string abc = "abc";
    char c;
    while (1) {
        cin >> c;
        if (c == '=') break;
    }
    while (1) {
        cin >> c;
        if (c == ';') break;
        s1 += c;
    }
    while (1) {
        cin >> c;
        if (c == '=') break;
    }
    while (1) {
        cin >> c;
        if (c == ';') break;
        s2 += c;
    }
    while (1) {
        cin >> c;
        if (c == '=') break;
    }
    while (1) {
        cin >> c;
        if (c == ';') break;
        s3 += c;
    }
    
    return 0;
}