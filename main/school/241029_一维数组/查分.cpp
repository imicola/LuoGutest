#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (auto& i : a)
        cin >> i;
    int k;
    cin >> k;
    cout << a[k - 1];
}