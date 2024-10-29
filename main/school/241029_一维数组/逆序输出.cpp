#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    int a[10];
    for (auto& i : a)
        cin >> i;
    for (int i = 9; i >= 0; i--)
        cout << a[i] << " ";
}