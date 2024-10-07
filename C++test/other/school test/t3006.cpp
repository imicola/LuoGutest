#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int max1 = 0;
    int sum = 0;
    int p = 0;
    int arr[500050];
    for (size_t i = 0; i < n ; i++)
    {
        if (i < m - 1)
        {
            cin >> arr[i];
            continue;
        }
        cin >> arr[i];
        for (size_t j = p,k = 0; k < m ;k++,j++)
        {
            
            
        }
        if (sum > max1)
        {
            max1 = sum;
        }
        p++;
        sum = 0;
    }
    cout << max1;
    return 0;
}