#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
    printf("sin:%lf",3.14159);
    return 0;
}