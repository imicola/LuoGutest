//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int strcount(string s, string ch)
{
    size_t it = 0;
    int ans = 0;
    while ((it = s.find(ch, it)) != string::npos) {
        it += ch.size();
        ans++;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    return 0;
}