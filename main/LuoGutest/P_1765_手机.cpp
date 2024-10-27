#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    int ans = 0;
    for(auto it = s.begin();it != s.end();it++)
    {
        if(*it == 'a'||*it == 'd'||*it == 'g'||*it == 'j'||*it == 'm'||*it == 'p'||*it == 't'||*it == 'w'||*it == ' ') ans += 1;
        if(*it == 'b'||*it == 'e'||*it == 'h'||*it == 'k'||*it == 'n'||*it == 'q'||*it == 'u'||*it == 'x') ans += 2;
        if(*it == 'c'||*it == 'f'||*it == 'i'||*it == 'l'||*it == 'o'||*it == 'r'||*it == 'v'||*it == 'y') ans += 3;
        if(*it == 's'||*it == 'z') ans += 4;
    }
    cout << ans;
    return 0;
}