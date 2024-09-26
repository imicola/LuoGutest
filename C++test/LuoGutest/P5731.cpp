#include <bits/stdc++.h>
using namespace std;

    int arr[12][12];

int main()
{
    int n ;
    cin >> n;
    for (int x = 0,y = 0 ,num = 0; num < n*n;)
    {
        while (x < n && arr[y][x+1] == 0)
        {
            arr[y][x] = ++num;
            x++;
            cout << "tt1 " <<arr[y][x]<<endl;
        }
        x--;
        while (y < n  && arr[y+1][x] == 0)
        {
            arr[y][x] = ++num;
            y++;
            cout << "tt2 " <<arr[y][x]<<endl;
        }
        y--;
        while (x > 0 && arr[y][x - 1] == 0)
        {
            arr[y][x] = ++num;
            x--; 
            cout << "tt3 " <<arr[y][x]<<endl;
        }
        x++;
        while (y > 0 && arr[y - 1][x] == 0)
        {
            arr[y][x] = ++num;
            y--;   
            cout << "tt4 " <<arr[y][x]<<endl;
        }
        y++;
        
    }
    
    
    for (size_t i = 0; i <= n; i++)
    {
        for (size_t k = 0; k <= n; k++)
        {
            cout <<setw(3) << arr[i][k];
        }
        cout <<endl;
    }
    
}