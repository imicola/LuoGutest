#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,p = 0;
    cin >> a>>b;
    if (a == 1 && b == 1)
    {
        cout << 1;
        return 0;
    }

    while(b > 0)
    {
        b--;
        a -= 2;
        if (a < 0)
        {
            break;
        }
        p += 3;
    }

    if (a >= 0)
    {
        cout << p+a;
    }
    else if(a + 2 >= 0 && a < 0)
    {
        cout << p + a + 2;
    }
    
    

    return 0;
}