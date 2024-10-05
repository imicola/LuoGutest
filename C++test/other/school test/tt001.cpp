#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b;
    cin >> a >> b;
    int arr[a];
    for (size_t i = 0; i < a; i++)
    {
        cin >> arr[i];
    }
    // sort(arr,arr+a,greater<int>());
    long long max = 0;
    // if (arr[0] != b)
    // {
    //     max = b;
    // }
    
    for (size_t i = 0; i < a; i++)
    {
        if (i == b-1)
        {
            continue;
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int p = 0;
    for (size_t i = 0; i < a; i++)
    {
        if (i == b-1)
        {
            continue;
        }
        if (arr[i] == max)
        {
            p++;
        }
    }
    cout << p;

    return 0;
}