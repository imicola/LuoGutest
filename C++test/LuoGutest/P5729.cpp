#include <bits/stdc++.h>
using namespace std;

int arrv0[21][21][21] = {0};

int main()
{
    int w,x,h,q,t = 0;
    cin >> w >> x >> h;
    cin >> q;
    int v0 = w*x*h;
    for (size_t i = 0; i < q; i++)
    {
        int tempx1,tempy1,tempz1,tempx2,tempy2,tempz2;
        cin >> tempx1 >> tempy1 >> tempz1 >> tempx2 >> tempy2 >> tempz2;
        for (size_t kx = tempx1; kx <= tempx2; kx++)
        {
            for (size_t ky = tempy1 ; ky <= tempy2; ky++)
            {
                for (size_t kz = tempz1; kz <= tempz2; kz++)
                {
                    arrv0[kx][ky][kz]++;
                }
            }
        }
    }
    for (size_t i1 = 1; i1 <= w ; i1++)
    {
        for (size_t i2 = 1; i2 <= x; i2++)
        {
            for (size_t i3 = 1; i3 <= h; i3++)
            {
                if (arrv0[i1][i2][i3] == 0)
                {
                    t++;
                }
            }
        }
    }
    cout << t;

    return 0;
}