#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a , b ,c ,d;
    cin >> a >> b >> c >> d;
    int sum = a*3600 + b*60 + c +d;
    int h = sum/3600;
    int min = (sum - h*3600)/60;
    int s = (sum - h*3600 - min*60);
    cout << h <<" " << min << " " << s;
    return 0;
}