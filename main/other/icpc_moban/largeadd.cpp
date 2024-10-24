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
        if (flag == 1){
            temp += 1;
            flag = 0;
        }
        if (temp > 9){
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
    
    return 0;
}