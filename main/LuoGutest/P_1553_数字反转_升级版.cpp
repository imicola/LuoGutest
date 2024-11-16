//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    if (s.find('.') != string::npos) {
        string s1(s.begin(), s.begin() + s.find('.'));
        string s2(s.begin() + s.find('.') + 1, s.end());
        while (*s2.begin() == '0' && s2.size() > 1) s2.erase(s2.begin());
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        while (*s1.begin() == '0' && s1.size() > 1) s1.erase(s1.begin());
        cout << s1 << '.' << s2;
    }
    else if (s.find('/') != string::npos) {
        string s1(s.begin(), s.begin() + s.find('/'));
        string s2(s.begin() + s.find('/') + 1, s.end());
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        while (*s1.begin() == '0' && s1.size() > 1) s1.erase(s1.begin());
        while (*s2.begin() == '0' && s2.size() > 1) s2.erase(s2.begin());
        cout << s1 << '/' << s2;
    }
    else if (s.find('%') != string::npos) {
        s.pop_back();
        reverse(s.begin(), s.end());
        while (*s.begin() == '0' && s.size() > 1) s.erase(s.begin());
        cout << s << '%';
    }
    else {
        reverse(s.begin(), s.end());
        while (*s.begin() == '0' && s.size() > 1) s.erase(s.begin());
        cout << s;
    }
    return 0;
}