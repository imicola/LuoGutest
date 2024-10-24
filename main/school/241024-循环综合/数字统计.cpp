#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int k,l,r;

int solve(int a)
{
    int p = 0;
    string s = to_string(a);
    for(auto it = s.begin(); it != s.end() ; it++){
        if(*it == '2') p++;
    }
    return p;
}

int main()
{
    cin >> l >> r;
    int sum = 0;
    for (size_t i = l; i <= r; i++)
    {
        sum += solve(i);
    }
    cout << sum;
    return 0;
}