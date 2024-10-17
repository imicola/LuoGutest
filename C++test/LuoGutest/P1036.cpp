#include <bits/stdc++.h>
using namespace std;

int n,k,ans;
vector<int> arr(25);

bool isprime(int a)
{
    if (a == 2)
    {
        return 1;
    }
    for (size_t i = 2; i <= a/i; i++)
    {
        if (a%i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void dfs(int m ,int sum ,int startx )
{
    if (m == k)
    {
        if (isprime(sum))
        {
            ans++;
        }
        return;
    }
    for (size_t i = startx; i < n; i++)
    {
        dfs(m+1,sum + arr[i],i+1);
    }
    return;
}

int main()
{
    cin >> n >> k;
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dfs(0,0,0);
    cout << ans;
    return 0;
}