#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,m,sum = 0;
    int minn = 100000;
    cin >> n >> m;
    vector<int> arr(n+1,0);
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (size_t i = 0; i <= n-m; i++)
    {
        for (size_t j = i; j < i+m ; j++)
        {
            sum += arr[j];
        }
        if (sum < minn)
        {
            minn = sum;
        }
        sum = 0;
    }
    cout << minn;
    return 0;
}