#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {1,2,3,4,5};
    int ans = 0;
    for (size_t i = 0; i < 5; i++) if(*&(i-1)[a + 1]%2 == 0) ans++;
    cout << ans;
    
}