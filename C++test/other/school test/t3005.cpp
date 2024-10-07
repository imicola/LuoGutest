#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,q,p = 0;
    cin >> n >> m >>q;
    string s;
    cin >> s;
    vector<int> arr;
    int flag = 0;
    int kk= 0;
    for (size_t i = 0; i < q; i++)
    {
        int c;
        char c1;
        cin >> c >> c1;
        s[c - 1] = c1;
        for (size_t j = 0; j < s.size() - 2; j++)
        {
            if (s[j] == 'M'&&s[j+1] == 'H'&&s[j+2] == 'Y')
            {
                p++;
                j += 2;
            }
        }
        if (p > m)
        {
            flag = 1;
            break;
        }
        else
        {
            arr.push_back(p);
            p = 0;
        }
    }
    if(flag == 0)
    {
        for (auto &&i : arr)
        {
            cout << i <<endl;
        }
        
         
    }
    else
    {
        cout << "MHY is bad";
    }
    
    return 0;
}