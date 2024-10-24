#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    char s[26];
    int p = 0;
    for(int i = 0;i < 26;i++) s[i] = (char)('A'+i); 
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout <<s[(j+p)%26];
        }
        cout << endl;
        p++;
    }
    return 0;
}