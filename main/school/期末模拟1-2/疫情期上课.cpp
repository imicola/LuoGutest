//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    map<int, int> class1;
    int k;
    while (cin >> k) class1[k]++;
    cout << class1[1] + class1[2] + class1[3] << endl;
    cout << "Chinese:" << class1[1] << endl;
    cout << "Math:" << class1[2] << endl;
    cout << "English:" << class1[3] << endl;
    return 0;
}