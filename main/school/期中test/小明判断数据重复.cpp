#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int a[10];
    for (size_t i = 0; i < 10; i++)
    {
        cin >> a[i];
        for (size_t j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                cout <<"YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}