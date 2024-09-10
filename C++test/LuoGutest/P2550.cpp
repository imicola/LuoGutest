#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0,p = 0,t = 0;
    cin >> n;
    int arr0[7] = {0};
    int arr_out[8] = {0};
    for (size_t i = 0; i < 7; i++)
    {
        cin >> arr0[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t k = 0; k < 7; k++)
        {
            cin >> p;
            for (size_t j = 0; j < 7; j++)
            {
                if (p == arr0[j])
                {
                    t++;
                }
            }
        }
        arr_out[8-t]++;
        t = 0; 
    }
    
    for (int i = 1; i <= 7; i++)
    {
        cout << arr_out[i]<<" ";
    }
    return 0;
}