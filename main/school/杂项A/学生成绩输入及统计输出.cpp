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

struct stu
{
    string name;
    int a, b, c;
};

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    stu counts[t];
    for (size_t i = 0; i < t; i++) {
        cin >> counts[i].name >> counts[i].a >> counts[i].b >> counts[i].c;
    }
    for (size_t i = 0; i < t; i++) {
        cout << counts[i].name << " " << counts[i].a + counts[i].b + counts[i].c << endl;
    }

    return 0;
}