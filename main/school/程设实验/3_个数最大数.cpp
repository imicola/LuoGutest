//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

void solve1(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << max(max(a, b), c);
}

void solve2(){
    priority_queue<int> pqe;
    int a, b, c;
    cin >> a >> b >> c;
    pqe.push(a), pqe.push(b), pqe.push(c);
    cout << pqe.top();
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    solve1();
    cout << endl;
    solve2();
    return 0;
}