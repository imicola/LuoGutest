//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;

double f(double n,vector<double> a)
{
    double sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
    }
    if(sum >= n && a.size() >= 5){
        return sum - a[0];
    }
    return sum;
}

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    double k;
    cin >> n >> k;
    vector<double> a(n);
    for (auto &&i : a) {
        cin >> i;
    }
    sort(all(a));
    printf("%.2f", f(k, a));
    return 0;
}