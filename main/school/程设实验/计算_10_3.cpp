#include <stdio.h>
int main()
{
    int a = 10, b = 3;
    double c = 10.0 / 3.0;
    printf("%d\n%.3f\n%.8f\n%e\n", a / b, c, c, c);
}