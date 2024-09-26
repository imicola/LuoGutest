#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p,q;
    cout << "要转化的数" <<endl;
    cin >> p ;
    cout << "要转化的进制(<=36)" << endl;
    cin >> q;

    vector<char> out;
    while (p != 0)
    {
        int temp = p%q;
        if (temp >= 10)
        {
            char t = temp + 55; 
            out.push_back(t);
            p /= q;
            continue;
        }
        char k = temp + '0';
        out.push_back(k);
        p /= q;
    }
    for(vector<char>::iterator it = out.end()-1;it != out.begin() - 1;it--) 
    {
        cout << *it;
    }
    return 0;
}