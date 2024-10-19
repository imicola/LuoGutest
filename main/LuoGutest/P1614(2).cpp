#include <bits/stdc++.h>
using namespace std;

int arr[3010];
int arr2[3010];

int main()
{
    int n,m,p,sum = 0;
    cin >> n >> m;
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (size_t i = 0; i < n-m; i++)
    {
        for (size_t j = i; j < i+m ; j++)
        {
            sum += arr[j];
        }
        arr2[i] = sum;
        sum = 0;
    }
    for (int i = 0;arr2[i] != 0; i++)
    {
        p++;
    }
    sort(arr2,arr2+p);
    cout << arr2[0];
}
//md,两个RE变全是RE了