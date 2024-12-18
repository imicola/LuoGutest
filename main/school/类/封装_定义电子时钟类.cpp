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

class Clock
{
private:
    int hour, minute, second;

public:
    Clock(int h = 0, int m = 0, int s = 0)
    {
        hour = h;
        minute = m;
        second = s;
    }
    void settime(int h, int m, int s)
    {
        cin >> h >> m >> s;
        hour = h;
        minute = m;
        second = s;
    }
    void showtime()
    {
        cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second << endl;
    }
};

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    Clock c(0, 0, 0);
    c.settime(0, 0, 0);
    c.showtime();
    return 0;
}