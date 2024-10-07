#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    long long n,a,b,c;
    vector<int> arr;
    for (size_t i = 0; i < t; i++)
    {
        cin >> n >> a >> b >>c;
        if ((a > b && a > c))
        {
            arr.push_back((n-a)+min(a-b,a-c));
        }
        else if (a < b && a < c)
        {
            arr.push_back(a-1+min(b-a,c-a));
        }
        else
        {
            arr.push_back(max(abs(b-a),abs(c-a))-(b+c)/2+1);
        }
    }
    for (auto &&i : arr)
    {
        cout << i <<endl;
    }
    
    return 0;
}