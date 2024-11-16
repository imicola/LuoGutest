//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

bool pand(int a, int b ,int c,int d ,int e ,int f){
    if(a + b > c && d + e > f){
        return 1;
    }
    if(a + c > d && b + e > f){
        return 1;
    }
    if(a + d > e && b + c > f){
        return 1;
    }
    if(a + e > f && b + c > d){
        return 1;
    }
    return 0;
}

int main()
{
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for (size_t i = l; i <= r; i++) {
        string s = to_string(i);
        vector<int> ch(6);
        for (int i = 0; i < 6; i++) {
            ch[i] = s[i]^48;
        }
        sort(ch.begin(), ch.end());
        if (pand(ch[0], ch[1], ch[2], ch[3], ch[4], ch[5])) ans++;
    }
    cout << ans;
    return 0;
}