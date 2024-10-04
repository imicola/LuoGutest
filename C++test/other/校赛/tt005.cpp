#include <bits/stdc++.h>
using namespace std;

int lianxu(string a)
{
    int max0 = 1,max1 = 1;
    //cout <<"tt"<< a << endl;
    for (size_t i = 1; i <= a.size(); i++)
    {
        if (a[i] != a[i-1])
        {
            max0 = 1;
        }
        else
        {
            max0++;
            if (max0 > max1)
            {
                max1 = max0;
            }
            
        }
    }
    return max1;
}


int main()
{
    int t;
    cin >> t;
    vector<string> s(10000);
    vector<int> out;
    for (size_t i = 0; i < t; i++)
    {
        int p = 0;
        int mp = 1;
        int maxp[4];
        cin >> p;
        cin >> s[i];
        char x = s[i][0];
        int a1 = 0;
        for (size_t k = 1; k <= 2; k++)
        {
            string temp = s[i];
            for (size_t j = 0; j < p; j++)
            {
                if (temp[j] == '2')
                {
                    if (k == 1)
                    {
                        temp[j] = '0';
                    }
                    else
                    {
                        temp[j] = '1';
                    }
                }
            }
            //cout << temp;
            maxp[k] = lianxu(temp);
        }
        out.push_back(max(maxp[1],maxp[2]));
    }
    for(const auto i : out)
    {
        cout << i <<endl;
    }
}