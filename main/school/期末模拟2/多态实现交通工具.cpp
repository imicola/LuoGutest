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

class Veh
{
public:
    virtual void Run() = 0;
    virtual void Stop() = 0;
};

class bike : public Veh
{
    void Run() override
    {
        cout << "自行车在行进!" << endl;
    }
    void Stop() override
    {
        cout << "自行车停了下来!" << endl;
    }
};

class Car : public Veh
{
    void Run() override
    {
        cout << "小汽车在行进!" << endl;
    }
    void Stop() override
    {
        cout << "小汽车停了下来!" << endl;
    }
};

class moto : public Veh
{
    void Run() override
    {
        cout << "摩托车在行进!" << endl;
    }
    void Stop() override
    {
        cout << "摩托车停了下来!" << endl;
    }
};

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    bike b;
    Car c;
    moto m;
    Veh *p = &b;
    p->Run();
    p->Stop();
    p = &c;
    p->Run();
    p->Stop();
    p = &m;
    p->Run();
    p->Stop();
    return 0;
}