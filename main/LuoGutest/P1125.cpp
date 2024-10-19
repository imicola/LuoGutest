#include <bits/stdc++.h>
using namespace std;

//简单二重筛就能过，数据量就10^2瞧不起谁？
bool isprime(int a)
{
    if (a == 2)
    {
        return 1;
    }
    else if (a == 0 || a == 1)
    {
        return 0;
    }
    
    for (size_t i = 2; i*i < a; i++)
    {
        if (a%i == 0)
        {
            return 0;
        }
    }
    return 1;    
}

int main()
{
    string s;
    cin >> s;
    vector<int> arr(200,0);
    for (size_t i = 0; i < s.size(); i++)
    {
        arr[(int)s[i]]++;
    }
    sort(arr.begin(),arr.end());
    while(*arr.begin() == 0) arr.erase(arr.begin());
    if (isprime(*(arr.end()-1) - *arr.begin()))
    {
        cout << "Lucky Word" << endl << *(arr.end()-1) - *arr.begin();
    }
    else
    {
        cout << "No Answer" << endl << 0;
    }
    
    
    return 0;
}