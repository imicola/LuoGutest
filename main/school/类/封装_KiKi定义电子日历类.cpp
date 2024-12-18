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

class Tdata
{
private:
    int year, month, day;

public:
    int y, m, d;
    Tdata(int y = 0, int m = 0, int d = 0)
    {
        year = y;
        month = m;
        day = d;
    }
    void setdata(int _y, int _m, int _d)
    {
        cin >> _y >> _m >> _d;
        year = _y;
        month = _m;
        day = _d;
    }
    void showdata()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    Tdata d(0, 0, 0);
    d.setdata(0, 0, 0);
    d.showdata();
    return 0;
}