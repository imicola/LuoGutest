#include <bits/stdc++.h>
using namespace std;

int arr[40][40];

int main()
{
    int N;
    cin >> N;
    arr[1][N/2 + 1] = 1;
    for (size_t K = 2; K <= N*N ; K++)
    {
        for (size_t i = 1; i <= N; i++)
        {
            for (size_t j = 1; j <= N; j++)
            {
                if (arr[i][j] == K-1)
                {
                    if (i == 1 && j != N)
                    {
                        arr[N][j + 1] = K;
                    }
                    else if (i != 1 && j == N)
                    {
                        arr[i - 1][1] = K;
                    }
                    else if (i == 1 && j == N)
                    {
                        arr[i+1][j] = K;
                    }
                    else if(i != 1 && j != N)
                    {
                        if (arr[i-1][j+1] == 0)
                        {
                            arr[i-1][j+1] = K;
                        }
                        else
                        {
                            arr[i+1][j] = K;
                        }
                    }
                }
            }
        }
    }
    
    for (size_t j = 1; j <= N ; j++)
    {
        for (size_t k = 1; k <= N ; k++)
        {
            cout << arr[j][k]<<" ";
        }
        cout << endl;
    }
}
