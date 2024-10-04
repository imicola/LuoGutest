#include <bits/stdc++.h>
using namespace std;

int p;
int cp[5];
int dp[5];

void get_data()
{
    cin >> cp[1] >> cp[2] >> cp[3] >> dp[1] >> dp[2] >> dp[3];
}

int main()
{
    cin >> p;
    string s;
    for (size_t i = 0; i < p; i++)
    {
        get_data();
        if (cp[1] > dp[2] || cp[3] > dp[1])
        {
            s += "C";
            
        }
        else if ( dp[1] - cp[3] > cp[2] || dp[3] > cp[1])
        {
            s += "D";
            
        }
        else
        {
            s += "E";
        }
    }
    
    for (auto &&i : s)
    {
        cout << i << endl;
    }
    
    return 0;
}