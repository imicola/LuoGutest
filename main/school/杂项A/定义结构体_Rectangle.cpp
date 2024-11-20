//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define size_t int
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int,int> pii;

struct Rectangle
{
    pii point1;
    int he, wi;
};


int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        Rectangle k;
        cin >> k.point1.first >> k.point1.second >> k.wi >> k.he;
        cout << k.point1.first + k.wi << " " << k.point1.second + k.he;
    }
    return 0;
}