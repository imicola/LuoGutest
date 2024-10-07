#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int>(3));
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    int nsum = 0,wsum = 0;
    for (size_t i = 0; i < n ; i++)
    {
        if (arr[i][0] > m)
        {
            arr[i][0] = 114;
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        
    }
    


    return 0;
}