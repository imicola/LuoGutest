#include<bits/stdc++.h>
using namespace std;

int ispalindrome(int t)
{
    string x = to_string(t);
    int x_lift = 0;
    int x_right = x.size() - 1;
    for ( ; x_lift < x_right;)
    {
        if (x[x_lift] != x[x_right])
        {
            return 0 ;
        }
        x_lift++;
        x_right--;
    }
    return 1;
}

int isprime(int n)
{
    int p = 1;
    for (int j = 2; j*j <= n; j++)
        {
            if (n%j == 0)
            {
                p = 0;
                break;
            }
        }

        if (p == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
}

int main()
{
    int a,b = 0;
    cin >> a >> b;
        for (int i = a; i <= b; i++)
        {
            if (i == 9989900)
            {
                break;
            }
            else if (ispalindrome(i) == 1 && isprime(i)==1)
            {
                cout << i <<endl;
            }    
        }
    system("pause");
    return(0);
}