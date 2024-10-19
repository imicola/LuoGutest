#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    int x = 0;
    cin >> n;
    bool p = 1;
    vector<int> arr(n*n);
    for (; x != n*n; )
    {
        int t;
        cin >> t;
        if (p)
        {
            for (size_t j = 0; j < t; j++)
            {
                arr[x] = 0;
                x++;
            }
            p = !p;
        }
        else
        {
            for (size_t k = 0; k < t; k++)
            {
                arr[x] = 1;
                x++;
            }
            p = !p;
        }
    }
    int a = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout << arr[a++];
        }
        cout << endl;
    }
    return 0;
}