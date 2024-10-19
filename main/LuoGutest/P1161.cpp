#include <bits/stdc++.h>
using namespace std;

int vis[1000000];
//谁家数组开这么大???

int main()
{
    int n;
    cin >> n;
    vector<pair<double , int>> arr(n);
    for (size_t i = 0; i < n; i++)
    {
        double temp1,temp2;
        cin >> temp1 >> temp2;
        arr[i].first = temp1;
        arr[i].second = temp2;
    }
    
    for (size_t i = 0; i < n; i++)
    {
        for (size_t k = 1; k <= arr[i].second; k++)
        {
            int p = floor(arr[i].first * k);
            if (vis[p] == 0)
            {
                vis[p] = 1;
            }
            else
            {
                vis[p] = 0;
            }
        }
    }
    int t = 0;
    for (int i = 0 ; vis[i] == 0 ; i++)
    {
        t++;
    }
    cout << t;
    

}