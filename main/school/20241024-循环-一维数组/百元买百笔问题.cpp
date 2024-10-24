#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    double n,flag = 0;
    cin >> n;
    for (size_t i = 1; i <= n / 3; i++)
    {
        for (size_t j = 1; j <= (n - 5 * i) / 2; j++)
        {
            size_t k = n - i - j;
            if (3 * i + 2 * j + (k / 2.0) == n && i + j + k == n)
            {
                cout << i << " " << j << " " << k << endl;
                flag++;
            }
        }
    }
    if (flag == 0)
    {
        cout << "Not found!";
    }
    
    
    return 0;
}
