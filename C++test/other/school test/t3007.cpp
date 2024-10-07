#include <bits/stdc++.h>
using namespace std;

long long pow1(int a ,int b)
{
    long long sum = 1;
    if (b == 0)
    {
        return 1;
    }
    for (size_t i = 0 ; i < b; i++)
    {
        sum *= a;
    }

    return sum;
}

int main()
{
    string s;
    cin >> s; 
    int len = s.size();
    char t[27];
    int k = 1;
    for (size_t i = 65; i <= 90; i++)
    {
        t[k] = (char)i;
        k++;
    }
    k = 0;
    int arr[14];
    for (int i = len - 1 ; i >= 0; i--)
    {
        for (size_t j = 1; j <= 26; j++)
        {
            if (s[i] == t[j])
            {
                arr[k++] = j;
                break;
            }
        }
    }
    long long sum = 0;
    for (size_t i = 0; i < k ; i++)
    {
        sum += arr[i] * pow1(26,i);
    }
    cout << sum<<endl;
    //cout << pow1(3,3);
    return 0;
}