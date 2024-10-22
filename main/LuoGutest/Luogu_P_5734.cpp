#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (size_t i = 0; i < n; i++)
    {
        int k = 0;
        cin >> k;
        if (k == 1 )
        {
            string s1;
            cin >> s1;
            s += s1;
            cout << s <<endl;
        }
        else if (k == 2)
        {
            int a,b;
            cin >> a >> b;
            string temp;
            for(auto it = s.begin()+a;it != s.begin()+a+b;it++) temp += *it;
            s = temp;
            cout << s <<endl;
        }
        else if (k == 3)
        {
            int a;
            string s2;
            cin >> a >> s2;
            auto it = s.begin() + a;
            auto it2 = s2.begin();
            auto it3 = s2.end();
            s.insert(it,it2,it3);
            cout << s <<endl;
        }
        else if (k == 4)
        {
            string s0;
            cin >> s0;
            auto ldx = s.find(s0);
            if (ldx != string::npos)
            {
                cout << ldx <<endl;
            }
            else
            {
                cout << -1 <<endl;
            }
        }
    }
    
    return 0;
}