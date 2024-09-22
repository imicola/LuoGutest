#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,p = 0,maxx = 0;
    cin >> a >> b >> c;
    vector<int> arr(110);
    for (size_t i = 1; i <= a; i++)
    {
        for (size_t k = 1; k <= b; k++)
        {
            for (size_t j = 1; j <= c ; j++)
            {
                arr[i+k+j]++;
            }
        }
    }
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] > maxx)
        {
            maxx = arr[i];
            p = i;
        }
    }
    cout << p;

    return 0;
}


