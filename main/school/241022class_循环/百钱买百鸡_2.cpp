#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    double n,flag = 0;
    cin >> n;
    for (size_t i = 0; i <= n / 5; i++)
    {
        for (size_t j = 0; j <= (n - 5 * i) / 3; j++)
        {
            size_t k = n - i - j;
            if (5 * i + 3 * j + (k / 3.0) == n && i + j + k == n)
            {
                cout << i << " " << j << " " << k << endl;
                flag++;
            }
        }
    }
    if (flag == 0)
    {
        cout << "No Answer.";
    }
    
    
    return 0;
}
