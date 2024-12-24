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

class Boat
{
public:
    Boat(int w)
    {
        weight = w;
    }
    friend int getTotalWeight(Boat &boat, class Car &car);

private:
    int weight;
};

class Car
{
public:
    Car(int w)
    {
        weight = w;
    }
    friend int getTotalWeight(class Boat &boat, Car &car)
    {
        return boat.weight + car.weight;
    };

private:
    int weight;
};

int main()
{
    int n, m;
    cin >> n >> m;
    Boat boat(n);
    Car car(m);
    cout << "船和汽车共重" << getTotalWeight(boat, car) << "吨" << endl;
}