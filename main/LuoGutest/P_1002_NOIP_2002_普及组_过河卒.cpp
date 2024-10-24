#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;

vector<vector<ll>> arr(25,vector<ll>(25));
vector<vector<ll>> arrx(25,vector<ll>(25));

void tra(ll x , ll y)
{
    arrx[x][y]=1;
    arrx[x-1][y-2]=1;
    arrx[x-2][y-1]=1;
    arrx[x-2][y+1]=1;
    arrx[x-1][y+2]=1;
    arrx[x+1][y-2]=1;
    arrx[x+2][y-1]=1;
    arrx[x+2][y+1]=1;
    arrx[x+1][y+2]=1;
}
int main()
{
    ll ax,bx,cx,dx;
    cin >> ax >> bx >> cx >> dx;
    ax += 2; bx += 2 ; cx += 2 ; dx += 2;
    arr[2][2] = 1;
    tra(cx,dx);
    for (size_t i = 2 ; i <= ax ; i++)
    {
        for (size_t j = 2; j <= bx ; j++)
        {
            if(i == 2&&j == 2) continue;
            if (arrx[i][j] == 0)
            {
                arr[i][j] = arr[i-1][j] + arr[i][j-1];
            }
        }
    }
    cout << arr[ax][bx];
    
    return 0;
}
