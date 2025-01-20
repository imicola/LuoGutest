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
    int n;
    cin >> n;
    vector<int> nums(n);
    int candidate = 0, counts = 0;
    for (auto &&i : nums) {
        cin >> i;
        if (counts == 0) candidate = i;
        if (candidate == i)
            counts++;
        else
            counts--;
    }
    int res = 0;
    for (auto &&i : nums) {
        if (i == candidate) {
            res++;
        }
    }
    cout << (res > nums.size() / 2 ? candidate : -1);
    return 0;
}