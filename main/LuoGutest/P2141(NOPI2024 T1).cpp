#include <bits/stdc++.h>
using namespace std;

int arr1[10020];

int main()
{
    int m;
    cin >> m;
    int arr[m] = {0};
    int t = 0;
    for (size_t i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr + m);
    for (size_t i = 2; i < m ; i++)
    {
        for (size_t k = 0; k < i; k++)
        {
            for (size_t j = k+1; j < i; j++)
            {
                if (arr[i] == arr[k] + arr[j])
                {
                    // cout << "tt1:" << arr[i] <<"tt2:"<<arr[k]<<" "<<arr[j]<<endl;
                    arr1[i]++;
                }
            }
        }
    }
    for (size_t i = 0; i < m+1; i++)
    {
        if (arr1[i] != 0)
        {
            t++;
        }
        
    }
    cout << t;

    return 0;
}