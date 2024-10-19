#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,t = 0;
    cin >> n;
    int arr[n][2];
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    cin >> t;
    int sc = 0;
    for (size_t i = 0; i < n; i++)
    {
        sc += (100/arr[i][0])*arr[i][1];
    }
    if (sc >= t )
    {
        cout << "Already Au.";
    }
    else
    {
        for (size_t i = 0; i < n; i++)
        {
            if (sc + (100/arr[i][0])*(arr[i][0] - arr[i][1]) < t)
            {
                cout << "NaN"<<endl;
            }
            else
            {
                int sc0 = sc;
                int temp = 0;
                while (sc0 < t)
                {
                    temp++;
                    sc0 += (100/arr[i][0]);
                }
                cout << temp <<endl;
            }
        }
    }
    return 0;
}