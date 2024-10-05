#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a,b,c;
    cin >> a>>b>>c;
    double x1,x2;
    x1 = (-b+sqrt(b*b-4*a*c))/(2*a);
    x2 = (-b-sqrt(b*b-4*a*c))/(2*a);
    if (x1 == x2)
    {
        printf("x1=x2=%.5lf",x1);
    }
    else if (x1 > x2)
    {
        printf("x1=%.5lf;x2=%.5lf",x2,x1);
    }
    else if (x2 > x1)
    {
        printf("x1=%.5lf;x2=%.5lf",x1,x2);
    }
    else
    {
        printf("No answer!");
    }
    

    return 0;
}