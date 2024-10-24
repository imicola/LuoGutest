#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int a;
    cin >> a;
    double sum = 0;
    int n = 1;
    while (sum < a)
    {
        sum += (double)1/(n++);
    }
    cout << --n;    
    return 0;
}