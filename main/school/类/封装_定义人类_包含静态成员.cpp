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

class People
{
private:
    string name;
    int age, height, weight;

public:
    People(string _name, int _age, int _height, int _weight)
    : name(_name)
    , age(_age)
    , height(_height)
    , weight(_weight)
    {
    }
};

class People_mg
{
private:
    vector<People> P_mg;

public:
    void addPeople(const string &name, int age, double height, double weight)
    {
        People p(name, age, height, weight);
        P_mg.push_back(p);
    }
    int P_num()
    {
        return P_mg.size();
    }
};

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    People_mg P;
    while (1) {
        string name;
        int a, b, c;
        cin >> name;
        if (name == "exit") {
            break;
        }
        cin >> a >> b >> c;
        P.addPeople(name, a, b, c);
    }
    cout << P.P_num();
    return 0;
}