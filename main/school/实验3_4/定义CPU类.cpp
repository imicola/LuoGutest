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

class CPU
{
    int rank, frequency;
    double voltnumber;

public:
    CPU(int _r, int _f, double _v): rank(_r), frequency(_f), voltnumber(_v)
    {
        cout << "CPU's constructor is called!" << endl;
    }
    ~CPU()
    {
        cout << "CPU's destructor is called!" << endl;
    }
    void run()
    {
        printf("I am working, my rank is %d, my frequency is %d, my voltnumber is %.1lf.\n", rank, frequency, voltnumber);
    }
    void stop()
    {
        printf("I stopped working!\n");
    }
};

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int a, b;
    double c;
    cin >> a >> b >> c;
    CPU cpu(a, b, c);
    cpu.run();
    cpu.stop();
    return 0;
}