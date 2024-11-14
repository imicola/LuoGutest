//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s1, s2, s3, s;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);
    s = s1 + s2 + s3;
    int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0;
    for (auto &&i : s) {
        if (i == ' ')
            ans4++;
        else if (i >= 'a' && i <= 'z')
            ans2++;
        else if (i >= 'A' && i <= 'Z')
            ans1++;
        else if (i >= '0' && i <= '9')
            ans3++;
        else
            ans5++;
    }
    cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << " " << ans5 << " ";
    return 0;
}