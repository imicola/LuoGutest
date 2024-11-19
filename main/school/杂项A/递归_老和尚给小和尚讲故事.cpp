//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define size_t int
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;

void f(int n)
{
    if (n == 0) return;
    cout << "从前有座山,山上有座庙,庙里有个老和尚,老和尚在给小和尚讲故事:" << endl;
    f(n - 1);
}

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    f(n);
    return 0;
}