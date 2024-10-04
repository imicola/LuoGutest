#include <bits/stdc++.h>
using namespace std;



int main()
{
    long long p = 0;
    long long n ,x;
    vector<int> vis;
    cin >> n >> x;
    for (size_t i = 1; i <= n; i++)
    {
        if (x % i == 0)
        {
            vis.push_back(p);
        }
        
    }
    if ((vis.size()+2)%2 == 0)
    {
        cout << "OFF";
    }
    else
    {
        cout << "ON";
    }
    
    return 0;
    

}