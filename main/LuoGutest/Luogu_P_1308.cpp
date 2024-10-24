#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    string s1;
    string s2;
    int flag = 0;
    int out = 0;
    cin >> s1;
    getline(cin,s2); s2 = "\n"; getline(cin,s2);
    //双方均转化为小写
    auto it = s1.begin();
    auto it2 = s2.begin();
    while (it != s1.end()){
        if(*it < 'a') *it = (char)(*it + 'a'-'A');
        it++;
    }
    while (it2 != s2.end()){
        if(*it2 < 'a'&&*it2 != ' ') *it2 = (char)(*it2 + 'a'-'A');
        it2++;
    }
    //.find + ' '判断整词存在；
    if (s2.find(s1) == string::npos)
    {
        cout << -1;
    }
    else
    {
        int ldx = s2.find(s1);
        auto itx = s2.begin()+ldx;
        while(1){
            ldx = s2.find(s1);
            itx = s2.begin()+ldx;
            if (ldx == string::npos) break;
            if((*(itx+s1.size()) != ' '||(*(itx-1) != ' ')&&(ldx != 0))&& ldx != string::npos){
                s2[itx - s2.begin()] = '0';
                continue;
            }
            flag++;
            if (flag == 1)
            {
                out = itx - s2.begin();
            }
            s2[itx - s2.begin()] = '0';
        }
        if (flag == 0)
        {
            cout << -1;
        }
        else
        {
            cout << flag << " " << out;
        }
    }
    
    return 0;
}