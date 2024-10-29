#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

inline ll read()
{
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

inline void print(ll x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

signed main()
{
    //ios::sync_with_stdio(0), cin.tie(0);
    ll n,m;
    cin >> n >> m;
    vector<ll> arr(n);
    for (auto &i : arr)
    {
        i = read();
    }
    for (ll p = 0 ; p < m;p++)
    {
        ll k = 0;
        cin >> k;
        if (k == 2)
        {
            ll x, y, sum = 0;
            cin >> x >> y;
            for (ll i = x-1; i <= y-1; i++)
            {
                sum += arr[i];
            }
            print(sum);
        }
        else
        {
            ll x, y, t = 0;
            cin >> x >> y >> t;
            for (ll i = x-1; i <= y-1; i++)
            {
                arr[i] += t;
            }
        }
    }
    return 0;
}