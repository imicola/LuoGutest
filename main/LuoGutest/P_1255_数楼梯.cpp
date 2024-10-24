#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

string largeadd(string a,string b)
{
    string x;
    int flag = 0;
    auto ita = a.end() - 1;
    for(auto itb = b.end()-1; itb != b.begin() - 1;itb--){
        int temp = (*itb - '0') + (*ita - '0');
        ita--;
        if (flag == 1)
        {
            temp += 1;
            flag = 0;
        }
        if (temp > 9)
        {
            temp -= 10;
            flag = 1;
        }
        x += to_string(temp);
    }    
    while (ita != a.begin() - 1)
    {
        int temp = *ita - '0';
        ita--;
        if (flag == 1)
        {
            temp += 1;
            flag = 0;
        }
        if (temp > 9)
        {
            temp -= 10;
            flag = 1;
        }
        x += to_string(temp); 
    }
    if (flag == 1)
    {
        x += "1";
    }
    reverse(x.begin(),x.end());
    return x;
}

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    else if (n == 2)
    {
        cout << 2;
        return 0;
    }
    string fib,fibx,fibx1;
    fibx = "1";
    fibx1 = "2";
    for (size_t i = 3; i <= n; i++)
    {
        fib = largeadd(fibx1,fibx);
        fibx = fibx1;
        fibx1 = fib;
    }
    cout << fib;

    return 0;
}