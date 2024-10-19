#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    char a = '0',b = '0';
    int t = 0,x = 1;
    int arr[1000010];
    while (cin >> a)
    {
        t++;
        if (a == b)
        {
            arr[x]++;
        }
        else
        {
            x++;
            arr[x]++;
            b = a;
        }
    }
    arr[0] = sqrt(t);
    for (size_t i = 0; i < x+1; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}