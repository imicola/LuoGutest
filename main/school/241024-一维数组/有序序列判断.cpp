#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n),arr2(n),arr3(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    arr2 = arr;
    arr3 = arr;
    sort(arr2.begin(),arr2.end());
    sort(arr3.begin(),arr3.end(),greater<int>());
    if (arr == arr2 || arr == arr3)
    {
        cout <<"sorted";
    }
    else
    {
        cout <<"unsorted";
    }
    
    
    return 0;
}