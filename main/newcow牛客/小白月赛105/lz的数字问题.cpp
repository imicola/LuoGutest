//#pragma GCC optimize(3)
#include <bits/stdc++.h>
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

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int pos1 = s1.find_first_of('.');
    int pos2 = s2.find_first_of('.');
    string s3, s4, s5, s6;
    s3 = (pos1 == -1 ? s1 : s1.substr(0, pos1));
    s4 = (pos1 == -1 ? "000000" : s1.substr(pos1 + 1));
    if (s4.size() < 6) {
        while (s4.size() < 6)
        {
            s4 += '0';
        }
    }
    else {
        s4 = s4.substr(0, 6);
    }
    s5 = (pos2 == -1 ? s2 : s2.substr(0, pos2));
    s6 = (pos2 == -1 ? "000000" : s2.substr(pos2 + 1));
    if (s6.size() < 6) {
        while (s6.size() < 6)
        {
            s6 += '0';
        }
        
    }
    else {
        s6 = s6.substr(0, 6);
    }
    // cout << s3 <<" "<< s4 << " " << s5<<" " << s6;
    if (s3 == s5 && s4 == s6)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}