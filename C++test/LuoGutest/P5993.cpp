#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<long long> arr_in(T);
    vector<long long> arr_f(1000);
    for (size_t i = 0; i < T; i++)
    {
        cin >> arr_in[i];
    }
    //找max
    int max = 0;
    for (size_t i = 0; i < T; i++)
    {
        if (max < arr_in[i])
        {
            max = arr_in[i];
        }
    }
    //cout <<"tt_max=" << max <<endl;
    //构造最大斐波那契数列
    arr_f[0] = 0;
    arr_f[1] = 1;
    for (size_t i = 2; i <= max; i++)
    {
        arr_f[i] = arr_f[i-1] + arr_f[i-2];
    }
    //int np = 1;
    // while (1)
    // {
    //     //cout<<"tt_arrf=" << arr_f[np]<<endl;
    //     if (arr_f[np] == 0)
    //     {
    //         break;
    //     }
    //     np++;
    // }
    //cout << "tt_np= "<<np;
    //找乘积相等
    for (size_t i = 0; i < T; i++)
    {
        int s = 0;
        for (size_t k = 0; arr_f[k] <= arr_in[k]; k++)
        {
            for (size_t j = k ; arr_f[j] <= arr_in[k]; j++)
            {
                if (arr_in[i] == arr_f[k] * arr_f[j])
                {
                    cout <<"TAK";
                    s = 1;
                    goto P;
                }
            }
        }
        if (s == 0)
        {
            cout << "NIE";
        }
        P:
        cout <<endl;
    }

    return 0;
}