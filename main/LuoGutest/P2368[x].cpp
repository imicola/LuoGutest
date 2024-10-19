#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p = 0;
    cin >> p;
    long long sum = 0;
    string sum1;
    int t = 0;
    for (long long i = pow(10,p); i < pow(10,p+1); i++)
    {
        sum = i*i;
        sum1 = to_string(sum);
        if (sum1.substr(sum1.size()-9) == "987654321")
        {
            t++;
        }
        cout << sum1 << endl;
    }
    cout <<t;

    



    return 0;
}