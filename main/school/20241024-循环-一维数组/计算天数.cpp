#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool isrun(int i)
{
    if((i%4 == 0 && i%100 !=0) || i%400 == 0) return 1;
    return 0;
}

int main()
{
    int y,m,d;
    cin >> y >> m >> d;
    int a = 0;
    int m0[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(isrun(y)) m0[2]++;
    for (size_t i = 1; i < m ; i++)
    {
        a += m0[i];
    }
    a += d;
    cout << a;
    return 0;
}