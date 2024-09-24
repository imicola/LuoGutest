#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<int> arr1(T);
    vector<long long> arr(50);
    arr[0] = 0;
    arr[1] = 1;
    for (size_t i = 2; i <= 50; i++)
    {
        arr[i] = arr[i-1] + arr[i - 2];
    }
    for (size_t i = 0; i < T; i++)
    {
        cin >> arr1[i];
    }
    for (size_t i = 0; i < T; i++)
    {
        int flag = 0;
        for (size_t k = 0; arr[k] <=  arr1[i] ; k++)
        {
            for (size_t j = k; arr[j] <= arr1[i] ; j++)
            {
                if (arr1[i] == arr[k] * arr[j])
                {
                    cout << "TAK";
                    flag++;
                    goto P;
                }
            }
        }
        if (flag == 0)
        {
            cout << "NIE";
        }
        P:
        cout << endl;
    }
    

    

    return 0;
}